/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:17:18 by araissa-          #+#    #+#             */
/*   Updated: 2026/08/27 19:14:10 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_context *context)
{
	double	stack_disorder;

	if (!context->stack_a || !context->stack_a->top
		|| !context->stack_a->top->next)
		return ;
	if (handle_small_sort(context, ADAPTIVE))
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
		radix_sort(context);
		context->strategy_used = COMPLEX;
	}
}
