#include "sort.h"

/**
 * print - A function that Prints of the list.
 *
 * @arr: Input array.
 * @len: Start of array.
 * @max: End of array.
 */
void print(int *arr, size_t len, size_t max)
{
	size_t i;

	for (i = len; i < max; i++)
	{
		if (i > len)
			printf(", ");
		printf("%d", arr[i]);
	}
	printf("\n");
}

/**
 * top_down - A function that Merge
 * @arr1: Original input array.
 * @arr2: array for merging.
 * @min: Start of array.
 * @mid: Middle of the array.
 * @max: End of array.
 */
void top_down(int *arr1, int *arr2, size_t min, size_t mid, size_t max)
{
	size_t i = min;
	size_t j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print(arr1, min, mid);
	printf("[right]: ");
	print(arr1, mid, max);
	for (k = min; k < max; k++)
	{
		if (i < mid && (j >= max || arr1[i] <= arr1[j]))
		{
			arr2[k] = arr1[i];
			i++;
		}
		else
		{
			arr2[k] = arr1[j];
			j++;
		}
	}
	printf("[Done]: ");
	print(arr1, min, max);
	for (k = min; k < max; k++)
		arr1[k] = arr2[k];
}

/**
 * top_split -A function Split the array into two parts and merge.
 * @arr1: array.
 * @arr2: array for merging.
 * @len: Start of array.
 * @max: End of array.
 */
void top_split(int *arr1, int *arr2, size_t len, size_t max)
{
	size_t mid;

	if (max - len < 2)
		return;
	mid = (len + max) / 2;
	top_split(arr1, arr2, len, mid);
	top_split(arr1, arr2, mid, max);
	top_down(arr1, arr2, len, mid, max);
}

/**
 * merge_sort - A function Sort an array using the merge sort method.
 * @array: Input array.
 * @size: Size of the input array.
 */
void merge_sort(int *array, size_t size)
{
	int *new;

	if (array == NULL || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return;
	top_split(array, new, 0, size);
	free(new);
}

