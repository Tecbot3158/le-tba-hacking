#include <cjson/cJSON.h>
#include <stdio.h>
//header guard
#ifndef TBA_DOWNLOADER_H
#define TBA_DOWNLOADER_H

typedef struct {
	char * endpoint;
	int http_response;	
	cJSON parsed_data;
	FILE * body_file;

} TBA_request ;

FILE * perform_get_tba (TBA_request * request) ;
cJSON * TBA_parse_json ( TBA_request * request );
int TBA_perform_request( TBA_request * request ) ;

#endif
