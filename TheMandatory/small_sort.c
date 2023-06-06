/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:58:50 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/01 06:25:46 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_help(t_node **a, t_node **stack, int *i, int lst_size)
{
	if ((*stack)->index == 0)
		(*i)++;
	else if ((*stack)->index <= (lst_size / 2))
	{
		while ((*stack)->index != 0)
		{
			ft_rotate(a, 'a');
			((*stack)->index)--;
		}
	}
	else if ((*stack)->index > (lst_size / 2))
	{
		while ((*stack)->index < lst_size)
		{
			ft_reverse(a, 'a');
			((*stack)->index)++;
		}
	}
}

void	ft_sort_two(t_node **a, t_node **b)
{
	if (!(*a))
		return ;
	if ((*a)->cont > ((*a)->next)->cont)
		ft_swap(a, b, 1);
}

void	ft_sort_three(t_node **a, t_node **b)
{
	if (!(*a))
		return ;
	if (((*a)->cont > ((*a)->next)->cont)
		&& (*a)->cont > (((*a)->next)->next)->cont)
		ft_rotate(a, 'a');
	else if (((*a)->next)->cont > ((*a)->cont)
		&& ((*a)->next)->cont > ((((*a)->next)->next))->cont)
		ft_reverse(a, 'a');
	ft_sort_two(a, b);
}

void	ft_sort_for(t_node **a, t_node **b, int lst_size)
{
	t_node	*iter;
	t_node	*rem;
	int		i;

	iter = (*a);
	rem = (*a);
	i = 0;
	rem->index = 0;
	while (i < lst_size)
	{
		if (iter->cont < rem->cont)
		{
			rem = iter;
			rem->index = i;
		}
		iter = iter->next;
		i++;
	}
	ft_help(a, &rem, &i, lst_size);
	ft_push(a, b, 2);
	ft_sort_three(a, b);
	ft_push(a, b, 1);
}

void	ft_sort_five(t_node **a, t_node **b, int lst_size)
{
	t_node	*iter;
	t_node	*rem;
	int		i;

	iter = (*a);
	rem = (*a);
	i = 0;
	rem->index = 0;
	while (i < lst_size)
	{
		if (iter->cont < rem->cont)
		{
			rem = iter;
			rem->index = i;
		}
		iter = iter->next;
		i++;
	}
	ft_help(a, &rem, &i, lst_size);
	ft_push(a, b, 2);
	lst_size--;
	ft_sort_for(a, b, lst_size);
	ft_push(a, b, 1);
}
