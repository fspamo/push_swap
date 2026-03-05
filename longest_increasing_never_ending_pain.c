/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_never_ending_pain.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 01:47:21 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/04 22:59:02 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*copy_stack(t_node *a, int size)
{
	int		*yanked_stack;
	t_node	*instance;
	size_t	i;

	instance = a;
	i = 0;
	yanked_stack = malloc(size * sizeof(int));
	if (!yanked_stack)
		return (0);
	while (instance)
	{
		yanked_stack[i] = instance->value;
		instance = instance->next;
		i++;
	}
	return (yanked_stack);
}

void	sort_array(int *array, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
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

void    index_stack(t_node *a)
{
	int		*array;
	t_node	*temp;
	int		i;
	int		size;

	array = copy_stack(a, input_counter(a));
	sort_array(array, input_counter(a));
	size = input_counter(a);
	temp = a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->value == array[i])
			{
				temp->value = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}

void core_keeper(t_node **a, t_node **b)
{
    t_node *last_node;

    index_stack(*a);
    last_node = last_lis_node(*a, calc_list_len(*a));
    mark_list(*a, last_node);
    toss_to_b(a, b);
	the_hunter(a, b);
	final_rotate(a);

	print_b_stakk(*b);
}
