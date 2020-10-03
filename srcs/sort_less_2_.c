/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_2_4_1(t_push *ab)
{
	push_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	if (!(is_order_cut(ab->a, 1, 2)) &&
	is_order_cut(ab->b, 1, 2))
		swap_ab(ab, 3, 1);
	else if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
}

void	sort_less_2_4_2(t_push *ab)
{
	while (ab->memlist->len > 0)
	{
		while (ab->memlist->len > 0 &&
		(*((int *)ab->b->content) == ab->param->end ||
		*((int *)ab->b->content) == ab->param->prev_end))
		{
			push_ab(ab, 1, 1);
			ab->memlist->len--;
		}
		if (ab->memlist->len > 0)
		{
			rotate_ab(ab, 2, 1);
			ab->memlist->len--;
		}
	}
	rev_rotate_ab(ab, 2, 1);
	rev_rotate_ab(ab, 2, 1);
	sort_footer_end(ab);
}

void	sort_less_2_3_1(t_push *ab)
{
	push_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
}

void	sort_less_2_3_2(t_push *ab)
{
	while (ab->memlist->len > 0)
	{
		while (ab->memlist->len > 0 &&
		(*((int *)ab->b->content) == ab->param->end ||
		*((int *)ab->b->content) == ab->param->prev_end))
		{
			push_ab(ab, 1, 1);
			ab->memlist->len--;
		}
		if (ab->memlist->len > 0)
		{
			rotate_ab(ab, 2, 1);
			ab->memlist->len--;
		}
	}
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	rev_rotate_ab(ab, 2, 1);
	push_ab(ab, 1, 1);
}

void	sort_less_2_2(t_push *ab)
{
	if (ab->memlist->len == 2)
	{
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
	}
	else if (ab->memlist->len == 1)
		push_ab(ab, 1, 1);
	ab->memlist->len = 0;
}
