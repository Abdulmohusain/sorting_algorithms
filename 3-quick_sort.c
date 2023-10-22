#include "sort.h"

/**
 * swap - A function Swap the values of two integers.
 * @i: first integer.
 * @j: second integer.
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * partition - A function Partition the array for the quicksort algorithm.
 * @array: An array to be sorted.
 * @start: Starting index
 * @end: Ending index
 * @size: Size of the array.
 * Return: Index of the pivot element.
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int idx = start;
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != idx)
			{
				swap(&array[i], &array[idx]);
				print_array(array, size);
			}
			idx++;
		}
	}
	if (pivot < array[idx])
	{
		swap(&array[idx], &array[end]);
		print_array(array, size);
	}

	return (idx);
}

/**
 * quick_sorting - A function that recursively sorts the array using
 * the quicksort algorithm.
 * @array: An to the array to be sorted.
 * @start: Starting index
 * @end: Ending index
 * @size: Size of the array.
 */
void quick_sorting(int *array, int start, int end, int size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end, size);
		quick_sorting(array, start, pivot_index - 1, size);
		quick_sorting(array, pivot_index + 1, end, size);
	}
}

/**
 * quick_sort - A funtion Sorts an array of integers using the
 * quicksort algorithm.
 * @array: An the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int start;
	int end;

	start = 0;
	end = size - 1;
	if (array == NULL || size < 2)
		return;

	quick_sorting(array, start, end, size);
}

