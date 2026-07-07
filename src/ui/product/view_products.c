#include "view_products.h"
#include <stdio.h>
#include "../../../include/business/product.h"
#include "../../../src/business/product/read_product.h"
int view_products(const char* filename,const char* name) {
	product product1;
	int status=0;
	int result;
	long int count=0;

	while(status!=3){
		result=read_product(filename, &product1,&status,count);
		if (status==2){
			printf("there is not %s file \n",name);
			return 0;
		}
		if (status==3){
			break;
		}
		count++;
		printf(
			"%s | %s | %i | %i | %i \n"
			,product1.name , product1.code, product1.quantity, product1.purchase_price ,product1.sale_price
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
