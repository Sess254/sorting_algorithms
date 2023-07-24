/*
 * File: 0-bubble_sort.c
 * Auth: Sess254
 */
void swap(int *a, int *b);

#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using Bubble sort algo
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;

	if (size <= 1)
		return;

	for (i = 0; i < (size - 1); i++)
		for (j = 1; j < size; j++)
			if (array[j - 1] > array[j])
			{
				swap(&array[j - 1], &array[j]);
				print_array(array, size);
			}
}
/**
 * swap - swaps the two pointers to integers
 *@a:first int pointer
 *@b: second int pointer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
