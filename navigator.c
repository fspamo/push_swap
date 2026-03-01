/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:09:20 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/28 23:39:20 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	navigation(t_node	*a)
{
	t_node	*b;

	   (void)b;
	if (input_counter(a) == 2)
		two_numbers(&a);
	else if (input_counter(a) == 3)
		three_numbers(&a);
	else if (input_counter(a) == 5 || input_counter(a) == 4)
		five_or_less(&a, &b);
}
