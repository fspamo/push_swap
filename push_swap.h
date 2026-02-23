/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:39:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/22 13:39:35 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_node
{
    int             value;
    struct s_node   *next;
} t_node;

void	swap(t_node **stack);
