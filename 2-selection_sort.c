#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                  Selection Sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: No return value (void).
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest, tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[smallest] > array[j])
				smallest = j;
		}
		if (smallest != i)
		{
			tmp = array[i];
			array[i] = array[smallest];
			array[smallest] = tmp;
			print_array(array, size);
		}
	}
}
