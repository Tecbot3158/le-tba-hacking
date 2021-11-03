#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tba_downloader.h"

const char * tba_base_url = "https://www.thebluealliance.com/api/v3";
const char * tba_base_header = "X-TBA-Auth-Key:";

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

int main(){

	TBA_request test = {
		.endpoint = "status",
	} ;

	FILE * myfile = perform_get_tba( & test );

	char line[100];	

	while ( fgets( line, sizeof line, myfile) != NULL ) {
		printf("%s", line);
	}


}


FILE * perform_get_tba (TBA_request * request) {


	CURL *url_handle;

	curl_global_init(CURL_GLOBAL_ALL);
	url_handle = curl_easy_init();



	char ** bufloc = NULL;
	size_t data_size = 0;
	FILE * data_file = open_memstream(bufloc, & data_size );
	size_t header_size = 0;
	FILE * header_file = open_memstream(bufloc, & header_size );

	char * tba_key = getenv("TBA_AUTH_KEY");
	char header_auth[300];
	sprintf(header_auth, "%s %s", tba_base_header, tba_key);

	struct curl_slist * headers_list=NULL;
	headers_list=curl_slist_append( headers_list, header_auth);

	if(headers_list == NULL){
		fprintf(stderr, "Error! headers_list not initiallized correctly!\n");
		return NULL;
	}

	char target_url[300];

	// if first character is a slash,
	// skip it...
	// or else the api will deny it 
	if(request->endpoint[0] == '/')
		request->endpoint++;

	sprintf(target_url, "%s/%s", tba_base_url, request->endpoint);

	//printf("Target url is %s\n", target_url);

	curl_easy_setopt( url_handle, CURLOPT_URL, target_url);
	curl_easy_setopt( url_handle, CURLOPT_HTTPHEADER, headers_list);

	curl_easy_setopt( url_handle, CURLOPT_WRITEFUNCTION, write_data);

	curl_easy_setopt( url_handle, CURLOPT_HEADERDATA, header_file);
	curl_easy_setopt( url_handle, CURLOPT_WRITEDATA, data_file);

	curl_easy_perform( url_handle );

	char s[100];

	// while ( fgets(s, sizeof s, header_file) != NULL ){
	//  	printf("%s", s);
	// }

	char response[100];

	fscanf(header_file, "HTTP/2 %s", response);
	//fgets(response, sizeof response, header_file);
	//
	printf("response is... %s\n", response);
	request->http_response = atoi(response);

 	curl_easy_cleanup( url_handle );

	//free(header_file);
	//fclose(	data_file);
	//fclose( header_file);
	
	free(header_file);




	return data_file ;

	// return NULL;
}


/*
 * The following function is part of the CURL Project examples, see 
 * below for the license, 
 *
 * COPYRIGHT AND PERMISSION NOTICE

Copyright (c) 1996 - 2021, Daniel Stenberg, daniel@haxx.se, and many
contributors, see the THANKS file.

All rights reserved.

Permission to use, copy, modify, and distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN
NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of a copyright holder shall not be
used in advertising or otherwise to promote the sale, use or other dealings in
this Software without prior written authorization of the copyright holder.
 */
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}
