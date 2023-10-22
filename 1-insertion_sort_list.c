#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *list_copy, *current, *temp, *next;
	int i = 0;

	if (*list == NULL)
		return;
	list_copy = (*list)->next;
	while (list_copy)
	{
		next = list_copy->next;
		current = list_copy;
		i++;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->prev)
			{
			if (current->next)
				current->next->prev = current->prev;
			if (current->prev->prev)
				current->prev->prev->next = current;
			temp = current->prev->prev;
			current->prev->prev = current;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = temp;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			}
		}
	list_copy = next;
	}
}
