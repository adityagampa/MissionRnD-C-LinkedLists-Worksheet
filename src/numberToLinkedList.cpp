/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * createNode(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->num = data;
	n->next = NULL;
	return n;
}
int reverse(int n)
{
	int i = 0;
	while (n)
	{
		i = i * 10 + n % 10;
		n = n / 10;
	}
	return i;
}
struct node * numberToLinkedList(int n)
{
	struct node *temp, *head = NULL, *last = NULL;
	if (n == 0)
	{
		temp = createNode(n % 10);
		return temp;
	}
	if (n<0)
		n = n*(-1);
	n = reverse(n);
	while (n)
	{
		temp = createNode(n % 10);
		if (head)
		{
			last->next = temp;
			last = temp;
		}
		else
		{
			head = temp;
			last = head;
		}
		n = n / 10;
	}
	return head;
}
