#include "edit_product_ui.h"
#include <stdio.h>
#include "../../../src/business/product/edit_product.h"
#include "../../../include/business/product.h"
#include "../../../src/ui/product/search_product_ui.h"
#include "../../../src/business/product/search_product.h"
#include "../../../include/mylib/myc.h"
#include "../../../src/ui/product/get_product.h"
int edit_product_ui(const char* filename,const char* name){
	printf("edit a %s \n",name);
	//get name from user
	int result=search_product_ui(filename);
	

	if(result==1){
		printf("\n please enter code of %s \n",name);
		char code[10];
		result=get_name_stdin(code, sizeof(code));
		int status; long int position;
		product product1;
		result=search_product_by_code(filename,code,&position, &status);
		if (result==2) {
			printf("the code not exist \n"); return 0;
		}
		if (result==1){
			if(get_product(&product1,filename)==1){
				if(edit_product(filename,product1,position)==1){
					printf ("data saved successfully \n");
					return 1;
				}
				else printf("error in edit_product function \n");
			}
		}
	}
	return 0;
}
