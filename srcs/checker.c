/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <ljacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int argc, char **argv)
{
	t_push		*ab;

	if (argc > 1)
	{
		if (!(ab = init_push(2, argc)))
			return (0);
		if (!(parse_with_flags(argv, ab)) || check_actions(ab) == 0)
		{
			clean_push(ab);
			free(ab);
			ft_printf("Error\n");
			return (0);
		}
		check_sort(ab);
		clean_push(ab);
		free(ab);
	}
	return (0);
}

char			*reading_file(void)
{
	int			readed;
	char		*buff;
	char		*tmp;
	char		*tmp2;

	tmp = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER + 1)))
		|| read(0, buff, 0) < 0)
		return (NULL);
	while ((readed = read(0, buff, BUFFER)) > 0)
	{
		buff[readed] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buff);
		else
		{
			tmp2 = ft_strdup(tmp);
			ft_strdel(&tmp);
			tmp = ft_strjoin(tmp2, buff);
			ft_strdel(&tmp2);
		}
	}
	ft_strdel(&buff);
	return (tmp);
}
