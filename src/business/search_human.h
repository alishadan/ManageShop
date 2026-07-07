#pragma once
#include "../../include/business/human.h"
int search_human_by_code(const char* filename,const char* code,long int* position, int* status);
int search_human_by_name(human *human1,const char* name,const char* filename,int *status,long int *position);