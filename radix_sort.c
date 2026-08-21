/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:22:14 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/21 17:45:02 by malima-m         ###   ########.fr       */
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

int get_bit(int value, int position)
{
	return ((value >> position) & 1)
}

radix_sort(t_stack **a, t_stack **b)
{

}
