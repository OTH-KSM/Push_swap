/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 05:46:19 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/02 01:41:03 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_for_checker(t_node **a, t_node **b, int which)
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
	}
	else if (which == 2)
	{
		if (!(*b) || !(*b)->next)
			return ;
		head = (*b)->next;
		(*b)->next = ((*b)->next)->next;
		head->next = (*b);
		(*b) = head;
	}
}
// which 1 : swap a;
// which 2 : swap b;

void	ft_push_for_checker(t_node **a, t_node **b, int which)
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
	}
	else if (which == 2)
	{
		if (!(*a))
			return ;
		head = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = head;
	}
}
//which 1 : push from b to a;
//which 2 : push from a to b;

void	ft_rotate_for_checker(t_node **stack)
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
}

void	ft_reverse_for_checker(t_node **stack)
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
}
