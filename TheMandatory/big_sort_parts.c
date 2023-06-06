/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:54:51 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/01 06:25:12 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_make_offset(int lst_size)
{
	int	offset;

	if (lst_size < 11)
		offset = 2;
	else if (lst_size < 151)
		offset = 11;
	else
		offset = 32;
	return (offset);
}

void	ft_push_it_to_a(t_node **a, t_node **b, t_elem *elem, int *lst_size)
{
	if (!(*a) || elem->iter->cont == elem->max)
	{
		if (elem->iter->cont == elem->max)
			elem->max = elem->arr[--(*lst_size)];
		else
		{
			elem->tl = elem->iter;
			elem->j++;
		}
		ft_push(a, b, 1);
		elem->size--;
	}
	else
	{
		if (elem->j == 0 || (elem->j != 0 && elem->iter->cont > elem->tl->cont))
		{
			ft_push(a, b, 1);
			ft_rotate(a, 'a');
			elem->tl = elem->iter;
			elem->j++;
			elem->size--;
		}
		else
			ft_do_this(b, (elem->size) / 2, elem->max);
	}
}

void	ft_just_reverse(t_node **a, t_elem *elem, int *lst_size)
{
	ft_reverse(a, 'a');
	elem->max = elem->arr[--(*lst_size)];
	elem->j--;
	if (elem->j < 0)
		elem->j = 0;
}
