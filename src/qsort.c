/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:51:53 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/22 01:59:59 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//#include <stdio.h>
//#include <stdlib.h>
void	qs_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int arr[], int low, int high)
{
	int	p;
	int	i;
	int	j;

	p = arr[low];
	i = low + 1;
	j = high;
	while (i < j)
	{
		while (arr[i] <= p && i <= high - 1)
			i++;
		while (arr[j] > p && j >= low + 1)
			j--;
		if (i < j)
			qs_swap(&arr[i], &arr[j]);
	}
	qs_swap(&arr[low], &arr[j]);
	return (j);
}

void	quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int	*sorted_arr(int *arr, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		sorted[i] = arr[j];
		i++;
		j += 2;
	}
	quick_sort(sorted, 0, size - 1);
	return (sorted);
}
/*
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int *sorted = sorted_arr(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d ", sorted[i]);
	printf("\n");
	return 0;
}
*/
