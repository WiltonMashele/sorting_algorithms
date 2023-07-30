#include "sort.h"

void swap_forward(listint_t **head, listint_t **end, listint_t **mover);
void swap_backward(listint_t **head, listint_t **end, listint_t **mover);
void cocktail_sort_list(listint_t **list);

/**
 * swap_forward - Change places of a node with the next node in a
 *                listint_t doubly-linked integer list.
 * @head: Pointer to the start of the doubly-linked list.
 * @end: Pointer to the last node of the doubly-linked list.
 * @mover: Pointer to the current node being swapped by the algorithm.
 */
void swap_forward(listint_t **head, listint_t **end, listint_t **mover)
{
	listint_t *temp = (*mover)->next;

	if ((*mover)->prev)
		(*mover)->prev->next = temp;
	else
		*head = temp;
	temp->prev = (*mover)->prev;
	(*mover)->next = temp->next;
	if (temp->next)
		temp->next->prev = *mover;
	else
		*end = *mover;
	(*mover)->prev = temp;
	temp->next = *mover;
	*mover = temp;
}

/**
 * swap_backward - Change places of a node with the previous node in a
 *                 listint_t doubly-linked integer list.
 * @head: Pointer to the start of the doubly-linked list.
 * @end: Pointer to the last node of the doubly-linked list.
 * @mover: Pointer to the current node being swapped by the algorithm.
 */
void swap_backward(listint_t **head, listint_t **end, listint_t **mover)
{
	listint_t *temp = (*mover)->prev;

	if ((*mover)->next)
		(*mover)->next->prev = temp;
	else
		*end = temp;
	temp->next = (*mover)->next;
	(*mover)->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = *mover;
	else
		*head = *mover;
	(*mover)->next = temp;
	temp->prev = *mover;
	*mover = temp;
}

/**
 * cocktail_sort_list - Arranges a listint_t doubly-linked integer list in
 *                      ascending order using the cocktail shaker sort method.
 * @list: Pointer to the start of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *mover;
	bool sorting_done = false;

	if (!list || !*list || !(*list)->next)
		return;

	end = *list;
	while (end->next)
		end = end->next;

	while (!sorting_done)
	{
		sorting_done = true;
		mover = *list;
		while (mover != end)
		{
			if (mover->n > mover->next->n)
			{
				swap_forward(list, &end, &mover);
				print_list((const listint_t *)*list);
				sorting_done = false;
			}
			mover = mover->next;
		}

		mover = mover->prev;
		while (mover != *list)
		{
			if (mover->n < mover->prev->n)
			{
				swap_backward(list, &end, &mover);
				print_list((const listint_t *)*list);
				sorting_done = false;
			}
			mover = mover->prev;
		}
	}
}

