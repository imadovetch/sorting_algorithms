#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *after, *current;

	if (!list || !*list || !(*list)->next)
		return;

	current = *list;
	while (current)
	{
		after = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);

		}
		current = after;
	}
}
