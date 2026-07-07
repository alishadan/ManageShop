#include <stdio.h>
#include "../../../include/business/product.h"
#include "../../../include/core.h"
#include "create_product.h"
#include <string.h>
int create_product(const char* filename,product product1, int* status) {
	long position;
	product product2;
	//asign id
	int result= read_last_record(filename, &product2, sizeof(product), 1, status) + 1;
	//asign name
	product1.id=product2.id;
	//save record on file
	if (save_record(filename, &product1, sizeof(product), 1) == 0) {
		*status = 4;
		return 0;
	}
	return 1;
}