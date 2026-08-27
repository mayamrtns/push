/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:07:15 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 18:05:32 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_context *context, int fd)
{
	char	*str_disorder;

	str_disorder = convert_disorder(context->disorder_result);
	if (!str_disorder)
		return ;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putstr_fd(str_disorder, fd);
	ft_putstr_fd("%", fd);
	ft_putstr_fd("\n", fd);
	free(str_disorder);
}

static void	print_op(char *label, int value, int fd)
{
	char	*str;

	str = ft_itoa(value);
	if (!str)
		return ;
	ft_putstr_fd(label, fd);
	ft_putstr_fd(str, fd);
	free(str);
}

static void	print_total_ops(t_op_count count, int fd)
{
	int		total_op;
	char	*total;

	total_op = count.sa + count.sb + count.ss + count.pa + count.pb
		+ count.ra + count.rb + count.rr + count.rra + count.rrb + count.rrr;
	total = ft_itoa(total_op);
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putstr_fd(total, fd);
	ft_putstr_fd("\n", fd);
	free(total);
}

void	print_bench(t_context *context)
{
	t_op_count	count;

	count = context->op_count;
	print_disorder(context, 2);
	print_strategy(context, 2);
	print_total_ops(count, 2);
	ft_putstr_fd("[bench] ", 2);
	print_op("sa: ", count.sa, 2);
	print_op(" sb: ", count.sb, 2);
	print_op(" ss: ", count.ss, 2);
	print_op(" pa: ", count.pa, 2);
	print_op(" pb: ", count.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	print_op("ra: ", count.ra, 2);
	print_op(" rb: ", count.rb, 2);
	print_op(" rr: ", count.rr, 2);
	print_op(" rra: ", count.rra, 2);
	print_op(" rrb: ", count.rrb, 2);
	print_op(" rrr: ", count.rrr, 2);
	ft_putstr_fd("\n", 2);
}
