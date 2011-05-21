#include <stdio.h>
typedef int (*cmp_t) (void *, void *);

void *max(void *pdata[], int n, cmp_t cmp)
{
	int i;
	void *j = pdata[0];
	for (i = 0; i < n; i++)
		if (cmp(j, pdata[i]) < 0) {
			j = pdata[i];
		}
	return j;
}

typedef struct {
	char *name;
	int score;

} student_t;

int cmp_student(void *m, void *n)
{
	if (((student_t *) m)->score > ((student_t *) n)->score)
		return 1;
	if (((student_t *) m)->score == ((student_t *) n)->score)
		return 0;
	else
		return -1;
}

int main(int argc, const char *argv[])
{
	student_t list[4] =
	    { {"li", 78}, {"nn", 89}, {"ll", 90}, {"ya", 65} };
	student_t *p[4] = { &list[0], &list[1], &list[2], &list[3] };
	student_t *pmax = max((void **) p, 4, cmp_student);
	printf("%d\n", pmax->score);
	return 0;
}
