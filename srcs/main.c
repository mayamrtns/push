/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:26 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 18:10:10 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_context(t_context *context)
{
	context->bench = 0;
	context->op_count = (t_op_count){0};
	context->stack_a = malloc(sizeof(t_stack));
	context->stack_b = malloc(sizeof(t_stack));
	if (!context->stack_a || !context->stack_b)
		return (0);
	init_stack(context->stack_a);
	init_stack(context->stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 2)
		return (0);
	if (!init_context(&context))
		return (1);
	parse_mode(argc, argv, &context);
	parse_args(argc, argv, &context);
	context.strategy_used = context.mode;
	context.disorder_result = compute_disorder(context.stack_a);
	index_stack(context.stack_a);
	if (context.stack_a->size > 1 && !is_sorted(context.stack_a))
		run_sort(&context.stack_a, &context.stack_b, &context);
	if (context.bench == 1)
		print_bench(&context);
	free_stack(context.stack_a);
	free_stack(context.stack_b);
	free(context.stack_a);
	free(context.stack_b);
	return (0);
}
