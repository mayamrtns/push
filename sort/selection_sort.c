/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:52:13 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/27 17:36:52 by araissa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selection_sort(t_context *context)
{
	int	size;

	if (!context->stack_a || !context->stack_a || !context->stack_a->top)
		return ;
	size = context->stack_a->size;
	push_chunk(context, 0, size - 1);
	push_back(&context->stack_a, &context->stack_b, context);
}
