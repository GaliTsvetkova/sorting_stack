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

void		print_list(t_list *a1)
{
	t_list	*a;

	a = a1;
	ft_printf("*list:\n");
	if (a == NULL || a->content == NULL)
		ft_printf("empty*\n");
	else
	{
		while (a != NULL && a->content)
		{
			ft_printf("%d\n", *((int *)a->content));
			a = a->next;
		}
		if (a != NULL && a->content)
			ft_printf("%d*\n", *((int *)a->content));
		if (a == NULL)
			ft_printf("*\n");
	}
}

void		print_ab(t_push *ab)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = ab->a;
	b = ab->b;
	i = ab->num;
	while (i > 0)
	{
		if (a == NULL || a->content == NULL)
			ft_printf("| %11s | ", "");
		else
		{
			ft_printf("| %s%11d%s | ", ab->color, *((int *)a->content), ENDC);
			a = a->next;
		}
		if (b == NULL || b->content == NULL)
			ft_printf("%11s |\n", "");
		else
		{
			ft_printf("%s%11d%s |\n", ab->color, *((int *)b->content), ENDC);
			b = b->next;
		}
		i--;
	}
}

void		print_lists(t_push *ab)
{
	ft_printf("_______a_____________b______\n");
	if (ab->a || ab->b)
	{
		print_ab(ab);
		ft_printf("____________________________\n");
	}
	else
		ft_printf("empty*\n");
}
