/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 00:26:32 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/20 17:02:55 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	default_controls(t_node *a, t_ops *ops, int bench)
{
	float	disholder;

	disholder = compute_disorder(a);
	if (bench == 0)
		is_sorted(a);
	is_duped(a);
	if (five_or_less_control(a, ops) == 1)
	{
		if (bench == 1)
			benchmarking(ops, 0, disholder);
		free_list(&a);
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
			{
				free_list(&a);
				print_error();
			}
			holder = holder->next;
		}
		curr = curr->next;
	}
}

int	is_sorted(t_node *a)
{
	t_node	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	free_list(&a);
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
	int		size;
	t_node	*b;

	size = input_counter(a);
	b = NULL;
	if (size == 2)
		two_numbers(a, ops);
	else if (size == 3)
		three_numbers(&a, ops);
	else if (size == 4)
		four_numbers(&a, &b, ops);
	else if (size == 5)
		five_numbers(&a, &b, ops);
	else
		return (0);
	return (1);
}
