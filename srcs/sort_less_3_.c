/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_3_4_1(t_push *ab)
{
	while (ab->memlist->len > 0)
	{
		while (ab->memlist->len > 0 && (find_last(ab->b) == ab->param->end ||
		find_last(ab->b) == ab->param->prev_end))
		{
			rev_rotate_ab(ab, 2, 1);
			push_ab(ab, 1, 1);
			ab->memlist->len--;
		}
		if (ab->memlist->len > 0)
		{
			rev_rotate_ab(ab, 2, 1);
			ab->memlist->len--;
		}
	}
	sort_footer_end(ab);
}

void	sort_less_3_3_1(t_push *ab)
{
	while (ab->memlist->len > 0)
	{
		while (ab->memlist->len > 0 && (find_last(ab->b) == ab->param->end ||
		find_last(ab->b) == ab->param->prev_end))
		{
			rev_rotate_ab(ab, 2, 1);
			push_ab(ab, 1, 1);
			ab->memlist->len--;
		}
		if (ab->memlist->len > 0)
		{
			rev_rotate_ab(ab, 2, 1);
			ab->memlist->len--;
		}
	}
	if (!(is_order_cut(ab->a, 1, 2)))
		swap_ab(ab, 1, 1);
	push_ab(ab, 1, 1);
}
