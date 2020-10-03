/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:35:44 by ljacquet          #+#    #+#             */
/*   Updated: 2019/10/23 16:22:36 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *bl;

	bl = *alst;
	if (bl == NULL)
		*alst = new;
	else if (bl->content == NULL)
		*alst = new;
	else
	{
		while (bl->next != NULL)
			bl = bl->next;
		bl->next = new;
	}
}
