/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:20:13 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/12 15:07:05 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_node *a)
{
	t_node	*for_pairs;
	t_node	*for_mistakes;
	float	i = 0;
	float	j = 0;

	for_mistakes = a;
	for_pairs = a;

	while (for_mistakes->next)
	{
		if (for_mistakes->value > for_mistakes->next->value)
			i++;
		for_mistakes = for_mistakes->next;
	}
	while (for_pairs->next)
	{
		if (for_pairs->next->value > for_pairs->value)
			j++;
		for_pairs = for_pairs->next;
	}

	float total = i / j;
	printf("%f", total);
	return (total);
}
