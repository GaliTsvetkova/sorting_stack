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

void	push_help(t_push *ab, int mod, int print)
{
	if (mod == 1)
	{
		swap_ab(ab, 1, 0);
		swap_ab(ab, 2, 0);
		ab->rec--;
		if (print == 1)
			ft_printf("ss\n");
	}
	if (mod == 2)
	{
		rotate_ab(ab, 1, 0);
		rotate_ab(ab, 2, 0);
		ab->rec--;
		if (print == 1)
			ft_printf("rr\n");
	}
	if (mod == 3)
	{
		rev_rotate_ab(ab, 1, 0);
		rev_rotate_ab(ab, 2, 0);
		ab->rec--;
		if (print == 1)
			ft_printf("rrr\n");
	}
}

int		swap_ab(t_push *ab, int mod, int print)
{
	if (mod == 1)
	{
		ft_swap_next_list(&(ab)->a);
		ab->rec++;
		if (print == 1)
			ft_printf("sa\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 2)
	{
		ft_swap_next_list(&(ab)->b);
		ab->rec++;
		if (print == 1)
			ft_printf("sb\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 3)
	{
		push_help(ab, 1, print);
		if (ab->flag_t)
			print_lists(ab);
	}
	return (0);
}

int		push_ab(t_push *ab, int mod, int print)
{
	if (mod == 1 && ab->b)
	{
		ft_lstfirsta_to_b(&(ab)->b, &(ab)->a);
		ab->rec++;
		if (print == 1)
			ft_printf("pa\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 2 && ab->a)
	{
		ft_lstfirsta_to_b(&(ab)->a, &(ab)->b);
		ab->rec++;
		if (print == 1)
			ft_printf("pb\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	return (0);
}

int		rotate_ab(t_push *ab, int mod, int print)
{
	if (mod == 1 && ab->a)
	{
		ft_lsthead_to_last(&(ab->a));
		ab->rec++;
		if (print == 1)
			ft_printf("ra\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 2 && ab->b)
	{
		ft_lsthead_to_last(&(ab->b));
		ab->rec++;
		if (print == 1)
			ft_printf("rb\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 3 && ab->b && ab->a)
	{
		push_help(ab, 2, print);
		if (ab->flag_t)
			print_lists(ab);
	}
	return (0);
}

int		rev_rotate_ab(t_push *ab, int mod, int print)
{
	if (mod == 1 && ab->a)
	{
		ft_lstlast_to_head(&(ab->a));
		ab->rec++;
		if (print == 1)
			ft_printf("rra\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 2 && ab->b)
	{
		ft_lstlast_to_head(&(ab->b));
		ab->rec++;
		if (print == 1)
			ft_printf("rrb\n");
		if (ab->flag_t)
			print_lists(ab);
	}
	if (mod == 3 && ab->b && ab->a)
	{
		push_help(ab, 3, print);
		if (ab->flag_t)
			print_lists(ab);
	}
	return (0);
}
