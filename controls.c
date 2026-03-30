/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 00:26:32 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/29 15:52:40 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	default_controls(t_node *a)
{
	is_sorted(a);
	is_duped(a);
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
