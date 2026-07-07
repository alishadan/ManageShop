#include <stdio.h>
#include <stdlib.h>
#include "src/ui/human_unit.h"
#include "src/ui/product/product_unit.h"
#include "src/ui/invoice/invoice_unit.h"
#include "src/ui/about.h"
#include "include/mylib/myc.h"
#include "src/ui/main_menu.h"

int main(){
	main_menu();
	char n;
	char response[6];
	int result;
	do{
		
		printf("please enter a character \n");
		result = get_name_stdin(response,sizeof(response));
		if (response[0] =='C'){

			char* filename="data/customer.bin";
			char* name="customer";
			clear_screen();
			human_unit(filename,name);
			main_menu();

		}
		if (response[0] =='S'){
			char* filename="data/supplier.bin";
			char* name="supplier";
			clear_screen();
			human_unit(filename,name);
			main_menu();
		}
		if (response[0] =='P'){
			char* filename="data/product.bin";
			char* name="product";
			clear_screen();
			product_unit(filename,name);
			main_menu();
		}
		if (response[0] =='I'){
			clear_screen();
			invoice_unit();
			main_menu();
		}

		if (response[0] =='A'){;
			clear_screen();
			about();
			main_menu();
		}
		if (response[0] =='E'){
			exit(1);
		}
	}
	while((response[0] != 'C') | (response[0] != 'S') | (response[0] != 'P') | (response[0] != 'I') | (response[0] != 'A') | (response[0] != 'E'));

	return 1;
}
