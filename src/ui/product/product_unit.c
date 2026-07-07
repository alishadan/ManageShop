#include "product_unit.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../../src/ui/draw_submenu.h"
#include "../../../include/mylib/myc.h"
#include "../../../src/ui/product/view_products.h"
#include "../../../src/ui/product/search_product_ui.h"
#include "../../../src/ui/product/edit_product_ui.h"
#include "../../../src/ui/product/create_product_ui.h"
int product_unit(const char* filename, const char* name){
	draw_submenu(name);
	char response[6];
	int result;
	do{
		printf("please enter a character \n");
		result = get_name_stdin(response,sizeof(response));
		if (response[0]=='V'){
			clear_screen();
			printf("\n all of %s is \n ",name);
			view_products(filename,name);
			printf("\n");
			draw_submenu(name);
		}
		if (response[0]=='S'){
			clear_screen();
			printf("\n");
			search_product_ui(filename);
			draw_submenu(name);
		}
		if (response[0]=='D'){
			clear_screen();
			printf("\n");
			edit_product_ui(filename,name);
			draw_submenu(name);
			//Edit_customer
		}
		if (response[0]=='A'){
			clear_screen();
			printf("\n");
			create_product_ui(filename,name);
			draw_submenu(name);
		}

		if (response[0]=='B'){
			clear_screen();
			return 1;
		}
		if (response[0]=='E'){
			exit(1);
		}
	}
	while((response[0] != 'V') | (response[0] != 'S') | (response[0] != 'A') | (response[0] != 'E') | (response[0] != 'B') | (response[0] != 'D'));

	return 1;
}
