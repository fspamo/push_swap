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
	float	i;
	float	j;
	float	total;

	i = 0;
	j = 0;
	for_mistakes = a;
	while (for_mistakes->next)
	{
		if (for_mistakes->value > for_mistakes->next->value)
			i++;
		for_mistakes = for_mistakes->next;
		j++;
	}
	total = i / j;
	return (total);
}
