int check_human(const char* name, const char* filename){
	int result=search_human_ui(filename);
	if(result==1){
		printf("\n please enter code of %s \n",name);
		char code[10];
		result=get_name_stdin(code, sizeof(code));
		int status; long int position;
		result=search_human_by_code(filename,code,&position, &status);
		if (result==2) {
			printf("the code not exist \n"); return 0;
		}
		if (result==1){
			if(read_human(&human1,filename,&status,position)==1){
				return 1;
			}
			else printf("error in read_human function \n");
		}
}