#pragma once
#include "business/customer.h"
int search_customer(const char* filename, const char* code, long* position, int* status);
int create_customer(customer customer1, int* status);