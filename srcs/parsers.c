/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				parse_with_flags(char **v, t_push *ab)
{
	if (ab->program != 0 && v[1][0] && v[1][1] && v[1][0] == '-' &&
	v[1][1] == 't')
	{
		ab->flag_t = 1;
		ab->count_of_elements--;
	}
	else if (ab->program != 0 && v[1][0] && v[1][1] && v[1][0] == '-' &&
	v[1][1] == 'o')
	{
		ab->flag_o = 1;
		ab->count_of_elements--;
	}
	if (ab->count_of_elements < 1)
		return (0);
	if (ab->count_of_elements == 1)
	{
		if ((ab->flag_t || ab->flag_o) && !(parse_char(v[2], ab, 0)))
			return (0);
		else if ((!(ab->flag_t) && !(ab->flag_o)) && !(parse_char(v[1], ab, 0)))
			return (0);
	}
	else if (!(parse_argvs(ab->count_of_elements + 1, v, ab)))
		return (0);
	return (1);
}

int				make_list(t_push *ab, char *v)
{
	long long	a;
	long long	*ptr_num;

	ptr_num = &a;
	*ptr_num = ft_atoi_long_long(v);
	if (*ptr_num < -2147483648 || *ptr_num > 2147483647)
		return (0);
	ft_lstadd_end(&(ab->a), ft_lstnew(ptr_num, sizeof(int)));
	ab->num++;
	return (1);
}

int				parse_char(char *v, t_push *ab, int check)
{
	int			len;

	len = ft_strlen(v);
	while (ab->i_str < len)
	{
		while (ab->i_str < len && v[0] == ' ')
		{
			v++;
			ab->i_str++;
		}
		if (ab->i_str < len && (ft_isdigit(v[0]) || v[0] == '-'))
		{
			check = check_str(v, ft_strlen_sym(v, ' '));
			if (!(check) || !(make_list(ab, v)))
				return (0);
			v = v + check;
			ab->i_str = ab->i_str + check;
		}
		else if (ab->i_str < len && !(ft_isdigit(v[0])) && v[0] != ' ')
			return (0);
	}
	ab->memlist->len = ab->num;
	if (is_correct(ab->a) == 0)
		return (0);
	return (1);
}

int				parse_argvs(int x, char **v, t_push *ab)
{
	int			i;

	i = 1;
	if (ab->flag_t || ab->flag_o)
		i++;
	while (i - ab->flag_t - ab->flag_o < x)
	{
		if (!(check_str(v[i], ft_strlen(v[i]))))
			return (0);
		if (!(make_list(ab, v[i])))
			return (0);
		i++;
	}
	ab->num = i - 1 - ab->flag_t - ab->flag_o;
	ab->memlist->len = ab->num;
	if (is_correct(ab->a) == 0)
		return (0);
	return (1);
}
