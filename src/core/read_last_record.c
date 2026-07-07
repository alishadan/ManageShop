// src/core/read_last_id.c
#include <string.h>
#include "../../include/core.h"
#include <stdio.h>
int read_last_record(const char* filename, void* record, size_t size_record, size_t nmemb,int*status) {
	//check inputs
	if (nmemb != 1 || filename == NULL || size_record == 0) {
		*status = 0;
		return 0;
	}
	//open filename
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		*status = 1;
		return 0;
	}
	fseek(file, -(long)sizeof(record), SEEK_END);
	size_t byte_readed = fread(record, sizeof(record), 1, file);
	fclose(file);
	if (byte_readed != 1) {
		*status = 3;
		return 0;
	}
	return 1;

}