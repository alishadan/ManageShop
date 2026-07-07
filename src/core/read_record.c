#include "read_record.h"
#include <stdio.h>
#include <stddef.h>
int read_record(const char* filename, void* record, size_t size_record, int* status, long int position) {
	//check inputs
	//printf("%s | %");
	if (filename == NULL || size_record == 0 || record==NULL || status==NULL) {
		*status = 1;
		return 0;
	}
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		*status = 2;
		return 0;
	}
	fseek(file, position, SEEK_SET);
	size_t byte_readed = fread(record, size_record, 1, file);
	fclose(file);
	if (byte_readed != 1) {
		*status = 3;
		return 0;
	}
	*status=0;
	return 1;
}