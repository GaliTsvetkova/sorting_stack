/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_correct(t_list *mlist1)
{
	t_list	*mlist;
	int		x;

	mlist = mlist1;
	if (!(mlist1))
		return (0);
	if (mlist1->content == NULL)
		return (0);
	x = *((int *)(mlist->content));
	while (mlist->next)
	{
		if (x == *((int *)(mlist->next->content)) && mlist->next)
			return (0);
		mlist = mlist->next;
	}
	return (1);
}

int			is_order_up(t_list *mlist1)
{
	t_list	*mlist;

	mlist = mlist1;
	if (!mlist)
		return (0);
	if (!(mlist->next))
		return (1);
	while (mlist->next && mlist->next->content)
	{
		if (*((int *)mlist->content) > *((int *)mlist->next->content))
			return (0);
		mlist = mlist->next;
	}
	return (1);
}

int			is_order_cut(t_list *x, int index, int len)
{
	t_list	*mlist;

	mlist = x;
	if (!mlist)
	{
		ft_printf("order checker error: there isn't list");
		return (0);
	}
	if (!(mlist->next))
	{
		return (1);
	}
	if (len == 1)
		return (1);
	while (index-- > 1)
		mlist = mlist->next;
	while (len-- > 1)
	{
		if (*((int *)mlist->content) > *((int *)mlist->next->content))
			return (0);
		mlist = mlist->next;
	}
	return (1);
}

int			is_over(char *s, int x)
{
	int		i;

	i = 0;
	while (ft_isdigit(s[0]))
	{
		s++;
		i++;
		if (i > x)
			return (1);
	}
	return (0);
}

int			check_str(char *v, int len)
{
	int		i;

	i = 0;
	if (is_over(v, 12) ||
		(v[0] == '0' && len > 1 && v[1] && ft_isdigit(v[1])))
		return (0);
	if (v[0] == '-')
	{
		if (!v[1] || !ft_isdigit(v[1]))
			return (0);
		else
			i++;
	}
	while (i < len)
	{
		if (!(ft_isdigit(v[i])) && (v[i] != ',' ||
									(v[i] == ',' && (i + 1) < len && v[i + 1])))
			return (0);
		else
			i++;
	}
	return (i);
}
