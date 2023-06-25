#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *			order using the Insertion sort algorithm
 * @list: A pointer to the linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			tmp = current->prev;
			current->prev = tmp->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = current;

			tmp->next = current->next;
			tmp->prev = current;
			current->next = tmp;

			if (tmp->next != NULL)
				tmp->next->prev = tmp;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
		current = current->next;
	}
}
