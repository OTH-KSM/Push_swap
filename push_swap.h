/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:58:32 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/02 00:21:07 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct node
{
	long long	cont;
	struct node	*next;
	int			index;
}				t_node;

typedef struct elem
{
	int			i;
	int			j;
	int			offset;
	int			size;
	int			max;
	int			midd;
	int			l_midd;
	int			r_midd;
	struct node	*iter;
	struct node	*tl;
	int			*arr;
	int			which;
}				t_elem;

//CHECKING ARGS
t_node			*ft_check_args(char **argv, t_node **a, int *count_node);

long long		ft_atoll(const char *nptr);
void			ft_check_arg_int(char *arg);
int				ft_check_max_int(long long arg);
void			ft_check_dup(t_node *stack, long long nbr);
void			ft_print_error(void);

//SMALL_SORT
void			ft_sort_two(t_node **a, t_node **b);
void			ft_sort_three(t_node **a, t_node **b);
void			ft_sort_for(t_node **a, t_node **b, int lst_size);
void			ft_sort_five(t_node **a, t_node **b, int lst_size);
void			ft_help(t_node **a, t_node **stack, int *i, int lst_size);

//BIG_SORT
void			ft_sort_big(t_node **a, t_node **b, int lst_size);

int				ft_locate(t_node **b, int tail);
int				ft_find(t_node **b, int max);
void			ft_do_this(t_node **b, int lst_size, int max);
void			ft_fill_arr(t_elem *elem, int *arr, int lst_size);
int				*ft_class_node_in_arr(t_node **a, int **arr, int lst_size);
int				ft_make_offset(int lst_size);
void			ft_push_it_to_a(t_node **a, t_node **b,
					t_elem *elem, int *lst_size);
void			ft_just_reverse(t_node **a, t_elem *elem, int *lst_size);

//MANDATORY_INSTRUCTION
void			ft_swap(t_node **a, t_node **b, int which);
void			ft_push(t_node **x, t_node **y, int which);
void			ft_rotate(t_node **stack, char which);
void			ft_reverse(t_node **stack, char which);
void			ft_swap_both(t_node **a, t_node **b);
void			ft_rotate_both(t_node **a, t_node **b);
void			ft_reverse_both(t_node **a, t_node **b);

//BONUS_INSTRUCTION
void			ft_swap_for_checker(t_node **a, t_node **b, int which);
void			ft_push_for_checker(t_node **a, t_node **b, int which);
void			ft_rotate_for_checker(t_node **stack);
void			ft_reverse_for_checker(t_node **stack);
void			ft_swap_both_for_checker(t_node **a, t_node **b);
void			ft_rotate_both_for_checker(t_node **a, t_node **b);
void			ft_reverse_both_for_checker(t_node **a, t_node **b);

#endif