/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_1_2(t_push *ab)
{
	if (ab->couple == 1)
	{
		if (ab->memlist->len == 2)
		{
			push_ab(ab, 2, 1);
			push_ab(ab, 2, 1);
			sort_footer_big(ab);
		}
		else
		{
			push_ab(ab, 2, 1);
			rev_rotate_ab(ab, 1, 1);
			rev_rotate_ab(ab, 1, 1);
			if (!(is_order_cut(ab->a, 1, 2)))
				swap_ab(ab, 1, 1);
			push_ab(ab, 1, 1);
		}
		ab->couple = 0;
	}
	else if (ab->memlist->len == 2 && !(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	ab->memlist->len = 0;
}

void	sort_less_first_3(t_push *ab)
{
	if (*((int *)ab->a->content) == ab->param->end &&
	*((int *)ab->a->next->next->content) == ab->param->prev_end)
		rotate_ab(ab, 1, 1);
	else if (*((int *)ab->a->content) == ab->param->prev_end &&
	*((int *)ab->a->next->content) == ab->param->end)
		rev_rotate_ab(ab, 1, 1);
	else if (*((int *)ab->a->content) == ab->param->end &&
	*((int *)ab->a->next->content) == ab->param->prev_end)
	{
		swap_ab(ab, 1, 1);
		rev_rotate_ab(ab, 1, 1);
	}
	ab->first = 0;
}

void	sort_footer_big(t_push *ab)
{
	rev_rotate_ab(ab, 1, 1);
	rev_rotate_ab(ab, 1, 1);
	sort_footer_end(ab);
}

void	sort_footer_end(t_push *ab)
{
	if (!(is_order_cut(ab->a, 1, 2)) && is_order_cut(ab->b, 1, 2))
		swap_ab(ab, 3, 1);
	else if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
}

void	sort_footer_end2(t_push *ab)
{
	push_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
}
