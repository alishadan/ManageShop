#include <stdio.h>
#include "get_customer_invoice.h"
#include "../../../src/ui/search_human_ui.h"
#include "../../../include/mylib/myc.h"
#include "../../../include/business/human.h"
#include "../../../src/business/search_human.h"
#include "../../../src/business/read_human.h"
int get_customer_invoice(human* human1){
	char* filename="data/customer.bin";
	char* name="customer";
	printf("name of customer: \n");
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
			if(read_human(filename,human1,&status,position)==1) return 1;
			else { 
			 printf("error in read_human function \n");
			 return 0;}
		}
	}

}
