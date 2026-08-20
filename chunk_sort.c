/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:19:20 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/18 17:39:40 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
	int	total;

	total = (*stack_a)->size;
	while (total > 0)
	{
		if ((*stack_a)->top->index >= low && (*stack_a)->top->index <= high)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		total--;
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	num_chunks;
	int	low;
	int	high;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return ;
	num_chunks = ((*stack_a)->size + chunk_size - 1) / chunk_size;
	c = num_chunks - 1;
	while (c >= 0)
	{
		low = c * chunk_size;
		high = low + chunk_size - 1;
		push_chunk(stack_a, stack_b, low, high);
		push_back(stack_a, stack_b);
		c--;
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
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
			rb(stack_b);
		}
		else
		{
			while ((*stack_b)->top != big)
			rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

t_node	*find_big(t_stack *stack_b)
{
	t_node	*big;
	t_node	*tmp;

	if (!stack_b || !stack_b->top)
		return (NULL); //TEM que ter o NULL pelo retorno ser t_node
	big = stack_b->top;
	tmp = stack_b->top;

	while (tmp) //enquanto tmp existe
	{
		if (tmp->index > big->index) //se o index da variavel tmp for maior que a da big, big recebe o valor de tmp e tmp segue para o próximo nó
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

int	get_position(t_node *top, t_node *target)
{
	int	k;

	if (!top || !target)
		return (-1);
	k = 0;
	while (top && top != target) //verificando se é nulo antes de ser igual a target
	{
		k++;
		top = top->next;
	}
	return (k);
}
