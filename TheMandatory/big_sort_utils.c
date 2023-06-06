/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:53:49 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/01 12:55:58 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_locate(t_node **b, int tl)
{
	t_node	*iter;
	int		i;

	iter = *b;
	i = 0;
	if (!(*b))
		return (0);
	while (iter)
	{
		if (iter->cont == tl)
			break ;
		i++;
		iter = iter->next;
	}
	return (i);
}

int	ft_find(t_node **b, int max)
{
	t_node	*iter;

	iter = (*b);
	if (!(*b))
		return (0);
	while (iter)
	{
		if (iter->cont == max)
			return (1);
		iter = iter->next;
	}
	return (0);
}

void	ft_do_this(t_node **b, int lst_size, int max)
{
	int	i;

	i = ft_locate(b, max);
	if (i > lst_size)
		ft_reverse(b, 'b');
	else
		ft_rotate(b, 'b');
}

void	ft_fill_arr(t_elem *elem, int *arr, int lst_size)
{
	while (elem->i < lst_size)
	{
		arr[elem->i] = elem->iter->cont;
		(elem->i)++;
		elem->iter = elem->iter->next;
	}
	elem->i = lst_size - 1;
	elem->j = lst_size - 1;
}

int	*ft_class_node_in_arr(t_node **a, int **arr, int lst_size)
{
	t_elem	elem;

	elem.iter = (*a);
	elem.i = 0;
	(*arr) = ft_calloc((lst_size + 1), sizeof(int));
	if (!(*arr))
		exit (0);
	ft_fill_arr(&elem, *arr, lst_size);
	while (elem.i > 0)
	{
		while (elem.j > 0)
		{
			if ((*arr)[elem.j] < (*arr)[elem.j - 1])
			{
				elem.size = (*arr)[elem.j - 1];
				(*arr)[elem.j - 1] = (*arr)[elem.j];
				(*arr)[elem.j] = elem.size;
			}
			else
				elem.j--;
		}
		elem.j = lst_size - 1;
		elem.i--;
	}
	return (*arr);
}
