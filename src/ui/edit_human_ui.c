#include "edit_human_ui.h"
#include <stdio.h>
#include "../../src/business/edit_human.h"
#include "../../include/business/human.h"
#include "../../src/ui/search_human_ui.h"
#include "../../src/business/search_human.h"
#include "../../include/mylib/myc.h"
#include "../../src/ui/get_human.h"
int edit_human_ui(const char* filename,const char* name){
	printf("edit a %s \n",name);
	//get name from user
	human human1;
	int result=search_human_ui(filename);
	if(result==1){
		printf("\n please enter code of %s \n",name);
		char code[10];
		result=get_name_stdin(code, sizeof(code));
		int status; long int position;
		result=search_human_by_code(filename,code,&position, &status);
		if (result==2) {
			printf("the code not exist \n"); return 0;
		}
		if (result==1){
			if(get_human(&human1,filename)==1){
				if(edit_human(filename,human1,position)==1){
					printf ("data saved successfully \n");
					return 1;
				}
				else printf("error in edit_human function \n");
			}
		}
	}
	return 0;
}