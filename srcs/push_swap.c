/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			help_print(t_push *ab)
{
	if (ab->flag_o && ab->program == 1)
	{
		ab->color = SALAT;
		print_lists(ab);
		if (is_order_up(ab->a) == 1)
			ft_printf("%s!sorted!%s\n", SALAT, ENDC);
		ft_printf("instructions = %d\n", ab->rec);
		ft_printf("length = %d\n", ab->num);
		ft_printf("arguments = %d\n", ab->count_of_elements);
	}
}

int				main(int argc, char **argv)
{
	t_push		*ab;

	if (argc > 1)
	{
		if (!(ab = init_push(1, argc)))
			return (0);
		if (!(parse_with_flags(argv, ab)))
		{
			clean_push(ab);
			free(ab);
			ft_printf("Error\n");
			return (0);
		}
		if (ab->flag_t || ab->flag_o)
			print_lists(ab);
		sort_start(ab);
		help_print(ab);
		clean_push(ab);
		free(ab);
	}
	return (0);
}
