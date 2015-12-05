/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int k)
{
	struct node *temp = head, *prev = head;
	int i = 0;
	if (k <= 1)
	{
		while (temp)
		{
			prev = temp->next;
			free(temp);
			temp = prev;
		}
		return NULL;
	}
	while (temp && temp->next)
	{
		for (i = 0; i<k - 1; i++)
		{
			if (temp == NULL)
				return head;
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			return head;
		prev->next = temp->next;
		free(temp);
		temp = prev;
		temp = temp->next;
	}
	return head;
}
