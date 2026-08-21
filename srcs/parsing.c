/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:34 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/20 20:38:38 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Garante que a entrada não possui duplicatas, trata múltiplos argumentos e orquestra a conversão de texto para nó.
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

static void	process_number(char *arg, t_stack *stack)
{
	long	value;
	t_node	*new_node;

	if (!is_number(arg))
		print_error(stack);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		print_error(stack);
	if (has_duplicate(stack->top, (int)value))
		print_error(stack);
	new_node = create_node((int)value);
	if (!new_node)
		print_error(stack);
	add_node_back(stack, new_node);
}

void	parse_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	t_mode	mode;

	i = 1;
	while (i < argc)
	{
		if (is_mode_flag(argv[i], &mode) == 0)
			process_number(argv[i], stack);
		i++;
	}
}
