#include <stdio.h>
#include "draw_submenu.h"
int draw_submenu(const char* entity) {
	printf("\n \n MANAGE SHOP \n");
	printf("#########################\n"
		   "# Add %s (A)      \n"
		   "# view %s (V) \n"
		   "# edit %s (D)    \n"
		   "# search %s (S)    \n"
		   "# back to main (B)     \n"
		   "# exit (E)             \n"
		   "#########################\n",
		entity,entity,entity,entity
	);
	return 1;
}