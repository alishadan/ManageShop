#pragma once
#include <stddef.h>
int read_last_record(const char* filename, void* record, size_t size_record, size_t nmemb,int* status);