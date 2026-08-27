/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:38:44 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/12 18:38:44 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack == NULL || *stack == NULL)
		return ;
	if ((*stack)->top == NULL || (*stack)->top->next == NULL)
		return ;
	first = (*stack)->top;
	second = first->next;
	third = second->next;
	if (third != NULL)
		third->prev = first;
	else
		(*stack)->bottom = first;
	first->next = third;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	(*stack)->top = second;
}

void	sa(t_stack **stack_a, t_context *context)
{
	ft_swap (stack_a);
	print_operations("sa", context);
}

void	sb(t_stack **stack_b, t_context *context)
{
	ft_swap(stack_b);
	print_operations("sb", context);
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_context *context)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	print_operations("ss", context);
}
