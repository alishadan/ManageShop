#pragma once
#define MAX_NAME_LEN 50
#define MAX_TELEPHONE_LEN 11
#define MAX_CODE_LEN 3
typedef struct {
	int id;
	char name[MAX_NAME_LEN+1];
	char code[MAX_CODE_LEN+1];
	int sale_price;
	int purchase_price;
	int quantity;

}product;