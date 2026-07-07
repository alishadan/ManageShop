#include <stdio.h>
#include "edit_record.h"
int edit_record(const char* filename, const void* record, size_t size_record, size_t nmemb,long int position){
	//check inputs
	if (nmemb != 1 || filename == NULL || size_record==0) {
		return 0;
	}
	//edit a record on a file
	//first create a FILE pointer with name filename
	FILE* file = fopen(filename, "rb+");
	if (file == NULL) {
		return 0;
	}
	fseek(file,0,SEEK_END);
	long int filesize=ftell(file);
	if (fseek(file,position,SEEK_SET)!=0){
		fclose(file);
		return 0;
	}
	size_t writen_byte = fwrite(record, size_record, nmemb, file);
	
	if (writen_byte!=nmemb) {
		return 0;
	}
	fflush(file);
	fclose(file);
	return 1;
}