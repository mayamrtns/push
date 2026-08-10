#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_node	*tmp;

	if (!src || !(*src)->top)
		return;
		//nada deve ser feito
		//protege o programa de segfault
	//se a pilha de origem estiver vazia, não há o que mover
	tmp = (*src)->top;
	//guarda o topo da stack de origem
	(*src)->top = tmp->next;
	//atualiza o topo da origem para o nó seguinte
	if ((*src)->top)
		(*src)->top->prev = NULL;
		//se sobrou alguém, ele é o novo topo e não tem prev
	else
		(*src)->bottom = NULL;
		//se a origem ficou vazia, bottom também precisa ficar nulo
	tmp->next = (*dst)->top;
	//conecta o next do tmp ao antigo topo da stack de destino
	tmp->prev = NULL;
	//tmp vai virar o novo topo, então não tem ninguém antes dele
	if ((*dst)->top)
		(*dst)->top->prev = tmp;
		//se já tinha alguém no destino, ele passa a apontar de volta pro tmp
	else
		(*dst)->bottom = tmp;
		//se o destino estava vazio, tmp é o único nó: topo e fundo ao mesmo tempo
	(*dst)->top = tmp;
	//atualiza o topo da stack de destino
	(*src)->size--;
	//origem perdeu um nó
	(*dst)->size++;
	//destino ganhou um nó
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}