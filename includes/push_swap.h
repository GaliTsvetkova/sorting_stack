/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:56:21 by ljacquet          #+#    #+#             */
/*   Updated: 2020/10/01 14:48:30 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER 10

typedef struct		s_cut
{
	int				beg2;
	int				beg3;
	int				med;
	int				prev_end;
	int				end;
	int				i;
	int				big;
	int				little;
	int				mid;
}					t_cut;

typedef struct		s_mem
{
	int				num;
	int				index;
	int				len;
	struct s_mem	*next;
}					t_mem;

typedef struct		s_push
{
	int				num;
	int				couple;
	int				program;
	int				count_of_elements;
	int				flag_t;
	int				flag_o;
	t_list			*a;
	t_list			*b;
	t_list			*help;
	t_list			*help_del;
	int				first;
	t_mem			*memlist;
	t_cut			*param;
	char			*actions;
	int				rec;
	int				i_str;
	char			*color;
}					t_push;

t_push				*init_push(int program, int argc);
int					parse_with_flags(char **v, t_push *ab);
void				set_param(t_push *ab);
void				clean_push(t_push *ab);
void				clean_help(t_push *ab);
int					parse_char(char *v, t_push *ab, int check);
int					parse_argvs(int ac, char **v, t_push *mlist1);
int					check_str(char *v, int len);
char				*reading_file(void);
int					is_order_up(t_list *mlist);
int					is_order_cut(t_list *x, int index, int len);
int					is_correct(t_list *mlist);
int					is_over(char *s, int x);
int					swap_ab(t_push *ab, int mod, int print);
int					push_ab(t_push *ab, int mod, int print);
int					rotate_ab(t_push *ab, int mod, int print);
int					rev_rotate_ab(t_push *ab, int mod, int print);
void				algo_bubble(t_list *x);
void				print_lists(t_push *ab);
void				ft_lstlast_to_head(t_list **x);
void				ft_lsthead_to_last(t_list **x);
void				ft_lstfirsta_to_b(t_list **a, t_list **b);
void				sort0(t_push *ab);
void				find_param(t_push *ab, int stack, int index, int len);
int					find_last(t_list *x);
void				find_cuts(t_push *ab, int len);
t_list				*ft_cp_cut_list(t_list *x, int index, int len);
void				record_mem_1(t_push *ab, int big, int little);
t_mem				*mem_new(int len, int num, int index);
void				mem_add_with_nol(t_push *ab, t_mem *newmem);
void				record_mem_2(t_push *ab, int big, int little, int mod);
void				mem_add(t_push *ab, t_mem *newmem);
void				record_mem_0(t_push *ab, int big, int little, int mid);
void				sort_start(t_push *ab);
void				sort1(t_push *ab);
void				sort2(t_push *ab);
void				sort3(t_push *ab);
void				sort_less_1(t_push *ab);
void				sort_less_1_4_1(t_push *ab);
void				sort_less_1_4_2(t_push *ab);
void				sort_less_1_4_3(t_push *ab);
void				sort_less_1_4_4(t_push *ab);
void				sort_less_1_4_5(t_push *ab);
void				sort_less_1_3_1(t_push *ab);
void				sort_less_1_3_2(t_push *ab);
void				sort_less_1_3_3(t_push *ab);
void				sort_less_1_3_4(t_push *ab);
void				sort_less_1_3_5(t_push *ab);
void				sort_less_1_2(t_push *ab);
void				sort_less_2(t_push *ab);
void				sort_less_2_4_1(t_push *ab);
void				sort_less_2_4_2(t_push *ab);
void				sort_less_2_3_1(t_push *ab);
void				sort_less_2_3_2(t_push *ab);
void				sort_less_2_2(t_push *ab);
void				sort_less_3(t_push *ab);
void				sort_less_first_3(t_push *ab);
void				sort_less_3_4_1(t_push *ab);
void				sort_less_3_3_1(t_push *ab);
void				sort_footer_big(t_push *ab);
void				sort_footer_end(t_push *ab);
void				sort_footer_end2(t_push *ab);
int					check_actions(t_push *ab);
void				check_sort(t_push *ab);
void				help_while_0_1(t_push *ab);
void				help_while_0_2(t_push *ab, int mod);
void				help_while_1_1(t_push *ab, int mod);
void				help_while_1_2(t_push *ab, int mod);
void				help_check_1(t_push *ab);
void				help_while_2_1(t_push *ab);
void				help_while_2_2(t_push *ab, int mod);
void				help_while_3_1(t_push *ab, int mod);
void				sort_less_help_1(t_push *ab, int mod);

#endif
