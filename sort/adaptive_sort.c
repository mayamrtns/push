/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:17:18 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 17:40:02 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **stack_a, t_stack **stack_b, t_context *context)
{
	double	stack_disorder;

	if (!stack_a || !*stack_a || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	stack_disorder = context->disorder_result;
	if (stack_disorder < 0.2)
	{
		ft_selection_sort(context);
		context->strategy_used = SIMPLE;
	}
	else if (stack_disorder < 0.5)
	{
		chunk_sort(context, get_chunk_size(context->stack_a->size));
		context->strategy_used = MEDIUM;
	}
	else
	{
		radix_sort(stack_a, stack_b, context);
		context->strategy_used = COMPLEX;
	}
}
