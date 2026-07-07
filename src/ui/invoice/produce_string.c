#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "produce_string.h"
#include "../../../include/business/human.h"
int produce_string(char** strf,human human1){
	//save customer information in a str
	int length=snprintf(NULL,0,
		"______________________________\n"
		"%s | %s \n",
		human1.name,human1.telephone);

	char strc[length+1];
	snprintf(strc,length+1,
		"______________________________\n"
		"%s | %s \n",
		human1.name,human1.telephone);

	int length_p=snprintf(NULL,0,
		"________________________________________\n"
		"product name | sale price | unit | sum \n"
		);
	char strp[length_p+1];

	snprintf(strp,length_p+1,
		"________________________________________\n"
		"product name | sale price | unit | sum \n"
		);
	size_t allocated_size=sizeof(char)*(length+length_p+2);
	char* str=malloc(allocated_size);

	snprintf(str, allocated_size, "%s %s", strc, strp);
	*strf=str;

}

