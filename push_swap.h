/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:39:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/29 15:53:19 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <stddef.h>

typedef struct	s_node
{
    int             value;
	int				index;
    struct s_node   *next;
} t_node;

void		default_controls(t_node *a);
int			input_counter(t_node *a);
int			is_valid_number(char *str);

void		print_error(void);
int			is_sorted(t_node *a);
void		is_duped(t_node *a);
long int	ft_so_long_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);

void		sa(t_node	**a);
void		sb(t_node	**a);
void		ss(t_node	**a, t_node **b);

void    	pa(t_node **a, t_node **b);
void    	pb(t_node **b, t_node **a);
        	
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **b, t_node **a);
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **b, t_node **a);
        	
void		add_back(t_node **lst, t_node *next);
t_node		*new_lst(int value);
int			list_size(t_node *a);

char    	*join_args(int argc, char **argv);
int     	total_length(int argc, char **argv);
float		compute_disorder(t_node *a);
int			ft_sqrt(int n);

void		chunk_core_indexer(t_node *a);
void		navigation(t_node **a, int strat);
void		bubble_sorting(t_node **a);
void		chunk_sorting(t_node **a, t_node **b);
void		radix(t_node **a, t_node **b);

#endif
