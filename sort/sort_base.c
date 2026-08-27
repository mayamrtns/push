/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:39 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 19:09:42 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_context *context)
{
	t_node	*first;
	t_node	*second;

	if (!context->stack_a->top || !context->stack_a->top->next)
		return ;
	first = context->stack_a->top;
	second = first->next;
	if (first->value > second->value)
		sa(&context->stack_a, context);
}

void	sort_three(t_context *context)
{
	int	first;
	int	second;
	int	third;

	first = context->stack_a->top->value;
	second = context->stack_a->top->next->value;
	third = context->stack_a->top->next->next->value;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		sa(&context->stack_a, context);
		ra(&context->stack_a, context);
	}
	else if (second < first && first < third)
		sa(&context->stack_a, context);
	else if (second < third && third < first)
		ra(&context->stack_a, context);
	else if (third < first && first < second)
		rra(&context->stack_a, context);
	else if (third < second && second < first)
	{
		sa(&context->stack_a, context);
		rra(&context->stack_a, context);
	}
}

static int	find_min_position(t_stack *a)
{
	int		i;
	int		pos;
	int		min;
	t_node	*actual;

	if (!a || !a->top)
		return (0);
	actual = a->top;
	min = actual->value;
	pos = 0;
	i = 0;
	while (actual)
	{
		if (actual->value < min)
		{
			min = actual->value;
			pos = i;
		}
		i++;
		actual = actual->next;
	}
	return (pos);
}

static void	move_min_to_top(t_context *context)
{
	int	pos;

	pos = find_min_position(context->stack_a);
	while (pos != 0)
	{
		if (pos <= context->stack_a->size / 2)
			ra(&context->stack_a, context);
		else
			rra(&context->stack_a, context);
		pos = find_min_position(context->stack_a);
	}
}

void	sort_five(t_context *context)
{
	if (context->stack_a->size == 4)
	{
		move_min_to_top(context);
		pb(&context->stack_a, &context->stack_b, context);
		sort_three(context);
		pa(&context->stack_a, &context->stack_b, context);
	}
	else
	{
		move_min_to_top(context);
		pb(&context->stack_a, &context->stack_b, context);
		move_min_to_top(context);
		pb(&context->stack_a, &context->stack_b, context);
		sort_three(context);
		pa(&context->stack_a, &context->stack_b, context);
		pa(&context->stack_a, &context->stack_b, context);
	}
}
