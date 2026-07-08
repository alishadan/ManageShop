#include "check_folder.h"
#include "../../include/mylib/myc.h"
#include <stdio.h>
int check_folder(const char* folder, int* status){
	int result=create_folder(folder,status);
	if (result==0)
		return 0; //success;
	else
		return -1;
}
