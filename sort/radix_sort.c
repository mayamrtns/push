/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:22:14 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 17:47:07 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack_a)
{
	int	max_index;
	int	max_bits;

	if (!stack_a || !stack_a->top)
		return (0);
	max_index = stack_a->size -1;
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

static void	sort_by_bit(t_stack **a, t_stack **b, int bit, t_context *context)
{
	int	total;

	total = (*a)->size;
	while (total > 0)
	{
		if (get_bit((*a)->top->index, bit) == 0)
			pb(a, b, context);
		else
			ra(a, context);
		total--;
	}
	while ((*b)->top)
		pa(a, b, context);
}

void	radix_sort(t_stack **a, t_stack **b, t_context *context)
{
	int	max_bits;
	int	bit;

	if (!a || !*a || !(*a)->top)
		return ;
	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(a, b, bit, context);
		bit++;
	}
}
