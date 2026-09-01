/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:22:14 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 19:11:10 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack_a)
{
	int	max_index;
	int	max_bits;

	if (!stack_a || !stack_a->top)
		return (0);
	max_index = stack_a->size - 1;
	max_bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		max_bits++;
	}
	return (max_bits);
}

int	get_bit(int value, int position)
{
	return ((value >> position) & 1);
}

static void	sort_by_bit(t_context *context, int bit)
{
	int	total;

	total = context->stack_a->size;
	while (total > 0)
	{
		if (get_bit(context->stack_a->top->index, bit) == 0)
			pb(&context->stack_a, &context->stack_b, context);
		else
			ra(&context->stack_a, context);
		total--;
	}
	while (context->stack_b->top)
		pa(&context->stack_a, &context->stack_b, context);
}

void	radix_sort(t_context *context)
{
	int	max_bits;
	int	bit;

	if (!context->stack_a || !context->stack_a->top)
		return ;
	if (handle_small_sort(context, COMPLEX))
		return ;
	max_bits = get_max_bits(context->stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(context, bit);
		bit++;
	}
	context->strategy_used = COMPLEX;
}