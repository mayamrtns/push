/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:26 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/21 18:53:48 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Valida se há argumentos suficientes, chama a inicialização da pilha, dispara o parsing e faz a limpeza ao final.
#include "push_swap.h"


int	is_mode_flag(char *arg, t_mode *mode)
{
	if (strncmp(arg, "--simple", 9) == 0)
		*mode = SIMPLE;
	else if (strncmp(arg, "--medium", 9) == 0)
		*mode = MEDIUM;
	else if (strncmp(arg, "--complex", 10) == 0)
		*mode = COMPLEX;
	else if (strncmp(arg, "--adaptive", 11) == 0)
		*mode = ADAPTIVE;
	else if (strncmp(arg, "--", 2) == 0)
		return (-1);
	else
		return (0);
	return (1);
}

static void	parse_mode(int argc, char **argv, t_mode *mode, t_stack	*stack_a, t_stack *stack_b)
{
	int	i;
	int	flag_count;
	int	result;

	*mode = ADAPTIVE;
	flag_count = 0;
	i = 1;
	while (i < argc)
	{
		result = is_mode_flag(argv[i], mode);
		if (result == -1)
			print_error(stack_a, stack_b);
		if (result == 1)
			flag_count++;
		i++;
	}
	if (flag_count > 1)
		print_error(stack_a, stack_b);
}

static void	run_sort(t_stack **stack_a, t_stack **stack_b, t_mode mode)
{
	if ((*stack_a)->size == 2)
		sort_two(stack_a);
	else if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else if (mode == SIMPLE)
		ft_selection_sort(stack_a, stack_b);
	else if (mode == MEDIUM)
		chunk_sort(stack_a, stack_b, get_chunk_size((*stack_a)->size));
	else if (mode == COMPLEX)
		radix_sort(stack_a, stack_b);
	else
		adaptive_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_mode	mode;

	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	init_stack(stack_a);
	init_stack(stack_b);
	parse_mode(argc, argv, &mode, stack_a, stack_b);
	parse_args(argc, argv, stack_a, stack_b);
	index_stack(stack_a);
	if (stack_a->size > 1 && !is_sorted(stack_a))
		run_sort(&stack_a, &stack_b, mode);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

// 	sort_two(&stack_a);
	// else if (stack_a->size == 3)
	// 	sort_three(&stack_a);
	// else if (stack_a->size <= 5)
	//	sort_five(&stack_a, &stack_b);
	// else
	// 	chunk_sort(&stack_a, &stack_b, get_chunk_size(stack_a->size));