
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

	json_object *root = json_object_from_file("../data/test.json");

	if(!root)
		return 1;
	printf("The json file is: \n\n%s\n", json_object_to_json_string(root));
	return 0;

}
