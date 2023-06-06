/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_double_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 05:48:13 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/01 06:39:06 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_both_for_checker(t_node **a, t_node **b)
{
	ft_swap_for_checker(a, b, 1);
	ft_swap_for_checker(a, b, 2);
}

void	ft_rotate_both_for_checker(t_node **a, t_node **b)
{
	ft_rotate_for_checker(a);
	ft_rotate_for_checker(b);
}

void	ft_reverse_both_for_checker(t_node **a, t_node **b)
{
	ft_reverse_for_checker(a);
	ft_reverse_for_checker(b);
}
