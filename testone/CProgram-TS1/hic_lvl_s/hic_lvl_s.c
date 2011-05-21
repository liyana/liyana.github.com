/* static */

#include <stdio.h>
#include <stdlib.h>

static int count_count = 0;

static int static_example( int count)
{
  static int count_num = 0;
    
    count_num += count;
    
    return(count_num);
}

int main(int argc, char** argv)
{
    int count = 0;
	  
    count = static_example(4);//4
    count_count++;//1
    printf("static_example() get count number is %d \n", count);//4
    printf("count_count is %d \n", count_count);//1
	  
    count = static_example(8);//12
    count_count++;//2
    printf("static_example() get count number is %d \n", count);//12
    printf("count_count is %d \n", count_count);	//2  
	  
    return 0;
}
