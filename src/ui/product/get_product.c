#include <stdio.h>
#include "get_product.h"
#include "../../../src/business/product/search_product.h"
#include "../../../include/mylib/myc.h"
#include "../../../include/business/product.h"
#include <stdlib.h>
int get_product(product* product1,const char*filename){
	long position;
	int status=0;
	char code[10];
	printf("please enter a name \n");
	int result=get_name_stdin(product1->name,sizeof(product1->name));
	
	printf("please enter a code \n");
	result = get_name_stdin(product1->code,sizeof(code));
	
	result =search_product_by_code(filename,product1->code,&position,&status);
	if(result== 1){
		printf("the product with this code existed in database \n please enter other code\n");
		return 0;
	}

	printf("please purchase price of product \n");
	char buffer[6];
	result = get_name_stdin(buffer,sizeof(buffer));
	product1->purchase_price=atoi(buffer);

	printf("please sale price of product \n");
	result = get_name_stdin(buffer,sizeof(buffer));
	product1->sale_price=atoi(buffer);

	printf("please quantity of product \n");
	result = get_name_stdin(buffer,sizeof(buffer));
	product1->quantity=atoi(buffer);	

	return 1;
}
