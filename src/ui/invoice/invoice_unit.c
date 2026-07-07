#include "invoice_unit.h"
#include <stdio.h>
#include <stdlib.h>
#include "invoice_unit.h"
#include "../../../include/business/human.h"
#include "../../../include/business/product.h"
#include "../../../src/ui/invoice/get_customer_invoice.h"
#include "../../../src/ui/invoice/produce_string.h"
#include "../../../src/ui/invoice/get_product_invoice.h"
#include "../../../src/ui/invoice/final_string.h"
#include "../../../src/ui/invoice/confirm_invoice.h"
#include "../../../include/mylib/myc.h"
int invoice_unit(void){
	printf("MANAGE SHOP - SALE INVOICE \n");
	int np=15; 
	int count=0;
	human human1;
	char n;
	if (get_customer_invoice(&human1)==0) return 0;

	//show data customers
	char* strc;
	produce_string(&strc,human1);
	product products[np];
	int quantity[np], prices[np];

	printf("%s \n",strc);
	char response[6];
	int total=0;

	while (count<=np){
		printf("do you want enter a product?y/n \n");
		int result = get_name_stdin(response,sizeof(response));
		if (response[0] == 'n' || response[0] == 'N') break;
		int result1=get_product_invoice(&products[count], &quantity[count], &prices[count]);
		total+=(quantity[count]*prices[count]);
		if (result1==0){
			printf("error in entering data of product \n please enter right \n");
			continue;
		}
		if (result1==1){
			result=final_string(&strc,products[count].name,quantity[count],prices[count],total);
			count++;
			
		}

		
	}
	free(strc);

	printf("do you want confirm the invoice?y/n \n");
	int result = get_name_stdin(response,sizeof(response));
	if (response[0] == 'y' || response[0] == 'Y'){
		if(confirm_invoice(products,quantity,count)==0){
			printf("error in confirm_invoice function \n");
			return 0;
		}

	}

return 1;

}