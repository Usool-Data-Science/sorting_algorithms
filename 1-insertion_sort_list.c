#include <stdio.h>
#include "sort.h"

/**
  * backChecker - Checks the linklist backward and sort it.
  *
  * @head: The node to start checking from.
  */

void backChecker(listint_t *head)
{
	listint_t *back;
	listint_t *temp = head;
	listint_t *current = head;

	/*If its an empty list or first value*/
	if (!head || head->prev == NULL)
		return;

	back = head->prev;
	while(back && back->n > temp->n)
	{
		current = back;
		back = back->prev;
	}

	/*If it breaks because we leave the list, let temp be the first node*/
	if (!back)
		temp->next = current->prev;
	else
	{
		back->next = temp;
		temp->next = back->next->next;
	}
}

/**
  * insertion_sort_list - Sorts a linkedlist using insertion method.
  *
  * @list: The linkedlist to sort
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;

	/*Move to the first node of the list*/
	while (current && current->prev)
	{
		current = current->prev;
	}
	while (current && current->next)
	{
		backChecker(current);
		current = current->next;
	}

}
