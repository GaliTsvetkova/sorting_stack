/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_1_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_1_3_1(t_push *ab)
{
	if (ab->couple == 1)
	{
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
		ab->couple = 0;
	}
	ab->memlist->len = 0;
}

void	sort_less_1_3_2(t_push *ab)
{
	if (ab->couple == 1)
	{
		swap_ab(ab, 1, 1);
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
		ab->couple = 0;
	}
	else
		swap_ab(ab, 1, 1);
	ab->memlist->len = 0;
}

void	sort_less_1_3_3(t_push *ab)
{
	if (ab->couple == 1)
	{
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		rev_rotate_ab(ab, 1, 1);
		rev_rotate_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 3, 1);
		else
			swap_ab(ab, 2, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		ab->couple = 0;
	}
	else
	{
		push_ab(ab, 2, 1);
		swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
	}
	ab->memlist->len = 0;
}

void	sort_less_1_3_4(t_push *ab)
{
	if (ab->first == 1)
		sort_less_first_3(ab);
	else if (ab->couple == 1)
		sort_less_1_3_5(ab);
	else
	{
		while (ab->memlist->len > 0)
		{
			if (*((int *)ab->a->content) == ab->param->end)
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
		sort_footer_end2(ab);
	}
	ab->memlist->len = 0;
}

void	sort_less_1_3_5(t_push *ab)
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
	sort_footer_end(ab);
	push_ab(ab, 1, 1);
	ab->couple = 0;
}
