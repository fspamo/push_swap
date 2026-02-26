/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:04:42 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/26 02:16:11 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// do this

void	two_numbers(t_node	*a)
{
	if(!default_controls(a))
		sa(&a);
}

void	three_numbers(t_node *a)
{
	int	st;
	int	nd;
	int	rd;

	st = a->value;
	nd = a->next->value;
	rd = a->next->next->value;

	
}

void	five_or_less(t_node *a)
{
	
}
