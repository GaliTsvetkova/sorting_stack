/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_1_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_1_4_1(t_push *ab)
{
	if (ab->couple == 1)
	{
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		rev_rotate_ab(ab, 1, 1);
		rev_rotate_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		ab->couple = 0;
	}
	ab->memlist->len = 0;
}

void	sort_less_1_4_2(t_push *ab)
{
	if (ab->couple == 1)
	{
		swap_ab(ab, 1, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		rev_rotate_ab(ab, 1, 1);
		rev_rotate_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		ab->couple = 0;
	}
	else
		swap_ab(ab, 1, 1);
	ab->memlist->len = 0;
}

void	sort_less_1_4_3(t_push *ab)
{
	if (ab->couple == 1)
	{
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		if (is_order_cut(ab->b, 1, 2))
			swap_ab(ab, 3, 1);
		else
			swap_ab(ab, 1, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		rev_rotate_ab(ab, 1, 1);
		rev_rotate_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		ab->couple = 0;
	}
	else
		sort_less_help_1(ab, 1);
	ab->memlist->len = 0;
}

void	sort_less_1_4_5(t_push *ab)
{
	while (ab->memlist->len > 0)
	{
		while (ab->memlist->len > 0 &&
		(*((int *)ab->a->content) == ab->param->end ||
		*((int *)ab->a->content) == ab->param->prev_end))
		{
			push_ab(ab, 2, 1);
			rotate_ab(ab, 2, 1);
			ab->memlist->len--;
		}
		if (ab->memlist->len > 0)
		{
			push_ab(ab, 2, 1);
			ab->memlist->len--;
		}
	}
	rev_rotate_ab(ab, 3, 1);
	rev_rotate_ab(ab, 3, 1);
	sort_less_help_1(ab, 2);
	push_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	ab->couple = 0;
}

void	sort_less_1_4_4(t_push *ab)
{
	if (ab->couple == 1)
		sort_less_1_4_5(ab);
	else
	{
		while (ab->memlist->len > 0)
		{
			while (ab->memlist->len > 0 &&
			(*((int *)ab->a->content) == ab->param->end ||
			*((int *)ab->a->content) == ab->param->prev_end))
			{
				rotate_ab(ab, 1, 1);
				ab->memlist->len--;
			}
			if (ab->memlist->len > 0)
			{
				push_ab(ab, 2, 1);
				ab->memlist->len--;
			}
		}
		rev_rotate_ab(ab, 1, 1);
		rev_rotate_ab(ab, 1, 1);
		sort_footer_end(ab);
	}
	ab->memlist->len = 0;
}
