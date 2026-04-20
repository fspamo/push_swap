/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melipola <melipola@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:01:56 by melipola          #+#    #+#             */
/*   Updated: 2026/04/20 13:04:41 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct hard_stuck
{
	float	disorder;
	int		strat;
	int		bench;
	int		offset;
}	t_vars;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

void		default_controls(t_node *a, t_ops *ops, int bench);
int			input_counter(t_node *a);
int			is_valid_number(char *str);
int			strategy_selector(char *strat);
void		benchmarking(t_ops *ops, int strat, float disorder);

void		print_error(void);
char		*adp_printer(float disorder);
int			is_sorted(t_node *a);
void		is_duped(t_node *a);

long int	ft_so_long_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);

void		sa(t_node **a, t_ops *ops);
void		sb(t_node **b, t_ops *ops);
void		ss(t_node **a, t_node **b, t_ops *ops);

void		pa(t_node **a, t_node **b, t_ops *ops);
void		pb(t_node **b, t_node **a, t_ops *ops);

void		ra(t_node **a, t_ops *ops);
void		rb(t_node **b, t_ops *ops);
void		rr(t_node **a, t_node **b, t_ops *ops);

void		rra(t_node **a, t_ops *ops);
void		rrb(t_node **b, t_ops *ops);
void		rrr(t_node **a, t_node **b, t_ops *ops);

void		add_back(t_node **lst, t_node *new_node);
t_node		*new_lst(int value);
int			list_size(t_node *a);

char		*join_args(int argc, char **argv);
int			total_length(int argc, char **argv);
float		compute_disorder(t_node *a);
int			ft_sqrt(int n);

void		chunk_core_indexer(t_node *a);

void		navigation(t_node **a, int strat, t_ops *ops);
void		bubble_sorting(t_node **a, t_ops *ops);
void		chunk_sorting(t_node **a, t_node **b, t_ops *ops);
void		radix(t_node **a, t_node **b, t_ops *ops);

void		put_nbr_fd(int n, int fd);
void		put_float(float n, int fd);
char		*strat_name(int strat, float disorder);

int			five_or_less_control(t_node *a, t_ops *ops);
void		two_numbers(t_node *a, t_ops *ops);
void		three_numbers(t_node **a, t_ops *ops);
void		four_numbers(t_node **a, t_node **b, t_ops *ops);
void		five_numbers(t_node **a, t_node **b, t_ops *ops);

#endif
