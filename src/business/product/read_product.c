#include "read_product.h"
#include <stdio.h>
#include "../../../src/core/read_record.h"
#include "../../../include/business/product.h"
int read_product(const char* filename, product* product1, int* status, long int count)
 {
	int result=read_record(filename, product1, sizeof(product), status, count);
	return result;
}