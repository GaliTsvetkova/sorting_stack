/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	record_mem_0(t_push *ab, int big, int little, int mid)
{
	t_mem	*bigger;
	t_mem	*smaller;
	t_mem	*middle;

	bigger = mem_new(big, 1, 1);
	smaller = mem_new(little, 2, 2);
	middle = mem_new(mid, 2, 1);
	mem_add_with_nol(ab, smaller);
	mem_add(ab, middle);
	mem_add(ab, bigger);
}

void	record_mem_1(t_push *ab, int big, int little)
{
	t_mem	*bigger;
	t_mem	*smaller;

	bigger = mem_new(big, 2, 1);
	smaller = mem_new(little, 3, ft_lenlst(ab->b) - little + 1);
	mem_add_with_nol(ab, smaller);
	mem_add(ab, bigger);
}

void	record_mem_2(t_push *ab, int big, int little, int mod)
{
	t_mem	*bigger;
	t_mem	*smaller;

	if (mod == 2)
	{
		bigger = mem_new(big, 1, 1);
		smaller = mem_new(little, 3, ft_lenlst(ab->b) - little + 1);
	}
	if (mod == 3)
	{
		bigger = mem_new(big, 1, 1);
		smaller = mem_new(little, 2, 1);
	}
	mem_add_with_nol(ab, smaller);
	mem_add(ab, bigger);
	ab->couple++;
}

void	mem_add_with_nol(t_push *ab, t_mem *newmem)
{
	newmem->next = ab->memlist->next;
	free(ab->memlist);
	ab->memlist = newmem;
}

void	mem_add(t_push *ab, t_mem *newmem)
{
	newmem->next = ab->memlist;
	ab->memlist = newmem;
}
