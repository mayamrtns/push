/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:26 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/20 18:20:13 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Valida se há argumentos suficientes, chama a inicialização da pilha, dispara o parsing e faz a limpeza ao final.
#include "push_swap.h"

	t_stack	*stack_a;
	t_stack	*stack_b;

	int main(int argc, char **argv)
	{
	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	init_stack(stack_a);          // t_stack*, sem &, porque stack_a já É o ponteiro
	init_stack(stack_b);
	parse_args(argc, argv, stack_a);
	index_stack(stack_a);
	if (stack_a->size == 2)
		sort_two(&stack_a);        // t_stack**, AGORA com &, porque essas pedem ponteiro-pro-ponteiro
	else if (stack_a->size == 3)
		sort_three(&stack_a);
	// else if (stack_a->size <= 5)
	// 	sort_five(&stack_a, &stack_b);
	else
		chunk_sort(&stack_a, &stack_b, get_chunk_size(stack_a->size)); 
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
	}
