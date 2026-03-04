/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 01:38:09 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/04 04:57:52 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_list_len(t_node *a)
{
	int		so_long;
	int		temp_long;
	t_node	*curr;
	t_node	*temp;

	so_long = 0;
	curr = a;
	while (curr)
	{
		temp_long = 1;

		temp = a;
		while (temp != curr)
		{
			if (temp->index < curr->index 
					&& temp->lis_len + 1 > temp_long)
			{
				temp_long = temp->lis_len + 1;
			}
			temp = temp->next;
		}
		curr->lis_len = temp_long;

		if (temp_long > so_long)
			so_long = temp_long;

		curr = curr->next;
	}
	return (so_long);
}

t_node	*last_lis_node(t_node *a, int max_len)
{
	t_node	*temp;
	t_node	*last;

	temp = a;
	last = NULL;

	while (temp)
	{
		if (temp->lis_len == max_len)
			last = temp;
		temp = temp->next;
	}
	return (last);
}

void	mark_list(t_node *a, t_node *last)
{
	int		curr_len;
	int		curr_index;
	t_node	*temp;

	curr_len = last->lis_len;
	curr_index = last->index;
	while (last)
	{
		last->in_lis = 1;
		temp = a;	
		while (temp != last)
		{
			if (temp->lis_len == curr_len - 1 
					&& temp->index < curr_index)
			{
				last = temp;
				curr_len--;
				curr_index = temp->index;
				break;
			}
			temp = temp->next;
		}
		if (curr_len == 1)
		{
			last->in_lis = 1;
			break;
		}
	}
}

void	toss_to_b(t_node **a, t_node **b)
{
	t_node	*holder;
	int		size;

	holder = *a;
	size = list_size(*a);
	while (size--)
	{
		if (holder->in_lis == 0)
			pb(a, b);
		else
			ra(a);
		holder = *a;
	}
}
