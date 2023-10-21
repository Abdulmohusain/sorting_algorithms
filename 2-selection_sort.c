#include "sort.h"

/**
 * selection_sort - A function that sort an array using the Selection
 * Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp;
	unsigned int idx = 0;
	bool check;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		check = false;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
			{
				idx = j;
				check = true;
			}
		}

		temp = array[i];
		array[i] = array[idx];
		array[idx] = temp;
		if (check)
			print_array(array, size);
	}
}
