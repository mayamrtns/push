/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_strategy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:02:16 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 18:05:51 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strategy_adaptive(t_context *context)
{
	if (context->mode == ADAPTIVE)
	{
		if (context->strategy_used == SIMPLE)
			return ("Adaptive / (O(n²)");
		if (context->strategy_used == MEDIUM)
			return ("Adaptive / O(n√n)");
		if (context->strategy_used == COMPLEX)
			return ("Adaptive / O(n log n)");
	}
	return (NULL);
}

char	*strategy_name(t_context *context)
{
	if (context->mode == SIMPLE)
		return ("Simple / (O(n²)");
	if (context->mode == MEDIUM)
		return ("Medium /  O(n√n)");
	if (context->mode == COMPLEX)
		return ("Complex / O(n log n)");
	return (strategy_adaptive(context));
}

void	print_strategy(t_context *context, int fd)
{
	char	*str_strategy;

	str_strategy = strategy_name(context);
	ft_putstr_fd("[bench] strategy: ", fd);
	ft_putstr_fd(str_strategy, fd);
	ft_putstr_fd("\n", fd);
}
