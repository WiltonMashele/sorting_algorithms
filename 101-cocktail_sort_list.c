#include "sort.h"

void exchange_node_forward(listint_t **list, listint_t **end,
		listint_t **current);
void exchange_node_backward(listint_t **list, listint_t **end,
		listint_t **current);
void perform_cocktail_sort(listint_t **list);

/**
 * exchange_node_forward - Interchange a node in a listint_t doubly-linked 
 *                         integer list with the following node.
 * @list: Pointer to the head of the doubly-linked integer list.
 * @end: Pointer to the tail of the doubly-linked list.
 * @current: Pointer to the node being swapped in the cocktail sort algorithm.
 */
void exchange_node_forward(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*end = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * exchange_node_backward - Interchange a node in a listint_t doubly-linked 
 *                          integer list with the preceding node.
 * @list: Pointer to the head of the doubly-linked integer list.
 * @end: Pointer to the tail of the doubly-linked list.
 * @current: Pointer to the node being swapped in the cocktail sort algorithm.
 */
void exchange_node_backward(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*end = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}

/**
 * perform_cocktail_sort - Arrange a listint_t doubly-linked integer list 
 *                         in ascending order utilizing the cocktail shaker sort.
 * @list: Pointer to the head of a listint_t doubly-linked list.
 */
void perform_cocktail_sort(listint_t **list)
{
	listint_t *end, *current;
	bool is_sorted = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (is_sorted == false)
	{
		is_sorted = true;
		for (current = *list; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				exchange_node_forward(list, &end, &current);
				print_list((const listint_t *)*list);
				is_sorted = false;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				exchange_node_backward(list, &end, &current);
				print_list((const listint_t *)*list);
				is_sorted = false;
			}
		}
	}
}
