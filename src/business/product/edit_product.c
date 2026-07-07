#include "edit_product.h"
#include "../../../include/business/product.h"
#include "../../../src/core/edit_record.h"
int edit_product(const char* filename, product product1,long int position){
	int result=edit_record(filename,&product1,sizeof(product),1,position);
	return result;
}