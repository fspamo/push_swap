/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melipola <melipola@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:46:24 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/16 16:17:05 by melipola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_counter(t_node *a)
{
	t_node	*holder;
	int		count;

	holder = a;
	count = 0;
	while (holder)
	{
		holder = holder->next;
		count++;
	}
	return (count);
}
