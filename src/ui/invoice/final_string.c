#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "final_string.h"
#include <stddef.h>
#include "../../../include/mylib/myc.h"
#include "../../../include/business/product.h"


int final_string(char**strc,const char* product1,int unit,int price,int total){
	 clear_screen();

	 //save customer information in a str
	  	int length=snprintf(NULL,0,
	  	"\n"
	  	"%s | %i | %i | %i \n"
	  	"______________________________\n"
	  	,
	  	product1,unit,price,price*unit);
	  	char str[length+1];
	  snprintf(str,length+1,
	  	"\n"
	  	"%s | %i | %i | %i \n"
	  	"______________________________\n"
	  	,
	  	product1,unit,price,price*unit);

	 size_t allocated_size=sizeof(char)*(length+1+strlen(*strc));
	 char* str1=malloc(allocated_size);

	 snprintf(str1, allocated_size, "%s %s", *strc, str);
	 printf("MANAGE SHOP | INVOICE \n");
	 printf("%s \n",str1);
	 printf("total: %d \n \n",total);
	 *strc=str1;
	return 1;

}
