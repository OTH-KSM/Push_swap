/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_what.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:05:46 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/06 00:21:56 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_check_dup(t_node *stack, long long nbr)
{
	t_node	*head;

	if (!stack)
		return ;
	head = stack;
	while (head)
	{
		if (head->cont == nbr)
			ft_print_error();
		head = head->next;
	}
}

long long	ft_atoll(const char *nptr)
{
	int		i;
	int		signe;
	size_t	nb;

	i = 0;
	nb = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		if (nb > INT_MAX && signe == -1)
			return (2147483648);
		if (nb > INT_MAX && signe == 1)
			return (2147483648);
		nb = nb * 10 + nptr[i++] - '0';
	}
	return (nb * signe);
}

void	ft_check_arg_int(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if ((arg[i] == '+' && arg[i + 1] == ' ') || (arg[i] == '-' && arg[i
						+ 1] == ' ') || ((arg[i] != 43 && arg[i] != 45
						&& arg[i] != ' ') && ((arg[i] > 32 && arg[i] < 48)
						|| (arg[i] > 57))) || (arg[i] == '+' && arg[i
						+ 1] == '+') || (arg[i] == '-' && arg[i + 1] == '-')
				|| (arg[i] == '+' && arg[i + 1] == '\0') || (arg[i] == '-'
					&& arg[i + 1] == '\0') || (arg[i] == '-' && arg[i
						+ 1] == '+') || (arg[i] == '+' && arg[i + 1] == '-'))
				ft_print_error();
		}
		else
			if ((arg[i + 1] >= 58 && arg[i + 1] <= 126)
				|| (arg[i + 1] >= 33 && arg[i + 1] <= 47))
				ft_print_error();
		i++;
	}
	return ;
}

int	ft_check_max_int(long long arg)
{
	if (arg > INT_MAX || arg < INT_MIN)
		ft_print_error();
	return (0);
}
