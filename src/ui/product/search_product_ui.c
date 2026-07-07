#include <stdio.h>
#include <string.h>
#include "search_product_ui.h"
#include "../../../include/business/product.h"
#include "../../../include/mylib/myc.h"
#include "../../../src/business/product/search_product.h"
int search_product_ui(const char* filename){
	//get name of product
	printf("please enter name: \n");
	char name[20];
	int result=get_name_stdin(name, sizeof(name));
	product product1;
	long int position=0;
	int status=0;
	int count=0;
	while(search_product_by_name(&product1,name,filename,&status,&position)==1){
		count++;
		printf(
			"%s | %s | %i | %i | %i \n"
			,product1.name , product1.code, product1.quantity, product1.purchase_price ,product1.sale_price
			);
	}
	if (count==0){
		printf("ther is not product with the name\n");
		return 0; //error
	}
	return 1;
}
