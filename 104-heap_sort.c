#include "sort.h"

/**
 * swap - A function that Swaps two integers in an array.
 *
 * @i: Pointer to the first integer.
 * @j: Pointer to the second integer.
 */
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * heap - A function that Rearranges the array elements to form a max heap.
 *
 * @array: The array
 * @size: The size of the array.
 * @idx: The index to start
 * @original: The original size of the array for printing.
 */
void heap(int *array, size_t size, size_t idx, size_t original)
{
	size_t big, left, right;

	left = 2 * original + 1;
	right = 2 * original + 2;
	big = original;

	if (left < idx && array[left] > array[big])
		big = left;
	if (right < idx && array[right] > array[big])
		big = right;

	if (big != original)
	{
		swap(array + original, array + big);
		print_array(array, size);
		heap(array, size, idx, big);
	}
}

/**
 * heap_sort - A function Sorts an array of integer
 * ascending order using Heap Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		heap(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap(array, array + j);
		print_array(array, size);
		heap(array, size, j, 0);
	}
}

