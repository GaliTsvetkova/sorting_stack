/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:35:44 by ljacquet          #+#    #+#             */
/*   Updated: 2019/10/23 16:22:36 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_next_list(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *list;
	if (!first)
		return ;
	if (first->next)
		second = first->next;
	else
		return ;
	if (second->next)
		third = second->next;
	else
		third = NULL;
	second->next = first;
	first->next = third;
	*list = second;
}
