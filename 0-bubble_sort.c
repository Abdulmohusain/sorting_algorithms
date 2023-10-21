#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: The array
 * @size: The size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, i;
	int swap, temp;

	if (array == NULL || size == 0)
		return;
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
				print_array(array, size);
			}
		}
		if (swap == 0)
			return;
	}
}
