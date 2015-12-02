/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

struct node * createnode(int a, int b)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->digit1 = a;
	n->digit2 = b;
	n->next = NULL;
	return n;
}
struct node *insertInEnd(struct node *head, int a, int b)
{
	struct node *temp = createnode(a, b), *last = head;
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
int convert_sll_2digit_to_int(struct node *head)
{
	struct node *temp = head;
	int n = 0;
	while (temp)
	{
		n = n * 100 + temp->digit1 * 10 + temp->digit2;
		temp = temp->next;
	}
	return n;
}

