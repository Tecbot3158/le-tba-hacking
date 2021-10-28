#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}

int main (int argn, char * argv[]){

	const char * authKey = getenv("TBA_AUTH_KEY");

	if ( !authKey ){
		printf("TBA env var auth key is null\n");
		return 1;
	}


//	printf("%s\n", authKey);

	curl_global_init(CURL_GLOBAL_ALL);

	CURL *curl_handle;

	return 0;

}
