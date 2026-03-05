/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:39:30 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/03/05 03:05:22 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <stddef.h>

typedef struct	s_node
{
    int             value;
    int             index;
	int				lis_len;
	int				in_lis;	
    struct s_node   *next;
} t_node;

void		default_controls(t_node *a);
int			input_counter(t_node	*a);

void		print_error(void);
int			is_sorted(t_node *a);
void		is_duped(t_node *a);
long int	ft_so_long_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);

void		sa(t_node	**a);
void		sb(t_node	**a);
void		ss(t_node	**a, t_node **b);

void    	pa(t_node **a, t_node **b);
void    	pb(t_node **b, t_node **a);
        	
        	
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **b, t_node **a);
void		rra(t_node **a);
        	
void		add_back(t_node **lst, t_node *next);
t_node		*new_lst(int value);
int			list_size(t_node *a);

char    	*join_args(int argc, char **argv);
int     	total_length(int argc, char **argv);

void		navigation(t_node **a);
void		two_numbers(t_node **a);
void		three_numbers(t_node **a);
void		five_or_less(t_node **a, t_node **b);
void		chungus(t_node **a, t_node **b);
void		bubble_sortingen(t_node **a);

void    	index_stack(t_node *a);
int			calc_list_len(t_node *a);
t_node		*last_lis_node(t_node *a, int max_len);
void		mark_list(t_node *a, t_node *last);
void		toss_to_b(t_node **a, t_node **b);
void		core_keeper(t_node **a, t_node **b);
void		the_hunter(t_node **a, t_node **b);
void		rotate_to_target(t_node **a, t_node *target);
void		final_rotate(t_node **a);

// useless functions to clear up after debugging

void		print_b_stakk(t_node	*b);

#endif
