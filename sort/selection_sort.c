/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:52:13 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 18:51:40 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selection_sort(t_context *context)
{
	int	size;

	if (!context->stack_a || !context->stack_a->top)
		return ;
	if (handle_small_sort(context, SIMPLE))
		return ;
	size = context->stack_a->size;
	push_chunk(context, 0, size - 1);
	push_back(&context->stack_a, &context->stack_b, context);
	context->strategy_used = SIMPLE;
}
