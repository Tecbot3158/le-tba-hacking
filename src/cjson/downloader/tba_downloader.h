#include <cjson/cJSON.h>
#include <stdio.h>
//header guard
#ifndef TBA_DOWNLOADER_H
#define TBA_DOWNLOADER_H

typedef struct {
	char * endpoint;
	int http_response;	
	cJSON parsed_data;

} TBA_request ;

FILE * perform_get_tba (TBA_request * request) ;

#endif
