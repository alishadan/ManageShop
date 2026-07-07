#include <stdio.h>
#include "get_human.h"
#include "../../src/business/search_human.h"
#include "../../include/mylib/myc.h"
#include "../../include/business/human.h"
int get_human(human* human1,const char*filename){
	long position;
	int status=0;
	char code[10];
	printf("please enter a name \n");
	int result=get_name_stdin(human1->name,sizeof(human1->name));
	
	printf("please enter a code \n");
	result = get_name_stdin(human1->code,sizeof(code));
	
	result =search_human_by_code(filename,human1->code,&position,&status);
	if(result== 1){
		printf("the human with this code existed in database \n please enter other code\n");
		return 0;
	}

	printf("please enter a phone \n");
	result = get_name_stdin(human1->telephone,sizeof(human1->telephone));


	return 1;
}