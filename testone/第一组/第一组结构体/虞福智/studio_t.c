/* studio */

#include <stdio.h>
#include "struct_t.h"
#include<stdlib.h>

int main( int argc, char ** argv)
{
  /*   struct space_3d sp;*/
     char sp_name[] = "gps";
     struct space_3d *p;

     p=(struct space_3d *)malloc(sizeof(struct space_3d));
     
     if (p==NULL)
     {
        printf("error!");
        exit(1);
     }

#if 0
     sp.x = 255;
     sp.y = 512;
     sp.z = 1024;
     sp.name = sp_name;
     printf(" sp.x (value is %d)\n sp.y (value is %f) \n", sp.x, sp.y);
     printf(" sp.z (value is %f)\n sp.name (name is %s)\n", sp.z, (char*)sp.name);
#else    
     p->x=254;
     p->y=510;
     p->z=1023;
     p->name=sp_name;

     printf(" p->x (value is %d)\n p->y (value is %f) \n", p->x, p->y);
     printf(" p->z (value is %f)\n p->name (name is %s)\n", p->z, (char*)p->name);
#endif
    
    return 0;
}
