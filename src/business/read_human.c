#include "read_human.h"
#include <stdio.h>
#include "../../src/core/read_record.h"
#include "../../include/business/human.h"
int read_human(const char* filename, human* human1, int* status, long int count) {
	int result=read_record(filename, human1, sizeof(human), status, count);
	return result;
}