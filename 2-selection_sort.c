#include "sort.h"

/**
 * selection_sort - Sorting Algorithm
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 *
 * A selection-sort algorithm for sorting an array of integers.
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t sort_position, min_position, cursor;
	int hold;

	if (!array || size < 2)
		return;

	sort_position = 0;

	while (sort_position < size - 1)
	{
		cursor = sort_position + 1;
		min_position = cursor;

		while (cursor < size)
		{
			if (array[cursor] < array[min_position])
			{
				min_position = cursor;
			}
			cursor++;
		}

		if (array[min_position] < array[sort_position])
		{
			hold = array[min_position];
			array[min_position] = array[sort_position];
			array[sort_position] = hold;
			print_array(array, size);
		}
		sort_position++;
	}
}
