#include <stdio.h>
#include <string.h>
#include "search_human_ui.h"
#include "../../include/business/human.h"
#include "../../include/mylib/myc.h"
#include "../../src/business/search_human.h"
int search_human_ui(const char* filename){
	//get name of human
	printf("please enter name: \n");
	char name[20];
	int result=get_name_stdin(name, sizeof(name));
	human human1;
	long int position=0;
	int status=0;
	int count=0;
	while(search_human_by_name(&human1,name,filename,&status,&position)==1){
		count++;
		printf("%s | %s | %s \n",human1.name , human1.code, human1.telephone);
	}
	if (count==0){
		printf("there is not human with the name\n");
		return 0; //error
	}
	return 1;
}