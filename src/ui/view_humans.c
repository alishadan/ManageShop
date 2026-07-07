#include "view_humans.h"
#include <stdio.h>
#include "../../include/business/human.h"
#include "../../src/business/read_human.h"
int view_humans(const char* filename,const char* name) {
	human human1;
	int status=0;
	int result;
	long int count=0;

	while(status!=3){
		result=read_human(filename, &human1,&status,count);
		if (status==2){
			printf("there is not %s file \n",name);
			return 0;
		}
		if (status==3){
			break;
		}
		count++;
		printf(
			"%s | %s | %s \n"
			,human1.name , human1.code, human1.telephone
			);
		
	}
	if (result==0){
		if (status==1){
			printf("error parametrs of read_record function"); return 0;
		}
		if (status==2){
			printf("error in openning filename"); return 0;
		}
	}

	return 1;
}