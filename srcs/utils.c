/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:48 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 16:54:34 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concentra utilitários genéricos: is_number e exibição de erros no stderr.
#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i]>= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		free_stack(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		free_stack(stack_b);
		free(stack_b);
	}
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	print_operations(char *name_op, t_context *context)
{
	ft_putendl_fd(name_op, 1);
	if (ft_strncmp(name_op, "sa", 3) == 0)
		context->op_count.sa++;
	else if (ft_strncmp(name_op, "sb", 3) == 0)
		context->op_count.sb++;
	else if (ft_strncmp(name_op, "ss", 3) == 0)
		context->op_count.ss++;
	else if (ft_strncmp(name_op, "pa", 3) == 0)
		context->op_count.pa++;
	else if (ft_strncmp(name_op, "pb", 3) == 0)
		context->op_count.pb++;
	else if (ft_strncmp(name_op, "ra", 3) == 0)
		context->op_count.ra++;
	else if (ft_strncmp(name_op, "rb", 3) == 0)
		context->op_count.rb++;
	else if (ft_strncmp(name_op, "rr", 3) == 0)
		context->op_count.rr++;
	else if (ft_strncmp(name_op, "rra", 4) == 0)
		context->op_count.rra++;
	else if (ft_strncmp(name_op, "rrb", 4) == 0)
		context->op_count.rrb++;
	else if (ft_strncmp(name_op, "rrr", 4) == 0)
		context->op_count.rrr++;
}
