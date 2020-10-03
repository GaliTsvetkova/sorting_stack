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

void		find_help(t_push *ab, int mod)
{
	if (mod == 1)
	{
		ab->param->end = *((int *)ab->help->content);
		ab->param->prev_end = *((int *)ab->help->content);
		clean_help(ab);
	}
	if (mod == 2)
	{
		ab->param->end = *((int *)ab->help->next->content);
		ab->param->prev_end = *((int *)ab->help->content);
		clean_help(ab);
	}
	if (mod == 3)
	{
		ab->param->med = *((int *)ab->help->content);
		while (ab->help && ab->help->next->next)
			ab->help = ab->help->next;
		ab->param->prev_end = *((int *)ab->help->content);
		ab->param->end = find_last(ab->help);
		clean_help(ab);
	}
}

void		set_help(t_push *ab, int stack, int index, int len)
{
	if (stack == 1)
		ab->help = ft_cp_cut_list(ab->a, index, len);
	else
	{
		if (index == 1)
			ab->help = ft_cp_cut_list(ab->b, index, len);
		else
			ab->help = ft_cp_cut_list(ab->b, ft_lenlst(ab->b) -
			len + 1, len);
	}
}

void		find_cuts(t_push *ab, int len)
{
	ab->help = ft_cp_cut_list(ab->a, 1, len);
	algo_bubble(ab->help);
	ab->help_del = ab->help;
	set_param(ab);
	while (ab->param->i < len * 4 / 14)
	{
		ab->help = ab->help->next;
		ab->param->i++;
	}
	ab->param->beg2 = *((int *)ab->help->content);
	while (ab->param->i < len * 2 / 3)
	{
		ab->help = ab->help->next;
		ab->param->i++;
	}
	ab->param->beg3 = *((int *)ab->help->content);
	clean_help(ab);
}

void		find_param(t_push *ab, int stack, int index, int len)
{
	int		i;

	set_help(ab, stack, index, len);
	algo_bubble(ab->help);
	ab->help_del = ab->help;
	if (ab->help && !(ab->help->next))
	{
		find_help(ab, 1);
		return ;
	}
	if (ab->help && ab->help->next && !(ab->help->next->next))
	{
		find_help(ab, 2);
		return ;
	}
	i = 0;
	while (i < len / 2)
	{
		ab->help = ab->help->next;
		i++;
	}
	find_help(ab, 3);
}

int			find_last(t_list *x)
{
	t_list	*lx;

	if (!x)
		return (0);
	if (x->next == NULL)
	{
		if (x->content)
			return (*((int *)x->content));
		else
			return (0);
	}
	lx = x;
	while (lx && lx->next)
		lx = lx->next;
	return (*((int *)lx->content));
}
