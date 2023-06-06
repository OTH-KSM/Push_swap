/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:25:27 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/06 00:29:13 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_sorted(t_node *a, t_node *b)
{
	if (b)
		return (0);
	while (a && a->next)
	{
		if (a->cont > a->next->cont)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_campare_double(t_node **a, t_node **b, char *instruction, int len)
{
	if (!ft_strncmp(instruction, "rrr\n", len))
		ft_reverse_both_for_checker(a, b);
	else if (!ft_strncmp(instruction, "rr\n", len))
		ft_rotate_both_for_checker(a, b);
	else if (!ft_strncmp(instruction, "ss\n", len))
		ft_swap_both_for_checker(a, b);
}

void	ft_compare_instruction(t_node **a, t_node **b, char *instruction)
{
	int	len;

	len = ft_strlen(instruction);
	if (!ft_strncmp(instruction, "ra\n", len))
		ft_rotate_for_checker(a);
	else if (!ft_strncmp(instruction, "rb\n", len))
		ft_rotate_for_checker(b);
	else if (!ft_strncmp(instruction, "sa\n", len))
		ft_swap_for_checker(a, b, 1);
	else if (!ft_strncmp(instruction, "sb\n", len))
		ft_swap_for_checker(a, b, 2);
	else if (!ft_strncmp(instruction, "pa\n", len))
		ft_push_for_checker(a, b, 1);
	else if (!ft_strncmp(instruction, "pb\n", len))
		ft_push_for_checker(a, b, 2);
	else if (!ft_strncmp(instruction, "rra\n", len))
		ft_reverse_for_checker(a);
	else if (!ft_strncmp(instruction, "rrb\n", len))
		ft_reverse_for_checker(b);
	else if (!ft_strncmp(instruction, "rrr\n", len)
		|| !ft_strncmp(instruction, "rr\n", len)
		|| !ft_strncmp(instruction, "ss\n", len))
		ft_campare_double(a, b, instruction, len);
	else
		ft_print_error();
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count_node;
	char	*instruction;

	if (argc < 2)
		return (0);
	count_node = 0;
	stack_a = ft_check_args(argv, &stack_a, &count_node);
	stack_b = NULL;
	instruction = get_next_line(0);
	while (instruction)
	{
		ft_compare_instruction(&stack_a, &stack_b, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (ft_check_sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
