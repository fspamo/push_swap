/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adp_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:02:51 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/04/20 13:03:53 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*adp_printer(float disorder)
{
	char	*metric;

	metric = NULL;
	if (disorder < 0.2)
		metric = ft_strdup("Adaptive / O(n²)");
	else if (0.2 <= disorder && disorder < 0.5)
		metric = ft_strdup("Adaptive / O(n√n)");
	else if (disorder >= 0.5)
		metric = ft_strdup("Adaptive / O(n log n)");
	return (metric);
}
