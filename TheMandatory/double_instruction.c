/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:47:30 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/01 06:25:33 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_both(t_node **a, t_node **b)
{
	ft_swap(a, b, 1);
	ft_swap(a, b, 2);
}

void	ft_rotate_both(t_node **a, t_node **b)
{
	ft_rotate(a, 'a');
	ft_rotate(b, 'b');
}

void	ft_reverse_both(t_node **a, t_node **b)
{
	ft_reverse(a, 'a');
	ft_reverse(b, 'b');
}
