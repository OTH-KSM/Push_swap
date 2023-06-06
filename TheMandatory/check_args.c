/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:45:54 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/02 19:41:53 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_create_node(t_node **a, t_node **head, int *count_node,
		char **splited)
{
	t_node		*new_node;
	long long	integer;
	int			index;

	index = 0;
	while (splited[index])
	{
		integer = ft_atoll(splited[index]);
		if (ft_check_max_int(integer) == 0)
		{
			ft_check_dup(*head, integer);
			new_node = malloc(sizeof(t_node));
			if (!new_node)
				exit (0);
			new_node->cont = integer;
			new_node->next = NULL;
			if (*head == NULL)
				*head = new_node;
			if ((*a) != NULL)
				(*a)->next = new_node;
			(*count_node)++;
			(*a) = new_node;
		}
		index++;
	}
}

t_node	*ft_check_args(char **argv, t_node **a, int *count_node)
{
	t_node	*head;
	t_node	*save;
	char	**ptr;
	int		k;
	int		i;

	k = 1;
	i = 0;
	(*a) = malloc(sizeof(t_node));
	if (!(*a))
		exit (0);
	(*a)->next = NULL;
	head = (*a);
	while (argv[k])
	{
		ft_check_arg_int(argv[k]);
		ptr = ft_split(argv[k], ' ');
		ft_create_node(a, &head, &(*count_node), ptr);
		ft_free_ptr(ptr);
		k++;
	}
	save = head->next;
	free(head);
	return (save);
}
