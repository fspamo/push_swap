/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:39:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/27 18:29:34 by cbozkurt         ###   ########.fr       */
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

void	default_controls(t_node *a);

int			is_sorted(t_node *a);
long int	ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);

void	sa(t_node	**a);
void	sb(t_node	**a);
void	ss(t_node	**a, t_node **b);

void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);


void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **b, t_node **a);

void	add_back(t_node **lst, t_node *next);
t_node *new_lst(int value);

char    *join_args(int argc, char **argv);
int     total_length(int argc, char **argv);

#endif
