#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
#include <time.h>

const char * tba_base_url = "https://www.thebluealliance.com/api/v3";
const char * tba_base_header = "X-TBA-Auth-Key:";

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

int main(){


	CURL *tba_url_handle;

	curl_global_init(CURL_GLOBAL_ALL);

	tba_url_handle = curl_easy_init();



	char ** bufloc = NULL;
	size_t data_size = 0;
	FILE * data_file = open_memstream(bufloc, & data_size );
	size_t header_size = 0;
	FILE * header_file = open_memstream(bufloc, & header_size );


	char * tba_key = getenv("TBA_AUTH_KEY");
	char header_auth[300];
	sprintf(header_auth, "%s %s", tba_base_header, tba_key);



	//printf("Header is %s\n", header_auth);


	struct curl_slist * headers_list=NULL;
	headers_list=curl_slist_append( headers_list, header_auth);


	if(headers_list == NULL){
		printf("error!\n");
		return -1;
	}

	char target_url_c[150];
	char * target_url = target_url_c;
	sprintf(target_url, "%s/%s", tba_base_url, "status");

	//printf("Target url is %s\n", target_url);


	curl_easy_setopt( tba_url_handle, CURLOPT_URL, target_url);
	curl_easy_setopt( tba_url_handle, CURLOPT_HTTPHEADER, headers_list);

	curl_easy_setopt( tba_url_handle, CURLOPT_WRITEFUNCTION, write_data);

	curl_easy_setopt( tba_url_handle, CURLOPT_HEADERDATA, header_file);
	curl_easy_setopt( tba_url_handle, CURLOPT_WRITEDATA, data_file);


	curl_easy_perform( tba_url_handle );

	char s[1000];

	while ( fgets(s, sizeof s, data_file) != NULL ){
		printf("%s", s);
	}

		exit(0);


//	fclose(	data_file);
//	fclose( header_file);



	// printf("Key is\n%s\n", tba_key);



}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}
