#include "save_record.h"
#include <stdio.h>
#include <io.h>
int save_record(const char* filename, const void* record, size_t size_record, size_t nmemb) {
	//check inputs
	if (nmemb != 1 || filename == NULL || size_record==0) {
		return 0;
	}
	//save a record on a file
	//first create a FILE pointer with name filename
	FILE* file = fopen(filename, "ab");
	if (file == NULL) {
		return 0;
	}
	//second write record on filename
	size_t writen_byte = fwrite(record, size_record, nmemb, file);
	fclose(file);
	if (writen_byte!=1) {
		return 0;
	}
	return 1;
}