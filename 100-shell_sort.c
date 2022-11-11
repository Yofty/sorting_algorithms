#include "sort.h"

/**
 * shell_sort - sort array using knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, x, y;
	int tmp;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size)
		;

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (x = gap; x < size; x++)
		{
			tmp = array[x];
			for (y = x; y >= gap && tmp <= array[y - gap]; y -= gap)
				array[y] = array[y - gap];
			array[y] = tmp;
		}
		print_array(array, size);
	}
}
