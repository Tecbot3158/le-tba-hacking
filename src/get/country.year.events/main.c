#include <stdio.h>
#include <json-c/json.h>

#define TBA_KEY "TBA_AUTH_KEY"

//method declarations
void usage();

int main( int argn, char * argv[])

{

	printf("Hello, worlD!\n");

	if (argn < 2){
		printf("at least 1 argument is required\n");
		usage();
		exit(1);
	}

	int test = atoi(argv[1]);

	printf("int is %d\n", test);


}


void usage(){

	printf("usage:\n");
	printf("\ttba-get-all-events year...\n");

}
