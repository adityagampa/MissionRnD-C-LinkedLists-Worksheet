/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node
{
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head)
{
	struct node *i = head, *j = head;
	int data;
	while (i)
	{
		j = head;
		while (j->next)
		{
			if (j->num > j->next->num)
			{
				data = j->next->num;
				j->next->num = j->num;
				j->num = data;
			}
			j = j->next;
		}
		i = i->next;
	}
	return head;
}
