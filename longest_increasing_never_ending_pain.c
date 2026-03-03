/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_never_ending_pain.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 01:47:21 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/03 01:52:17 by cbozkurt         ###   ########.fr       */
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
	while (instance && i < size)
	{
		yanked_stack[i] = instance->value;
		instance = instance->next;
		i++;
	}
	return (yanked_stack);
}

void	sort_array(int *array, int size)
{
	
}

void    index_stack(t_node *a)
{
	//  create a sorted array and pass arguments inside.
	int	*array;

	array = copy_stack(a, input_counter(a));
	sort_array(array, );
}
