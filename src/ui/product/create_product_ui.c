#include "create_product_ui.h"
#include <stdio.h>
#include "../../../include/business/product.h"
#include "../../../src/ui/product/get_product.h"
#include "../../../src/business/product/create_product.h"
int create_product_ui(const char* filename,const char* name) {
	printf("create a %s \n",name);
	product product1;
	int status=0;
	int result=get_product(&product1,filename);
		if (result == 1) {
			create_product(filename,product1, &status);
			printf("the %s is saved\n",name);
			return 1;
		}
		if (result == 0) {
			printf("error in get_product \n");
			return 0;
		}
	
	
}
