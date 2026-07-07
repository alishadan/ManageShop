#include <stdio.h>
#include "search_product.h"
#include "../../../include/business/product.h"
#include <string.h>
int search_product_by_code(const char* filename,const char* code,long int* position, int* status) {
	product product1;
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		*status = 1;
		return 0; //error
	}


	while (fread(&product1, sizeof(product), 1, file) == 1) {
		if (strcmp(product1.code, code) == 0){ 
			*position = ftell(file)-sizeof(product);
			fclose(file);
			return 1;  //the code exist
		}
	}
	fclose(file);
	return 2; //the code not exist

}

int search_product_by_name(product *product1,const char* name,const char* filename,int *status,long int *position){
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		*status = 1;
		return 0; //error
	}
	if (fseek(file,*position,SEEK_SET)!=0){
		perror("fseek failed");
		*status=2;
		return 0;
	}

	while (fread(product1, sizeof(product), 1, file) == 1){
		if (strcmp(product1->name, name) == 0) {
			*status = 0;
			*position=ftell(file);
			if (*position==-1){
				perror("ftell error");
				*status=2;
				return 0; //error
			}
			fclose (file);
			return 1;  //the code exist
		}

	}
	*status = 0;
	fclose(file);
	return 2; //the code not exist

}