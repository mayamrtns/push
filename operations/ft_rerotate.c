/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rerotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:38:28 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/12 18:38:28 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_rerotate(t_stack **stack)
{
	t_node *aux;
	t_node	*last;

	if (!stack || !(*stack)->top || !(*stack)->top->next)
		return;
	aux = (*stack)->bottom->prev;
	last = (*stack)->bottom;
	last->next = (*stack)->top;
	(*stack)->top->prev = last;
	aux->next = NULL;
	last->prev = NULL;
	(*stack)->top = last;
	(*stack)->bottom = aux;
}

void	rra(t_stack **stack_a, t_context *context)

{
	ft_rerotate(stack_a);
	//write(1, "rra\n", 4);
	print_operations("rra", context);
}

void	rrb(t_stack **stack_b, t_context *context)

{
	ft_rerotate(stack_b);
	//write(1, "rrb\n", 4);
	print_operations("rrb", context);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_context *context)

{
	ft_rerotate(stack_a);
	ft_rerotate(stack_b);
	//write(1, "rrr\n", 4);
	print_operations("rrr", context);
}