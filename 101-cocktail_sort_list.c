#include "sort.h"
/**
 * cocktail_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail_stop = NULL, *head_stop = NULL, *tail, *head = *list;
	int sorted = 0, swapped;

    if (list == NULL || *list == NULL)
        return;
	while (sorted <= 0)
	{
		while (head->next != tail_stop)
		{
			if (head->n > head->next->n)
			{
				swap_right(head);
				print_list(*list);
				swapped = 1;

			} else
				head = head->next;
		}
		tail_stop = head;
		tail = head->prev;
		while (tail->prev != head_stop)
		{
			if (tail->n < tail->prev->n)
			{
				swap_left(tail);
				swapped = 1;
				if (tail->prev == NULL)
					*list = tail;
				print_list(*list);
			} else
				tail = tail->prev;
		}
		head_stop = tail;
		head = tail->next;
		if (swapped == 0)
			sorted = 1;
		swapped = 0;
	}
}
/**
 * swap_right - swaps element to the right
 * @head: pointer to the head
 */
void swap_right(listint_t *head)
{
	listint_t *temp;

	if (head->prev)
		head->prev->next = head->next;
	if (head->next)
		head->next->prev = head->prev;
	if (head->next->next)
		head->next->next->prev = head;
	temp = head->next->next;
	head->prev = head->next;
	head->next->next = head;
	head->next = temp;
}
/**
 * swap_left - swaps element to the left
 * @tail: the tail of the list
 */
void swap_left(listint_t *tail)
{
	listint_t *temp;

	if (tail->next)
		tail->next->prev = tail->prev;
	if (tail->prev)
		tail->prev->next = tail->next;
	if (tail->prev->prev)
		tail->prev->prev->next = tail;
	temp = tail->prev->prev;
	tail->next = tail->prev;
	tail->prev->prev = tail;
	tail->prev = temp;
}
