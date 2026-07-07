#include "myc.h"
#include <stdio.h>
int main() {
	printf("please enter a phone \n");
	char name[5];
	fgets(name, sizeof(name), stdin);
	printf("%'s", name);
	return 0;
}