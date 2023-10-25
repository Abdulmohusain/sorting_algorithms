#include "sort.h"
/**
 * counting_sort - A function that sort array
 * @array: array
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *new, *count;
	size_t max, i, temp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	max= 0;
	while (i < size)
	{
		if (array[i] > (int)max)
			max = array[i];
		i++;
	}
	max++;

	count = malloc(max * sizeof(int));
	if (count == NULL)
		return;
	new = malloc(size * sizeof(int));
	if (new == NULL)
	{
		free(count);
		return;
	}

	i = 0;
	while (i < size)
	{
		new[i] = array[i];
		i++;
	}

	i = 0;
	while (i < max)
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while (i < size)
	{
		count[array[i]]++;
		i++;
	}

	i = 1;
	while (i < max)
	{
		count[i] += count[i - 1];
		i++;
	}

	print_array(count, max);

	i = 0;
	while (i < size)
	{
		temp = new[i];
		array[count[temp] - 1] = temp;
		count[temp]--;
		i++;
	}
	free(count);
	free(new);
}
