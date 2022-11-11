#include "sort.h"

/**
 * quick_sort - sort the array using quick algorism
 * @array : the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function
 * @array : the array to be sorted
 * @left : the index of the left element
 * @right :  the indx of the rioght element
 * @size : the size of the array
 * Return: nothing
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv + 1, right, size);
	}
}

/**
 * partition - gives pic index for quick sort
 * @array :  the array to besorted
 * @left : index of the left element
 * @right : index of the roght element
 * @size:  size of the array
 * Return: int ( the index of PIV)
 */
int partition(int *array, int left, int right, size_t size)
{
	int tmp, x, y;

	x = left - 1;

	for (y = left; y < right; y++)
	{
		if (array[y] < array[right])
		{
			x++;
			if (x != y)
			{
				tmp = array[x];
				array[x] = array[y];
				array[y] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[right] < array[x + 1])
	{
		tmp = array[x + 1];
		array[x + 1] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}
	return (x + 1);
}
