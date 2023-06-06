/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:45:49 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/06 00:21:41 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_sorted(t_node *s)
{
	while (s && s->next)
	{
		if (s->cont > s->next->cont)
			return (0);
		s = s->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count_node;

	count_node = 0;
	if (argc < 2)
		return (0);
	stack_a = ft_check_args(argv, &stack_a, &count_node);
	if (!ft_check_sorted(stack_a))
	{
		if (count_node == 1)
			return (0);
		else if (count_node == 2)
			ft_sort_two(&stack_a, &stack_b);
		else if (count_node == 3)
			ft_sort_three(&stack_a, &stack_b);
		else if (count_node == 4)
			ft_sort_for(&stack_a, &stack_b, count_node);
		else if (count_node == 5)
			ft_sort_five(&stack_a, &stack_b, count_node);
		else
			ft_sort_big(&stack_a, &stack_b, count_node);
	}
}

// int		i = 0;
// printf("stack a : \n");
// while (stack_a)
// {
// 	printf("%lld\n", stack_a->cont);
// 	// if (stack_a->cont != i)
// 	// {
// 	// 	printf("wow\n");
// 	// 	exit (0);
// 	// }
// 	stack_a = stack_a->next;
// 	i++;
// }
// i = 0;
// printf("stack b : \n");
// while (stack_b)
// {
// 	printf("%lld\n", stack_b->cont);
// 	// if (stack_b->cont != i)
// 	// {
// 	// 	printf("wow\n");
// 	// 	exit (0);
// 	// }
// 	stack_b = stack_b->next;
// 	i++;
// }
// 
// 	ft_printf("sorted\n");
// else
// 	ft_printf("not sorted\n");