#include <stdio.h>
#include "confirm_invoice.h"
#include "../../../include/business/product.h"
#include "../../../src/business/product/search_product.h"
#include "../../../src/business/product/edit_product.h"
int confirm_invoice(product* products,int * units,int np){
	printf("saving data: ...\n");
	const char* filename="data/product.bin";
	int count=0;
	int status; long int position; int result;

	while(count<np){
		result=search_product_by_code(filename,products[count].code,&position, &status);
		if (result==2) {
			printf("the code not exist \n"); return 0;
		}
		products[count].quantity-=units[count];
		if(edit_product(filename,products[count],position)==1){
			printf ("record %i saved succesfully \n",count);
			count++;
			continue;
			}
		else {
			printf("error in edit_product function \n"); 
			return 0;
		}
		
	}

	printf("all data saved \n");
	return 1;
}