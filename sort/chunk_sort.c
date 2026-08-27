/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:19:20 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 17:22:29 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_context *context, int low, int high)
{
	int	total;

	total = context->stack_a->size;
	while (total > 0)
	{
		if (context->stack_a->top->index >= low
			&& context->stack_a->top->index <= high)
			pb(&context->stack_a, &context->stack_b, context);
		else
			ra(&context->stack_a, context);
		total--;
	}
}

void	chunk_sort(t_context *context, int chunk_size)
{
	int	num_chunks;
	int	low;
	int	high;
	int	c;

	if (!context->stack_a || !context->stack_a || !context->stack_a->top)
		return ;
	num_chunks = (context->stack_a->size + chunk_size - 1) / chunk_size;
	c = num_chunks - 1;
	while (c >= 0)
	{
		low = c * chunk_size;
		high = low + chunk_size - 1;
		push_chunk(context, low, high);
		push_back(&context->stack_a, &context->stack_b, context);
		c--;
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b, t_context *context)
{
	int		k;
	int		size;
	t_node	*big;

	if (!stack_b || !*stack_b || !(*stack_b)->top)
		return ;
	while ((*stack_b)->top)
	{
		big = find_big(*stack_b);
		size = (*stack_b)->size;
		k = get_position((*stack_b)->top, big);
		if (k <= size / 2)
		{
			while ((*stack_b)->top != big)
				rb(stack_b, context);
		}
		else
		{
			while ((*stack_b)->top != big)
				rrb(stack_b, context);
		}
		pa(stack_a, stack_b, context);
	}
}

int	get_chunk_size(int size)
{
	int	i;

	i = 0;
	while (i * i < size)
	{
		i++;
	}
	return (i * 2);
}
