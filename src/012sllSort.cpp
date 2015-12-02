/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node * createnode(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->next = NULL;
	return n;
}
struct node *insertInEnd(struct node *head, int n)
{
	struct node *temp = createnode(n), *last = head;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		while (last->next)
		{
			last = last->next;
		}
		last->next = temp;
		last = temp;
	}
	return head;
}
void sll_012_sort(struct node *head)
{
	struct node *i = head, *j = head;
	int data;
	while (i)
	{
		j = head;
		while (j->next)
		{
			if (j->data > j->next->data)
			{
				data = j->next->data;
				j->next->data = j->data;
				j->data = data;
			}
			j = j->next;
		}
		i = i->next;
	}
}
