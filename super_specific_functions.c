/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_specific_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:54:00 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/20 16:02:34 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	blessing_souls(t_node **a, char **numbers, int i)
{
	free_list(a);
	free_numbers(numbers, i);
	print_error();
}
