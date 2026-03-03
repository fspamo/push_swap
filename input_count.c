/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:46:24 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/28 22:49:08 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_counter(int *array)
{
	
}

int	input_counter(t_node *a)
{
	t_node	*holder;
	int	count;

	holder = a;
	count = 0;
	while (holder)
	{
		holder = holder->next;
		count++;
	}
	return (count);
}
