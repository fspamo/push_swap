/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:38:17 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/04 22:57:38 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_b_stakk(t_node *b)
{
	t_node *instance;

	if (!b)
	{
		printf("Stack B is empty\n");
		return;
	}

	instance = b;
	printf("Stack B:\n");
	while (instance)
	{
		printf("%d\n", instance->in_lis);
		instance = instance->next;
	}
}
