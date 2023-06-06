/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:58:23 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/02 01:40:53 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_node **a, t_node **b, int which)
{
	t_node	*head;

	if (which == 1)
	{
		if (!(*a) || !(*a)->next)
			return ;
		head = (*a)->next;
		(*a)->next = ((*a)->next)->next;
		head->next = (*a);
		(*a) = head;
		ft_printf("sa\n");
	}
	else if (which == 2)
	{
		if (!(*b) || !(*b)->next)
			return ;
		head = (*b)->next;
		(*b)->next = ((*b)->next)->next;
		head->next = (*b);
		(*b) = head;
		ft_printf("sb\n");
	}
}
// which 1 : swap a;
// which 2 : swap b;

void	ft_push(t_node **a, t_node **b, int which)
{
	t_node	*head;

	if (which == 1)
	{
		if (!(*b))
			return ;
		head = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = head;
		ft_printf("pa\n");
	}
	else if (which == 2)
	{
		if (!(*a))
			return ;
		head = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = head;
		ft_printf("pb\n");
	}
}
//which 1 : push from b to a;
//which 2 : push from a to b;

void	ft_rotate(t_node **stack, char which)
{
	t_node	*head;
	t_node	*iter;

	if (!(*stack) || !(*stack)->next)
		return ;
	iter = (*stack);
	head = (*stack)->next;
	while (iter->next)
		iter = iter->next;
	iter->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = head;
	ft_printf("r%c\n", which);
}
//which 1 : rotate a;
//which 2 : rotate b;

void	ft_reverse(t_node **stack, char which)
{
	t_node	*iter;
	t_node	*tail;

	if (!(*stack) || !(*stack)->next)
		return ;
	iter = (*stack);
	while (iter->next->next)
		iter = iter->next;
	tail = iter->next;
	iter->next = NULL;
	tail->next = (*stack);
	(*stack) = tail;
	ft_printf("rr%c\n", which);
}
//which 1 : reverse a;
//which 2 : reverse b;
