/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:05:13 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/07 20:06:19 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
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

//utils.c

int	is_number(char *str);
void	print_error(t_stack *stack);


//parsing.c
int	has_duplicate(t_node *top, int number);
void	parse_args(int argc, char **argv, t_stack *stack);

//stack_utils.c
void	init_stack(t_stack *stack);
t_node *create_node(int value);
void	add_node_back(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);


#endif