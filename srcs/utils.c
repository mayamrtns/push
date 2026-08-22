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
