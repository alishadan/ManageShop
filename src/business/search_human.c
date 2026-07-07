#include <stdio.h>
#include "search_human.h"
#include "../../include/business/human.h"
#include <string.h>
int search_human_by_code(const char* filename,const char* code,long int* position, int* status) {
	human human1;
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		*status = 1;
		return 0; //error
	}


	while (fread(&human1, sizeof(human), 1, file) == 1) {
		if (strcmp(human1.code, code) == 0){ 
			*position = ftell(file)-sizeof(human);
			fclose(file);
			return 1;  //the code exist
		}
	}
	fclose(file);
	return 2; //the code not exist

}

int search_human_by_name(human *human1,const char* name,const char* filename,int *status,long int *position){
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		*status = 1;
		return 0; //error
	}
	if (fseek(file,*position,SEEK_SET)!=0){
		perror("fseek failed");
		*status=2;
		return 0;
	}

	while (fread(human1, sizeof(human), 1, file) == 1){
		if (strcmp(human1->name, name) == 0) {
			*status = 0;
			*position=ftell(file);
			if (*position==-1){
				perror("ftell error");
				*status=2;
				return 0; //error
			}
			fclose (file);
			return 1;  //the code exist
		}

	}
	*status = 0;
	fclose(file);
	return 2; //the code not exist

}