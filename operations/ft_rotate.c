/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:38:39 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 18:22:11 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack)->top || !(*stack)->top->next)
		return ;
	first = (*stack)->top;
	last = (*stack)->bottom;
	(*stack)->top = first->next;
	(*stack)->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*stack)->bottom = first;
}

void	ra(t_stack **stack_a, t_context *context)
{
	ft_rotate(stack_a);
	print_operations("ra", context);
}

void	rb(t_stack **stack_b, t_context *context)
{
	ft_rotate(stack_b);
	print_operations("rb", context);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_context *context)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	print_operations("rr", context);
}
