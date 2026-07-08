#include "check_requirements.h"
#include "../../src/utility/check_folder.h"
#include "../../include/mylib/myc.h"
#include <stdio.h>
int check_requirements(int *status){
	const char* folder="data";
	//if everything is okay
	int result=check_folder(folder,status);
	if (result==0) return 0;

	else return -1;
}
