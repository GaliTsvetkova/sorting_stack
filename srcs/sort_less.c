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

void	sort_less_1_3(t_push *ab)
{
	if (is_order_cut(ab->a, 1, 3))
		sort_less_1_3_1(ab);
	else if (*((int *)ab->a->next->next->content) == ab->param->end)
		sort_less_1_3_2(ab);
	else if (*((int *)ab->a->next->content) == ab->param->end &&
	*((int *)ab->a->next->next->content) == ab->param->prev_end)
		sort_less_1_3_3(ab);
	else
		sort_less_1_3_4(ab);
}

void	sort_less_1(t_push *ab)
{
	if (ab->memlist->len == 4)
	{
		if (is_order_cut(ab->a, 1, 4))
			sort_less_1_4_1(ab);
		else if (*((int *)ab->a->next->next->content) == ab->param->prev_end &&
		*((int *)ab->a->next->next->next->content) == ab->param->end)
			sort_less_1_4_2(ab);
		else if (*((int *)ab->a->next->next->content) == ab->param->end &&
		*((int *)ab->a->next->next->next->content) == ab->param->prev_end)
			sort_less_1_4_3(ab);
		else
			sort_less_1_4_4(ab);
	}
	if (ab->memlist->len == 3)
		sort_less_1_3(ab);
	if (ab->memlist->len <= 2)
		sort_less_1_2(ab);
	ab->memlist->num = 0;
}

void	sort_less_2(t_push *ab)
{
	if (ab->memlist->len == 4)
	{
		if ((*((int *)ab->b->content) >= ab->param->med &&
		*((int *)ab->b->next->content) >= ab->param->med))
			sort_less_2_4_1(ab);
		else
			sort_less_2_4_2(ab);
	}
	if (ab->memlist->len == 3)
	{
		if ((*((int *)ab->b->content) >= ab->param->med &&
		*((int *)ab->b->next->content) >= ab->param->med))
			sort_less_2_3_1(ab);
		else
			sort_less_2_3_2(ab);
	}
	if (ab->memlist->len <= 2)
		sort_less_2_2(ab);
	ab->memlist->num = 0;
}

void	sort_less_3(t_push *ab)
{
	if (ab->memlist->len == 4)
		sort_less_3_4_1(ab);
	else if (ab->memlist->len == 3)
		sort_less_3_3_1(ab);
	else if (ab->memlist->len == 2)
	{
		rev_rotate_ab(ab, 2, 1);
		push_ab(ab, 1, 1);
		rev_rotate_ab(ab, 2, 1);
		push_ab(ab, 1, 1);
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
	}
	else if (ab->memlist->len == 1)
	{
		rev_rotate_ab(ab, 2, 1);
		push_ab(ab, 1, 1);
	}
	ab->memlist->num = 0;
}
