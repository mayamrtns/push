/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:22:14 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/21 19:39:59 by malima-m         ###   ########.fr       */
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
	return ((value >> position) & 1);
}

static void	sort_by_bit(t_stack **a, t_stack **b, int bit)
{
	int	total;

	total = (*a)->size; //guarda o tamanho original antes de comecar, se nao mudaria a cada pb
	while (total > 0) //percorre a stack A inteira exatamente uma vez
	{
		if (get_bit((*a)->top->index, bit) == 0)
			pb(a, b);
		else
			ra(a);
		total--;
	} //elementos com bit 0 vao pra B e elementos com bit 1 vao pra A
	while ((*b)->top)
		pa(a, b); //devolve tudo de B para A com pa
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;

	if (!a || !*a || !(*a)->top)
		return ;
	max_bits = get_max_bits(*a); //calcula quantos bits sao necessarios
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(a, b, bit); //roda uma vez para cada bit, do menos significativo ao mais significativo
		bit++;
	}
}//no fim, a  stack A esta ordenada
