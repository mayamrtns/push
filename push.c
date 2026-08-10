void    ft_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src || !*src)
		return;
        //nada deve ser feito
		//protege o programa de segfault
    //se a pilha de origem só tiver um nó, ela deve ficar nula após a remoção
	tmp = *src;
	//guarda o topo da stack de origem
	*src = tmp->next;
	//atualiza o topo da origem para o nó seguinte
	tmp->next = *dst;
	//conecta o next de temp ao antigo topo da stack de destino
	*dst = tmp;
	//atualiza o topo da stack de destino
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