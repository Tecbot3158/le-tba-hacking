#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	cJSON * events_mx = cJSON_CreateObject();

	if (events_mx == NULL){
		fprintf(stderr, "error generating events_mx cJSON object");
	}

	cJSON * events = NULL;
	cJSON * city = NULL;

	FILE * file_json = fopen("test2.json", "rb");
	char * buffer = NULL;
	size_t len;
	ssize_t bytes_read = getdelim(&buffer, &len, '\0', file_json);
	if ( bytes_read == -1){
		printf("Error!\n");
		return( -1 );
	}
	// printf("file is...\n%s\t EOF \n", buffer);
	printf("length is %i\n", len);

	cJSON *json_parsed = cJSON_Parse(buffer);

	int array_size = cJSON_GetArraySize(json_parsed);

	printf("Total events: %i\n", array_size);

	// 
	cJSON_ArrayForEach(events, json_parsed){

		cJSON * country	= NULL;
		cJSON * name_event	= NULL;


// 		city = cJSON_GetObjectItemCaseSensitive(events, "city");	
// 		if (cJSON_IsString(city) )
// 			printf("city is %s\n", city->valuestring);

		country = cJSON_GetObjectItemCaseSensitive(events, "country");	
		if (cJSON_IsString(country) ) {
			// printf("country is %s\n", country->valuestring);
			if (strcmp( country -> valuestring, \
					"Mexico") == 0 ) {
				name_event = cJSON_GetObjectItemCaseSensitive(events, "name");	
				printf("Found event in Mexico.\t%s\n", name_event -> valuestring );

			}
		}
	}
	return(0);



}

// "city": "City"
//     name = cJSON_GetObjectItemCaseSensitive(monitor_json, "name");
//
