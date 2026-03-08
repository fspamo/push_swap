/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:18:43 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/08 13:57:37 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*copy_array(t_node *a, int size)
{
	int		i;
	int		*array;
	t_node	*copycat;

	i = 0;
	copycat = a;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (copycat)
	{
		array[i] = copycat->value;
		i++;
		copycat = copycat->next;
	}
	return (array);
}

void	sort_arr(int *array, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_numbers(t_node *a, int *array, int size)
{
	t_node	*holder;
	int		i;

	holder = a;
	while (holder)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == holder->value)
			{
				holder->value = i;
				break;
			}
			i++;
		}
		holder = holder->next;
	}
}

void	core_indexer(t_node *a)
{
	int *array;
	int	size;

	size = input_counter(a);
	array = copy_array(a, size);
	if (!array)
		return ;
	sort_arr(array, size);
	index_numbers(a, array, size);
	free(array);
}
