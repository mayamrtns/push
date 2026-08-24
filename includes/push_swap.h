/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:05:13 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/21 19:32:32 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <string.h>
#include <stdio.h> //remover posteriormente
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

typedef struct s_op_count
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
}    t_op_count;

typedef struct s_context
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_mode	mode;
	int		bench;
	double	disorder_result;
	t_mode strategy_used;
}	t_context;

//srcs/utils.c
int	is_number(char *str);
void	print_error(t_stack *stack_a, t_stack *stack_b);
void	print_operations(char *name_op);
t_op_count get_op_count(void);
//srcs/parsing.c
int	has_duplicate(t_node *top, int number);
void	parse_args(int argc, char **argv, t_context *context);
//srcs/stack_utils.c
void	init_stack(t_stack *stack);
t_node *create_node(int value);
void	add_node_back(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);
//srcs/analysis.c
double	compute_disorder ( t_stack *stack_a);
void	index_stack(t_stack *stack_a);
int	is_sorted(t_stack *stack);
//srcs/sort_base.c
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
//operations/ft_rerotate.c
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
//operations/ft_rotate.c
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
//operations/ft_swap.c
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
//operations/ft_push.c
void	ft_push(t_stack **src, t_stack **dst);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//sort/selection_sort.c
void	ft_selection_sort(t_stack **stack_a, t_stack **stack_b);
//sort/chunk_sort.c
void	push_chunk(t_stack **stack_a, t_stack **stack_b, int low, int high);
void	push_back(t_stack **stack_a, t_stack **stack_b);
int		get_chunk_size(int size);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int chunk_size);
//sort/chunk_utils.c
t_node	*find_big(t_stack *stack_b);
int		get_position(t_node *top, t_node *target);
//sort/radix_sort.c
int		get_max_bits(t_stack *stack_a);
int get_bit(int value, int position);
void	radix_sort(t_stack **a, t_stack **b);
//sort/adaptative_sort.c
void	adaptive_sort(t_stack **stack_a, t_stack **stack_b,  t_context *context);
//srcs/main.c
int	is_mode_flag(char *arg, t_context *context);
//src/bench_utils.c
char *convert_disorder (double disorder);
//srcs/bench_print.c 
void print_bench(t_context *context);

#endif