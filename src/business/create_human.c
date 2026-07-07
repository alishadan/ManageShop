//src/bussiness/create_human
//#include "create_human.h"
#include <stdio.h>
#include "../../include/business/human.h"
#include "../../include/core.h"
#include "create_human.h"
#include "../../src/business/create_human.h"
#include <string.h>
int create_human(const char* filename,human human1, int* status) {
	long position;
	 human human2;
	//asign id
	int result= read_last_record(filename, &human2, sizeof(human), 1, status) + 1;
	//asign name
	human1.id=human2.id;
	//save record on file
	if (save_record(filename, &human1, sizeof(human), 1) == 0) {
		*status = 4;
		return 0;
	}
	return 1;
}