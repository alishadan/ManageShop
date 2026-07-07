#pragma once
#include "../../../include/business/product.h"
int search_product_by_code(const char* filename,const char* code,long int* position, int* status);
int search_product_by_name(product *product1,const char* name,const char* filename,int *status,long int *position);