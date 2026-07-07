#pragma once
#include <stddef.h>
int save_record(const char* filename, const void* record, size_t size_record, size_t nmemb);
int read_last_record(const char* filename, void* record, size_t size_record, size_t nmemb,int*status);