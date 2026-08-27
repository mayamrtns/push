/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:34 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 17:50:06 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_node *top, int number)
{
	t_node	*current;

	current = top;
	while (current != NULL)
	{
		if (current->value == number)
			return (1);
		else
			current = current->next;
	}
	return (0);
}

static void	process_number(char *arg, t_context *context)
{
	long	value;
	t_node	*new_node;

	if (!is_number(arg))
		print_error(context->stack_a, context->stack_b);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		print_error(context->stack_a, context->stack_b);
	if (has_duplicate(context->stack_a->top, (int)value))
		print_error(context->stack_a, context->stack_b);
	new_node = create_node((int)value);
	if (!new_node)
		print_error(context->stack_a, context->stack_b);
	add_node_back(context->stack_a, new_node);
}

void	parse_args(int argc, char **argv, t_context *context)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (is_mode_flag(argv[i], context) == 0)
			process_number(argv[i], context);
		i++;
	}
}
