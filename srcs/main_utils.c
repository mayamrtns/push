/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:09:46 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 19:14:07 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_mode_flag(char *arg, t_context *context)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		context->mode = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		context->mode = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		context->mode = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		context->mode = ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		context->bench = 1;
		return (2);
	}
	else if (ft_strncmp(arg, "--", 2) == 0)
		return (-1);
	else
		return (0);
	return (1);
}

void	parse_mode(int argc, char **argv, t_context *context)
{
	int	i;
	int	flag_count;
	int	result;

	context->mode = ADAPTIVE;
	flag_count = 0;
	i = 1;
	while (i < argc)
	{
		result = is_mode_flag(argv[i], context);
		if (result == -1)
			print_error(context->stack_a, context->stack_b);
		if (result == 1)
			flag_count++;
		i++;
	}
	if (flag_count > 1)
		print_error(context->stack_a, context->stack_b);
}

void	run_sort(t_context *context)
{
	if (context->mode == SIMPLE)
		ft_selection_sort(context);
	else if (context->mode == MEDIUM)
		chunk_sort(context, get_chunk_size(context->stack_a->size));
	else if (context->mode == COMPLEX)
		radix_sort(context);
	else
		adaptive_sort(context);
}
