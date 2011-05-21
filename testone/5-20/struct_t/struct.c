#include <stdio.h>
#include <stdlib.h>
typedef struct student {
	char *name;
	int age;
	float score;
} student_t;

int main(int argc, const char *argv[])
{
	char Name[] = "liyana";
	student_t *s_t;
	s_t = malloc(sizeof(student_t));

	s_t->age = 18;
	s_t->score = 79;
	s_t->name = Name;

	printf("s_t->age (value is %d)\ns_t->score (value is %f)\n",
	       s_t->age, s_t->score);
	printf("s_t->name (value is %s)\n", (char *) s_t->name);
	// printf("s_t->name (value is %s)\n",s_t->name);
       free(s_t);
	return 0;
}
