#include "sort.h"

/**
 * shell_sort - A functin that Sorts an array of integers in ascending
 * order using the Shell Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t hole, i, j;
	int temp;

	if (!array || size < 2)
		return;

	hole = 1;
	while (hole < size / 3)
		hole = (hole * 3) + 1;

	while (hole)
	{
		for (i = hole; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= hole && array[j - hole] > temp; j -= hole)
			{
				array[j] = array[j - hole];
			}
			array[j] = temp;
		}

		print_array(array, size);

		hole /= 3;
	}
}
