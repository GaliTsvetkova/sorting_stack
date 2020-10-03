/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_actions_str(char *str, int i)
{
	if (ft_strncmp(str + i, "sa\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "sb\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "ss\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "pa\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "pb\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "ra\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "rb\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "rr\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "rra\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "rrb\0",
		ft_strlen_sym(str + i, '\n')) == 0 ||
		ft_strncmp(str + i, "rrr\0",
		ft_strlen_sym(str + i, '\n')) == 0)
		return (0);
	return (-1);
}

int			check_actions(t_push *ab)
{
	int		i;

	i = 0;
	ab->actions = reading_file();
	while (ab->actions != NULL && ab->actions[i] != '\0')
	{
		if (ab->actions[i] == '\n' ||
			check_actions_str(ab->actions, i) == -1)
			return (0);
		while (ab->actions[i] >= 'a' && ab->actions[i] <= 'z')
			i++;
		if (ab->actions[i] != '\n' && ab->actions[i] != '\0')
			return (0);
		if (ab->actions[i] != '\0')
			i++;
	}
	return (1);
}

void		check_sort_2(t_push *ab, int len, int i)
{
	if (ft_strncmp(ab->actions + i, "rb\0", len) == 0)
		rotate_ab(ab, 2, 0);
	else if (len == 2 && ft_strncmp(ab->actions + i, "rr\0", len) == 0)
		rotate_ab(ab, 3, 0);
	else if (ft_strncmp(ab->actions + i, "rra\0", len) == 0)
		rev_rotate_ab(ab, 1, 0);
	else if (ft_strncmp(ab->actions + i, "rrb\0", len) == 0)
		rev_rotate_ab(ab, 2, 0);
	else if (ft_strncmp(ab->actions + i, "rrr\0", len) == 0)
		rev_rotate_ab(ab, 3, 0);
}

void		check_sort_1(t_push *ab)
{
	int		len;

	len = ft_strlen_sym(ab->actions + ab->i_str, '\n');
	if (ft_strncmp(ab->actions + ab->i_str, "sa\0", len) == 0)
		swap_ab(ab, 1, 0);
	else if (ft_strncmp(ab->actions + ab->i_str, "sb\0", len) == 0)
		swap_ab(ab, 2, 0);
	else if (ft_strncmp(ab->actions + ab->i_str, "ss\0", len) == 0)
		swap_ab(ab, 3, 0);
	else if (ft_strncmp(ab->actions + ab->i_str, "pa\0", len) == 0)
		push_ab(ab, 1, 0);
	else if (ft_strncmp(ab->actions + ab->i_str, "pb\0", len) == 0)
		push_ab(ab, 2, 0);
	else if (ft_strncmp(ab->actions + ab->i_str, "ra\0", len) == 0)
		rotate_ab(ab, 1, 0);
	else
		check_sort_2(ab, len, ab->i_str);
}

void		check_sort(t_push *ab)
{
	ab->i_str = 0;
	while (ab->actions != NULL && ab->actions[ab->i_str] != '\0')
	{
		check_sort_1(ab);
		while (ab->actions[ab->i_str] >= 'a'
		&& ab->actions[ab->i_str] <= 'z')
			ab->i_str++;
		ab->i_str++;
	}
	if (is_order_up(ab->a) == 1 && (ab->b == NULL ||
	(ab->b && ab->b->content == NULL)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
