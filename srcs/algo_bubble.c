/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		*swap_lists(t_list *l1, t_list *l2)
{
	t_list	*l3;
	t_list	*next2;

	l3 = ft_lstnew(0, 0);
	*l3 = *l2;
	next2 = l2->next;
	*l2 = *l1;
	l2->next = next2;
	*l1 = *l3;
	l1->next = l2;
	free(l3);
	return (0);
}

void		algo_bubble(t_list *x)
{
	t_list	*y1;
	int		o;

	o = 1;
	while (o == 1)
	{
		o = 0;
		y1 = x;
		while (y1->next != NULL)
		{
			if (*((int *)y1->content) > *((int *)y1->next->content))
			{
				swap_lists(y1, y1->next);
				o = 1;
			}
			y1 = y1->next;
		}
	}
}
