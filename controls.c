/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 00:26:32 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/29 15:13:47 by cbozkurt         ###   ########.fr       */
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
