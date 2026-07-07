#include "edit_human.h"
#include "../../include/business/human.h"
#include "../../src/core/edit_record.h"
int edit_human(const char* filename, human human1,long int position){
	int result=edit_record(filename,&human1,sizeof(human),1,position);
	return result;
}