#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of
 * integers using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, list);
				swapped = 1;
			}
		}
	}
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @node: Pointer to the first node
 * @list: Pointer to the head of the list
 */
void swap_nodes(listint_t *node, listint_t **list)
{
	listint_t *prev, *next;

	prev = node->prev;
	next = node->next;

	if (prev)
		prev->next = next;
	else
		*list = next;

	node->prev = next;
	node->next = next->next;

	next->prev = prev;
	next->next = node;

	if (node->next)
		node->next->prev = node;
}

