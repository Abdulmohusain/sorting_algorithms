#include "sort.h"
/**
 * bubble_sort - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: the list
 */
void insertion_sort_list(listint_t **list)
{
	size_t a, i;
	int swap, temp;

	for (a = 0; a < (size - 1); a++)
	{
		swap = 0;
		for (i = 0; i < (size - a - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
			}
		}
		print_array(array, size);
		if (swap == 0)
			return;
	}
}
