#include "create_human_ui.h"
#include <stdio.h>
#include "../../include/business/human.h"
#include "../../src/ui/get_human.h"
#include "../../src/business/create_human.h"
int create_human_ui(const char* filename,const char* name) {
	printf("create a %s \n",name);
	human human1;
	int status=0;
	int result=get_human(&human1,filename);
		if (result == 1) {
			create_human(filename,human1, &status);
			printf("the %s is saved\n",name);
			return 1;
		}
		if (result == 0) {
			printf("error in get_human \n");
			return 0;
		}
	
	
}