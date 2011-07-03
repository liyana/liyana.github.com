/* studio */  
#include<stdlib.h>
#include <stdio.h>
#include "struct_t.h"

int main(int argc, char **argv) 
{
	struct space_3d *sp;
	struct space_3d p;
	sp = (struct space_3d *) malloc(sizeof(p));
//	sp=&p;
	char sp_name[] = "gps";

	sp->x = 255;
	sp->y = 512;
	sp->z = 1024;
	sp->name = sp_name;
	printf(" sp.x (value is %d)\n sp.y (value is %f) \n", sp->x,
		sp->y);
	printf(" sp.z (value is %f)\n sp.name (name is %s)\n", sp->z,
		(char *) sp->name);
	free(sp);

	return 0;
}


