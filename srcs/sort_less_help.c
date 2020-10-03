/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_help_1(t_push *ab, int mod)
{
	if (mod == 1)
	{
		push_ab(ab, 2, 1);
		push_ab(ab, 2, 1);
		if (is_order_cut(ab->b, 1, 2))
			swap_ab(ab, 3, 1);
		else
			swap_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
		push_ab(ab, 1, 1);
	}
	if (mod == 2)
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
}
