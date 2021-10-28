#include <stdio.h>

#include <json-c/json_object.h>
#include <json-c/json.h>


/*
 *
 * data/test.json
 */



int main(
int argc,
char * argv[]
){
	printf("hello, world!\n");

	FILE *fp;
	char buffer[1024];

	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *age;
	struct json_object *idk;

	// open file
	fp = fopen("data/test.json", "r");	
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);


	json_object_object_get_ex(parsed_json, "name", &name);

	printf("name is %s\n", json_object_get_string(name));
	// printf("name is %s\n", name);


	return 0;

}
