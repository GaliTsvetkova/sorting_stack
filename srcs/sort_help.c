/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	help_while_0_1(t_push *ab)
{
	while (ab->param->i + 2 < ab->memlist->len &&
		*((int *)ab->a->content) < ab->param->beg2 &&
		ab->a->next->content &&
		*((int *)ab->a->next->content) >= ab->param->beg3)
	{
		push_ab(ab, 2, 1);
		rotate_ab(ab, 3, 1);
		ab->param->little++;
		ab->param->big++;
		ab->param->i = ab->param->i + 2;
	}
}

void	help_while_0_2(t_push *ab, int mod)
{
	if (mod == 1 && (ab->param->i < ab->memlist->len &&
		*((int *)ab->a->content) < ab->param->beg2))
	{
		push_ab(ab, 2, 1);
		rotate_ab(ab, 2, 1);
		ab->param->little++;
		ab->param->i++;
	}
	else if (mod == 2 && (ab->param->i < ab->memlist->len &&
		*((int *)ab->a->content) >= ab->param->beg2 &&
		*((int *)ab->a->content) < ab->param->beg3))
	{
		push_ab(ab, 2, 1);
		ab->param->i++;
		ab->param->mid++;
	}
	else if (mod == 3 && (ab->param->i < ab->memlist->len &&
		*((int *)ab->a->content) >= ab->param->beg3))
	{
		rotate_ab(ab, 1, 1);
		ab->param->i++;
		ab->param->big++;
	}
}

void	help_while_1_1(t_push *ab, int mod)
{
	if (mod == 1)
	{
		while (ab->param->i + 2 < ab->memlist->len &&
			*((int *)ab->a->content) < ab->param->med &&
			ab->a->next->content &&
			(*((int *)ab->a->next->content) == ab->param->end ||
			*((int *)ab->a->next->content) == ab->param->prev_end))
		{
			push_ab(ab, 2, 1);
			rotate_ab(ab, 3, 1);
			ab->param->little++;
			ab->param->i = ab->param->i + 2;
		}
	}
	if (mod == 3 && (ab->param->i < ab->memlist->len &&
		*((int *)ab->a->content) < ab->param->med))
	{
		push_ab(ab, 2, 1);
		rotate_ab(ab, 2, 1);
		ab->param->i++;
		ab->param->little++;
	}
}

void	help_while_1_2(t_push *ab, int mod)
{
	if (mod == 1)
	{
		while (ab->param->i < ab->memlist->len &&
			(*((int *)ab->a->content) == ab->param->end ||
			*((int *)ab->a->content) == ab->param->prev_end))
		{
			rotate_ab(ab, 1, 1);
			ab->param->i++;
		}
	}
	if (mod == 2 && (ab->param->i < ab->memlist->len &&
			*((int *)ab->a->content) >= ab->param->med &&
			*((int *)ab->a->content) < ab->param->prev_end))
	{
		push_ab(ab, 2, 1);
		ab->param->i++;
		ab->param->big++;
	}
}

void	help_check_1(t_push *ab)
{
	if (ft_lenlst(ab->a) == 2)
	{
		if (!(is_order_cut(ab->a, 1, 2)))
			swap_ab(ab, 1, 1);
	}
	else
	{
		if (ab->couple == 1)
		{
			rev_rotate_ab(ab, 1, 1);
			rev_rotate_ab(ab, 1, 1);
			push_ab(ab, 2, 1);
			push_ab(ab, 2, 1);
			ab->couple = 0;
		}
		sort_footer_big(ab);
	}
}
