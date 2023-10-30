#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node: Node to be swapped
 * @list: Pointer to the list
 */
void swap_nodes(listint_t *node, listint_t **list)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	if (node->next)
		node->next->prev = node->prev;

	node->prev = node->next;
	node->next = node->prev->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;

	if (node->prev->prev == NULL)
		*list = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using
 * the Cocktail shaker sort algorithm
 * @list: Pointer to the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, list);
				print_list(*list);
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
				swap_nodes(current, list);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

