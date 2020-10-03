/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rest_free(t_push *ab)
{
	if (ab->actions != NULL)
		free(ab->actions);
	if (ab->memlist != NULL)
		free(ab->memlist);
	if (ab->param != NULL)
		free(ab->param);
}

void		clean_push(t_push *ab)
{
	t_list	*help;

	if (ab->a != NULL)
	{
		while (ab->a)
		{
			help = ab->a->next;
			free(ab->a->content);
			free(ab->a);
			ab->a = help;
		}
	}
	if (ab->b != NULL)
	{
		while (ab->b)
		{
			help = ab->b->next;
			free(ab->b->content);
			free(ab->b);
			ab->b = help;
		}
	}
	rest_free(ab);
}

void		clean_help(t_push *ab)
{
	t_list	*help;

	if (ab->help_del != NULL)
	{
		while (ab->help_del)
		{
			help = ab->help_del->next;
			free(ab->help_del->content);
			free(ab->help_del);
			ab->help_del = help;
		}
	}
	ab->help = NULL;
	ab->help_del = NULL;
}
