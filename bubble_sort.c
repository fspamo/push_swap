/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:53:06 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/12 14:47:18 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sorting(t_node **a)
{
	int	size;
	int	i;
	int	j;

	if (!a || !*a)
		return;
	size = input_counter(*a);
	i = 0;
	while (is_sorted(*a))
	{
		while (i < size - 1)
		{
			j = 0;
			while (j < size - 1)
			{
				if ((*a)->value > (*a)->next->value)
					sa(a);
				ra(a);
				j++;
			}
			i++;
		}
	}
}
