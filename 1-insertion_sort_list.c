#include "sort.h"

/**
 * swap_list_nodes - Interchanges two nodes in a listint_t doubly-linked list.
 * @head: A reference to the head of the doubly-linked list.
 * @node1: A reference to the first node to exchange.
 * @node2: The second node to exchange.
 */
void swap_list_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       by utilizing the insertion sort algorithm.
 * @list: A reference to the head of a doubly-linked list of integers.
 *
 * Description: Outputs the list following each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *walker, *inserter, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (walker = (*list)->next; walker != NULL; walker = temp)
	{
		temp = walker->next;
		inserter = walker->prev;
		while (inserter != NULL && walker->n < inserter->n)
		{
			swap_list_nodes(list, &inserter, walker);
			print_list((const listint_t *)*list);
		}
	}
}
