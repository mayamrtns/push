/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malima-m <malima-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:02:43 by malima-m          #+#    #+#             */
/*   Updated: 2026/08/20 16:18:19 by malima-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contém funções de alocação como init_stack, create_node, add_node_back e a desalocação free_stack.
#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
	stack->bottom = NULL;
}

t_node *create_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node_back(t_stack *stack, t_node *new_node)
{
	t_node *last;

	if(!stack || !new_node)
		return ;
	if (!stack->top)
		stack->top = new_node;
	else
	{
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	}
	stack->bottom = new_node;
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack->top = NULL;
	stack->size = 0;
	stack->bottom = 0;
}
