#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>

#include "downloader/tba_downloader.h"

int main(){

	// this object is not used any more
	// cJSON * events_array = NULL;
	cJSON * events_mx = cJSON_CreateObject();
	// cJSON_AddArrayToObject();
	// 

	if (events_mx == NULL){
		fprintf(stderr, "error generating events_mx cJSON empty object");
	}
	cJSON * events_mx_events = cJSON_AddArrayToObject( events_mx, "events");

	cJSON * events = NULL;
	cJSON * city = NULL;

	TBA_request frc_events_2019 = {
		.endpoint = "events/2019",
	} ;


	int file_json_size = TBA_perform_request( &frc_events_2019 );

	if (frc_events_2019.http_response != 200){
		fprintf(stderr, "Error. http response is %i\n", frc_events_2019.http_response  );
	}


	// printf("file size is %i\n", file_json_size);
	cJSON * json_parsed = TBA_parse_json( & frc_events_2019 );
	// cJSON *json_parsed = cJSON_Parse(frc_events_2019->body_file);

	int array_size = cJSON_GetArraySize(json_parsed);

	// printf("Total events: %i\n", array_size);

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
			//
			// if an event from "Mexico" is found, add the whole event to the new array
			if (strcmp( country -> valuestring, \
					"Mexico") == 0 ) {
				name_event = cJSON_GetObjectItemCaseSensitive(events, "name");	
				// printf("Found event in Mexico.\t%s\n", name_event -> valuestring );
				//     resolutions = cJSON_AddArrayToObject(monitor, "resolutions");
				// even
				// object cJSON= events_mx 
				// cJSON_AddItemToArray(events_array, events)
				// cJSON_AddObjectToObject(events_array, events);
				//cJSON_AddObjectToObject(events_mx_events, events);
				//
				//
				int arr_size = cJSON_GetArraySize(events_mx_events);
				 //printf("Items; %d \n", arr_size);

				//cJSON_InsertItemInArray(events_mx_events, arr_size+1 , events);
				// cJSON_AddItemToArray(events_mx_events, events);
				// if AddItemToArray is used, the  ArrayForEach stops working...
				cJSON_AddItemReferenceToArray(events_mx_events, events);
				// consider using: 
				// cJSON_AddItemReferenceToObject( ) ;


					

			
			}
		}
	}

	cJSON * events_mx_array = cJSON_GetObjectItemCaseSensitive( events_mx, "events");

	char * toprint = cJSON_Print(events_mx_array);
	// printf("\n%s", toprint);

	cJSON * single_event_mx = NULL;
	cJSON_ArrayForEach( single_event_mx, events_mx_array) {
		cJSON * event_all_matches = NULL;

		//strcat... man 3 
		cJSON * event_obj = cJSON_GetObjectItem( single_event_mx, "key");
		if ( ! cJSON_IsString( event_obj )  )
			fprintf(stderr, "Error parsing key value into string ");

		TBA_request all_matches = {	.endpoint = malloc(500),  } ;

		memset(all_matches.endpoint, 0, 500);

		strncat( all_matches.endpoint, "event/" , 20 );

		strncat( all_matches.endpoint, event_obj -> valuestring , 20 ) ;

		strncat( all_matches.endpoint, "/matches" , 20 );

		// printf("URL:%s\n", all_matches.endpoint );

		int file_size = TBA_perform_request( &all_matches );
		event_all_matches = TBA_parse_json( & all_matches );

		// printf("size is %i\n", cJSON_GetArraySize( event_all_matches ) );
		// printf("http response is %i\n", all_matches.http_response );

		// printf("-----------------\n%s\n", cJSON_Print(event_all_matches) );
		//
		//
		cJSON * event_matches = cJSON_AddArrayToObject(events_mx  , event_obj->valuestring);
		// event_obj->valuestring 

		cJSON_AddItemReferenceToArray(event_matches, event_all_matches);
		cJSON_AddItemReferenceToArray(events_mx, event_matches);

	}

	// cJSON_AddI
//	cJSON * events_mx_events = cJSON_AddArrayToObject( events_mx, "events");
	char * stringed = cJSON_Print(events_mx);
	printf("%s", cJSON_Print(events_mx) );

	return(0);


	// fclose(file_json);

}

// "city": "City"
//     name = cJSON_GetObjectItemCaseSensitive(monitor_json, "name");
//
