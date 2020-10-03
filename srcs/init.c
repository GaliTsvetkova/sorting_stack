/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push		*init_push(int program, int argc)
{
	t_push	*ab;

	ab = (t_push *)malloc(sizeof(t_push));
	ab->a = NULL;
	ab->b = NULL;
	ab->help = NULL;
	ab->help_del = NULL;
	if (!(ab->memlist = mem_new(0, 1, 0)))
		return (0);
	ab->num = 0;
	ab->couple = 0;
	ab->rec = 0;
	ab->i_str = 0;
	ab->flag_t = 0;
	ab->flag_o = 0;
	ab->first = 1;
	ab->actions = NULL;
	ab->program = program;
	ab->color = ENDC;
	ab->count_of_elements = argc - 1;
	if (!(ab->param = (t_cut *)malloc(sizeof(t_cut))))
		return (0);
	return (ab);
}

t_mem		*mem_new(int len, int num, int index)
{
	t_mem	*memlist;

	if (!(memlist = (t_mem *)malloc(sizeof(t_mem))))
		return (NULL);
	memlist->len = len;
	memlist->num = num;
	memlist->index = index;
	memlist->next = NULL;
	return (memlist);
}

void		set_param(t_push *ab)
{
	ab->param->i = 0;
	ab->param->big = 0;
	ab->param->little = 0;
	ab->param->mid = 0;
}
