/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	help_while_2_1(t_push *ab)
{
	while (ab->param->i + 2 < ab->memlist->len &&
		(*((int *)ab->b->content) == ab->param->end ||
		*((int *)ab->b->content) == ab->param->prev_end) &&
		*((int *)ab->b->content) < ab->param->med)
	{
		push_ab(ab, 2, 1);
		rotate_ab(ab, 3, 1);
		ab->param->little++;
		ab->param->i = ab->param->i + 2;
	}
}

void	help_while_2_2(t_push *ab, int mod)
{
	if (mod == 1)
	{
		while (*((int *)ab->b->content) == ab->param->end ||
			*((int *)ab->b->content) == ab->param->prev_end)
		{
			push_ab(ab, 1, 1);
			rotate_ab(ab, 1, 1);
			ab->param->i++;
		}
	}
	if (mod == 2 && (ab->param->i < ab->memlist->len &&
		*((int *)ab->b->content) >= ab->param->med &&
		*((int *)ab->b->content) < ab->param->prev_end))
	{
		push_ab(ab, 1, 1);
		ab->param->i++;
		ab->param->big++;
	}
	if (mod == 3 && (ab->param->i < ab->memlist->len &&
		*((int *)ab->b->content) < ab->param->med))
	{
		rotate_ab(ab, 2, 1);
		ab->param->i++;
		ab->param->little++;
	}
}

void	help_while_3_1(t_push *ab, int mod)
{
	if (mod == 1)
	{
		while (find_last(ab->b) == ab->param->end ||
			find_last(ab->b) == ab->param->prev_end)
		{
			rev_rotate_ab(ab, 2, 1);
			push_ab(ab, 1, 1);
			rotate_ab(ab, 1, 1);
			ab->param->i++;
		}
	}
	if (mod == 2 && (ab->param->i < ab->memlist->len &&
		(find_last(ab->b) >= ab->param->med &&
		find_last(ab->b) < ab->param->prev_end)))
	{
		rev_rotate_ab(ab, 2, 1);
		push_ab(ab, 1, 1);
		ab->param->i++;
		ab->param->big++;
	}
}
