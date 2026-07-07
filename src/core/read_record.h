#include <stddef.h>
#pragma once
int read_record(const char* filename, void* record, size_t size_record, int* status, long position);