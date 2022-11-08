#include "sort.h"

/**
 * selection_sort - sort the array using selection algorism
 * @array : the array to be sorted
 * @size : the size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int x, y, min;
	register int tmp;

	if (size < 2)
		return;

	for (x = 0 ; x < size ; x++)
	{
		min = x;
		for (y = x +1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}
		tmp = array[x];
		array[x] = array[min];
		array[min] = tmp;
		if (x != min)
			print_array(array, size);
	}
}
