/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 00:26:32 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/09 15:37:34 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	default_controls(t_node *a, t_ops *ops, int bench)
{
	float	disholder;

	disholder = compute_disorder(a);
	is_sorted(a);
	is_duped(a);
	if (five_or_less_control(a, ops) == 1)
	{
		if (bench == 1)
			benchmarking(ops, 0, disholder);
		exit (1);
	}
}

void	is_duped(t_node *a)
{
	t_node	*curr;
	t_node	*holder;

	curr = a;
	while (curr)
	{
		holder = curr->next;
		while (holder)
		{
			if (holder->value == curr->value)
				print_error();
			holder = holder->next;
		}
		curr = curr->next;
	}
}

int	is_sorted(t_node *a)
{
	t_node *temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	exit (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	five_or_less_control(t_node *a, t_ops *ops)
{
	t_node	*b;
	if (input_counter(a) <= 5)
	{
		if (input_counter(a) == 2)
		{
			two_numbers(a, ops);
			return (1);
		}
		else if (input_counter(a) == 3)
		{
			three_numbers(&a, ops);
			return (1);
		}
		else if (input_counter(a) == 4)
		{
			four_numbers(&a, &b, ops);
			return (1);
		}
		else if (input_counter(a) == 5)
		{
			five_numbers(&a, &b, ops);
			return (1);
		}
	}
	return (0);
}
