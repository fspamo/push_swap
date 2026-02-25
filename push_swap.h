/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:39:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/25 00:29:24 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <stddef.h>

typedef struct	s_node
{
    int             value;
    struct s_node   *next;
} t_node;

int		is_sorted(t_node *a);
int		ft_atoi(const char *nptr);
void	swap(t_node **stack);
void    push(t_node **src, t_node **dest);
void	add_back(t_node **lst, t_node *next);

#endif
