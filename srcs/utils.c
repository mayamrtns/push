/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:48 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/12 19:02:49 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concentra utilitários genéricos: is_number e exibição de erros no stderr.
#include "push_swap.h"



int	is_number(char *str)
{
	int	i;

	i = 0;
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

static	t_op_count count = {0};

void	print_operations(char *name_op)
{
	ft_putendl_fd(name_op,1);
	if (ft_strncmp(name_op, "sa", 3) == 0)
		count.sa++;
	else if (ft_strncmp(name_op, "sb", 3) == 0)
		count.sb++;
	else if (ft_strncmp(name_op, "ss", 3) == 0)
		count.ss++;
	else if (ft_strncmp(name_op, "pa", 3) == 0)
		count.pa++;
	else if (ft_strncmp(name_op, "pb", 3) == 0)
		count.pb++;
	else if (ft_strncmp(name_op, "ra", 3) == 0)
		count.ra++;
	else if (ft_strncmp(name_op, "rb", 3) == 0)
		count.rb++;
	else if (ft_strncmp(name_op, "rr", 3) == 0)
		count.rr++;
	else if (ft_strncmp(name_op, "rra", 4) == 0)
		count.rra++;
	else if (ft_strncmp(name_op, "rrb", 4) == 0)
		count.rrb++;
	else if (ft_strncmp(name_op, "rrr", 4) == 0)
		count.rrr++;
}

t_op_count get_op_count(void)
{
	return (count);
}
