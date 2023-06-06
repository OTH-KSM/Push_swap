/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:06:05 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/01 12:28:37 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_initialize(t_node **a, t_node **b, t_elem *elem, int *lst_size)
{
	if (elem->which == 1)
	{
		elem->iter = (*a);
		elem->i = 0;
		elem->j = 0;
		elem->size = *lst_size;
		elem->offset = ft_make_offset(*lst_size);
		elem->arr = ft_class_node_in_arr(a, &elem->arr, *lst_size);
		elem->midd = (*lst_size / 2) - 1;
		elem->l_midd = elem->midd - (elem->offset);
		elem->r_midd = elem->midd + (elem->offset);
	}
	else if (elem->which == 2)
	{
		*lst_size = elem->size - 1;
		elem->max = elem->arr[*lst_size];
		elem->j = 0;
		elem->i = 0;
		elem->tl = NULL;
		elem->iter = (*b);
	}
}

void	ft_from_a_to_b(t_node **a, t_node **b, t_elem *elem, int *lst_size)
{
	while (elem->i < *lst_size)
	{
		if (elem->iter->cont >= elem->arr[elem->l_midd]
			&& elem->iter->cont <= elem->arr[elem->midd])
		{
			ft_push(a, b, 2);
			ft_rotate(b, 'b');
			elem->j++;
		}
		else if (elem->iter->cont > elem->arr[elem->midd]
			&& elem->iter->cont <= elem->arr[elem->r_midd])
		{
			ft_push(a, b, 2);
			elem->j++;
		}
		else
			ft_rotate(a, 'a');
		elem->i++;
		elem->iter = (*a);
	}		
	elem->i = 0;
	*lst_size = *lst_size - elem->j;
	elem->j = 0;
	elem->l_midd = elem->l_midd - (elem->offset);
	elem->r_midd = elem->r_midd + (elem->offset);
}

void	ft_from_b_to_a(t_node **a, t_node **b, t_elem *elem, int *lst_size)
{
	if (ft_find(b, elem->max) == 1)
		ft_push_it_to_a(a, b, elem, lst_size);
	else
		ft_just_reverse(a, elem, lst_size);
}

void	ft_sort_big(t_node **a, t_node **b, int lst_size)
{
	t_elem	elem;

	elem.which = 1;
	ft_initialize(a, b, &elem, &lst_size);
	while ((*a))
	{
		ft_from_a_to_b(a, b, &elem, &lst_size);
		if (elem.r_midd > elem.size)
			elem.r_midd = elem.size - 1;
		if (elem.l_midd < 0)
			elem.l_midd = 0;
	}
	elem.which = 2;
	ft_initialize(a, b, &elem, &lst_size);
	while ((*b))
	{
		ft_from_b_to_a(a, b, &elem, &lst_size);
		elem.iter = (*b);
	}
	while (elem.j)
	{
		ft_reverse(a, 'a');
		elem.j--;
	}
	free(elem.arr);
}
