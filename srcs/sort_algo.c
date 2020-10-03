/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_start(t_push *ab)
{
	int		i;
	t_mem	*help;

	i = 0;
	sort0(ab);
	while (ft_lenlst(ab->a) < ab->num)
	{
		if (ab->memlist->num == 1)
			sort1(ab);
		if (ab->memlist->num == 2)
			sort2(ab);
		if (ab->memlist->num == 3)
			sort3(ab);
		while (ab->memlist && ab->memlist->num == 0)
		{
			help = ab->memlist;
			ab->memlist = ab->memlist->next;
			free(help);
		}
		if (i == ab->num)
			i = 1;
	}
}

void	sort0(t_push *ab)
{
	find_cuts(ab, ab->num);
	find_param(ab, 1, 1, ab->memlist->len);
	set_param(ab);
	if (ab->memlist->len > 4 && !(is_order_up(ab->a)))
	{
		while (ab->param->i < ab->memlist->len)
		{
			help_while_0_1(ab);
			help_while_0_2(ab, 1);
			help_while_0_1(ab);
			help_while_0_2(ab, 2);
			help_while_0_1(ab);
			help_while_0_2(ab, 3);
		}
		record_mem_0(ab, ab->param->big, ab->param->little, ab->param->mid);
	}
	else
		sort_less_1(ab);
	ab->first = 0;
}

void	sort1(t_push *ab)
{
	find_param(ab, 1, 1, ab->memlist->len);
	set_param(ab);
	if (ab->memlist->len > 4)
	{
		while (ab->param->i < ab->memlist->len)
		{
			help_while_1_1(ab, 1);
			help_while_1_2(ab, 1);
			help_while_1_1(ab, 1);
			help_while_1_2(ab, 2);
			help_while_1_1(ab, 1);
			help_while_1_1(ab, 3);
		}
		record_mem_1(ab, ab->param->big, ab->param->little);
		help_check_1(ab);
	}
	else
	{
		if (!(is_order_up(ab->a)))
			sort_less_1(ab);
		else
			ab->memlist->num = 0;
	}
}

void	sort2(t_push *ab)
{
	find_param(ab, 2, 1, ab->memlist->len);
	set_param(ab);
	if (ab->memlist->len > 4)
	{
		while (ab->param->i < ab->memlist->len)
		{
			help_while_2_1(ab);
			help_while_2_2(ab, 1);
			help_while_2_1(ab);
			help_while_2_2(ab, 2);
			help_while_2_1(ab);
			help_while_2_2(ab, 3);
		}
		record_mem_2(ab, ab->param->big, ab->param->little, 2);
	}
	else
		sort_less_2(ab);
}

void	sort3(t_push *ab)
{
	find_param(ab, 2, ab->memlist->index, ab->memlist->len);
	set_param(ab);
	if (ab->memlist->len > 4)
	{
		while (ab->param->i < ab->memlist->len)
		{
			help_while_3_1(ab, 1);
			help_while_3_1(ab, 2);
			if (ab->param->i < ab->memlist->len &&
			find_last(ab->b) < ab->param->med)
			{
				rev_rotate_ab(ab, 2, 1);
				ab->param->i++;
				ab->param->little++;
			}
		}
		record_mem_2(ab, ab->param->big, ab->param->little, 3);
	}
	else
		sort_less_3(ab);
}
