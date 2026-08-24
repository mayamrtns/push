/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:26 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/24 15:53:18 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Valida se há argumentos suficientes, chama a inicialização da pilha, dispara o parsing e faz a limpeza ao final.
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

static void	parse_mode(int argc, char **argv, t_context *context)
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

static void	run_sort(t_stack **stack_a, t_stack **stack_b, t_context *context)
{
	if ((*stack_a)->size == 2)
		sort_two(stack_a);
	else if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else if (context->mode == SIMPLE)
	{
		ft_selection_sort(stack_a, stack_b);
		context->strategy_used = SIMPLE;
	}
	else if (context->mode == MEDIUM)
	{
		chunk_sort(stack_a, stack_b, get_chunk_size((*stack_a)->size));
		context->strategy_used = MEDIUM;
	}
	else if (context->mode == COMPLEX)
	{
		radix_sort(stack_a, stack_b);
		context->strategy_used = COMPLEX;
	}
	else
	{
		adaptive_sort(stack_a, stack_b, context);
	}
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 2)
		return (0);
	context.bench = 0;
	context.stack_a = malloc(sizeof(t_stack));
	context.stack_b = malloc(sizeof(t_stack));
	if (!context.stack_a || !context.stack_b)
		return (1);
	init_stack(context.stack_a);
	init_stack(context.stack_b);
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

