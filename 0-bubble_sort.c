#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/**
  * bubble_sort - Sort the @array in ascending order
  * @array: The array to sort
  * @size: The length of the array
  */
void bubble_sort(int *array, size_t size)
{
	int temp;
	bool swapper;
	size_t j, i = 0;

	while (i < size - 1)
	{
		swapper = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapper = true;
				print_array(array, size);
			}
		}
		if (swapper == false)
			break;
		i++;
	}
}
