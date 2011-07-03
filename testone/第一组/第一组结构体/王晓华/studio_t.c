

#include <stdio.h>
#include "struct_t.h"
#include <stdlib.h>
int main(int argc, char **argv) 
{
	struct space_3d *p;
	p = (struct space_3d *) malloc(sizeof(struct space_3d));
	char sp_name[] = "gps";

	p->x = 255;
	p->y = 512;
	p->z = 1024;
	p->name = sp_name;
	printf(" p ->x (value is %d)\n p->y (value is %f) \n", p->x,
		p->y);
	printf(" p->z (value is %f)\n p->name (name is %s)\n", p->z,
		(char *) p->name);
	free(p);

	return 0;
}


