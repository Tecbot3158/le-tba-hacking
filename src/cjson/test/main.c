#include <cjson/cJSON.h>
#include <stdio.h>


char *create_json(void) 
{

	const unsigned int numbers [3][1] = {
		5,
		9,
		1111
	} ;

	char *string = NULL;
	cJSON *events = NULL;
	size_t index = 0;

	cJSON * event = cJSON_CreateObject();

	if ( cJSON_AddStringToObject(event, "name", "jj") == NULL ){
		printf("error!\n");

	}

	events = cJSON_AddArrayToObject(event, "keys");
	if (events == NULL)
	{
		printf("error ! \n");
	}

	for ( int i = 0 ; i < 3; i++){
		cJSON * event = cJSON_CreateObject();

		cJSON_AddItemToArray(events, event);		

	}

	char * all = cJSON_Print(event);

	if (all == NULL)
		printf("Error!\n");

	printf("string is \n%s\n", all);


}


int main (){

	create_json();
return 0;	
}
