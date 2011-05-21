#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
int m = atoi(argv[2]); int n = atoi(argv[1]);
	
	Josephus( n,m);
    
	return 0;

}

int Josephus(int n,int m)
{      int i,count;
	typedef struct Node {
		int val;
		struct Node *next;
	} Node, *PNode;

	PNode head, item, parent;
	head = (struct Node*) malloc(sizeof(Node) * n);
	if (!head)
		printf("malloc error");

	item = head;
	for (i = 0; i < n; i++) {
		item->val = i + 1;
		if (i == n- 1) {
			item->next = head;
			parent=item;
		}

		else {
			item->next = item + 1;
		}
		item++;
	}

         item=head;

	for (i = 0; i < n; i++) {
		count = 0;
		while (++count < m) {
			parent = item;
			item = item->next;
		}
		printf("%3d:%5d.out ", i + 1, item->val);
		if ( (i+1) % 5 == 0)
			printf("\n");
		parent->next = item->next;
		item = parent->next;
	}
	if (head)
		free(head);
	return 0;



}


