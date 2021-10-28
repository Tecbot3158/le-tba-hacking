#include<stdio.h>
#include<json-c/json.h>

int main(int argc, char **argv) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *age;
	struct json_object *friends;
	struct json_object *friend;
	struct json_object *teams;
	size_t n_teams;
	size_t n_friends;

	size_t i;	

	fp = fopen("test.json","r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "name", &name);
	json_object_object_get_ex(parsed_json, "age", &age);
	json_object_object_get_ex(parsed_json, ".", &friends);

	//n_friends = json_object_array_length(friends);
	// 	n_teams = json_object_object_length(parsed_json);
	// json_type type = json_object_get_type(friends);


	int a = json_object_object_length(friends);
	printf("length is a %i\n", a );

	// printf("type is %i\n", type);

	// printf("is null %i\n", json_type_null);
	// printf("is bool %i\n", json_type_boolean);
	// printf("is double %i\n", json_type_double);
	// printf("is int %i\n", json_type_int);
	// printf("is object %i\n", json_type_object);
	// printf("is array %i\n", json_type_array);
	// printf("is string %i\n", json_type_string);

	// printf("%i\n", json_type);

	//printf("Found %i FRC teams!\n", n_teams);

	//for(i=0;i<n_friends;i++) {
	//	friend = json_object_array_get_idx(friends, i);
	//	printf("%lu. %s\n",i+1,json_object_get_string(friend));
	//}	
}
