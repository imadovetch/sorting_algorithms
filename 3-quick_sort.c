#include "sort.h"

/**
 * partition - This function finds the pivot
 * element in the array and returns its index.
 * @array: The array to sort.
 * @low: The start index of the subarray to sort.
 * @high: The end index of the subarray to sort.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, temp, j;

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (j != i)
				print_array(array, size);
		}
	}

	i++;
	if (array[i] != array[high])
	{
		temp = array[high];
		array[high] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
	return i;
}

/**
 * Lomuto_quick_sort - This function sorts the array
 * using the Lomuto partitioning scheme.
 * @array: The array to sort.
 * @low: The start index of the subarray to sort.
 * @high: The end index of the subarray to sort.
 * @size: The size of the array.
 */
void Lomuto_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high <= low)
		return;

	pivot = partition(array, low, high, size);
	Lomuto_quick_sort(array, low, pivot - 1, size);
	Lomuto_quick_sort(array, pivot + 1, high, size);
}

/**
 * quick_sort - This function sorts the array using the quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	Lomuto_quick_sort(array, 0, size - 1, size);
}
