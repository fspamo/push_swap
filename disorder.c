/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:20:13 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/19 22:25:22 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_node *a)
{
	t_node	*for_mistakes;
	float	i;
	float	j;
	float	total;

	i = 0;
	j = 0;
	for_mistakes = a;
	if (!for_mistakes || !for_mistakes->next)
        return (0);
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
