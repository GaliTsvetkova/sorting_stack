/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_lstfirsta_to_b(t_list **a, t_list **b)
{
	t_list	*a_first;
	t_list	*a_second;
	t_list	*b_ptr;

	a_first = *a;
	b_ptr = *b;
	if (a_first)
	{
		if (!(a_first->next))
			a_second = NULL;
		else
			a_second = a_first->next;
		a_first->next = b_ptr;
		*b = a_first;
		*a = a_second;
	}
}

void		ft_lstlast_to_head(t_list **x)
{
	t_list	*find_last;
	t_list	*ptr;
	int		len;

	if (!(*x))
		return ;
	find_last = *x;
	ptr = *x;
	len = ft_lenlst(ptr);
	if (ptr->next == NULL)
		return ;
	while (find_last->next)
		find_last = find_last->next;
	find_last->next = ptr;
	*x = find_last;
	ptr = *x;
	while (len-- > 1)
		ptr = ptr->next;
	ptr->next = NULL;
}

void		ft_lsthead_to_last(t_list **x)
{
	t_list	*find_last;
	t_list	*second;
	t_list	*ptr;

	if (!(*x))
		return ;
	find_last = *x;
	ptr = *x;
	second = ptr->next;
	if (ptr->next == NULL)
		return ;
	while (find_last->next)
		find_last = find_last->next;
	find_last->next = ptr;
	*x = second;
	ptr->next = NULL;
}

t_list		*ft_cp_cut_list(t_list *x, int index, int len)
{
	t_list	*l_b;
	t_list	*lx;

	lx = x;
	while (index-- > 1)
		lx = lx->next;
	l_b = ft_lstnew(lx->content, lx->content_size);
	lx = lx->next;
	while (len-- > 1)
	{
		ft_lstadd_end(&l_b, ft_lstnew(lx->content, lx->content_size));
		lx = lx->next;
	}
	return (l_b);
}
