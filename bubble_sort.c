/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:53:06 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/16 16:35:02 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sorting(t_node **a, t_ops *ops)
{
	int	size;
	int	i;
	int	j;

	if (!a || !*a)
		return;
	size = input_counter(*a);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*a)->value > (*a)->next->value)
				sa(a, ops);
			ra(a, ops);
			j++;
		}
		j = 0;
		while (j++ < size - 1)
			rra(a, ops);
		i++;
	}
}
