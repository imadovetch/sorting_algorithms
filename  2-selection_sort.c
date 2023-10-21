#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void selection_sort(int *array, size_t size){
	int currentmin = 0;
	int current = 0;
	size_t i, y;
	int track = 0;

	for (i = 0; i < size; i++)
	{
		for (y = 0; y < size; y++)
		{
			currentmin = y;
			if(array[y + 1] < array[y])
				currentmin = y + 1;
		}
		array[track] = currentmin;
		track++;
	}
	
}
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}