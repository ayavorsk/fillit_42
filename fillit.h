/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:07:10 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/04 15:07:10 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define SIZE 20

typedef struct		s_term
{
	char			**content;
	char			symbol;
	int				x[4];
	int				y[4];
	struct s_term	*next;
}					t_term;

t_term				*ft_set_cord(t_term *begin, char **str);
t_term				*ft_pars_list(char *str, int i);
void				ft_new_cord(t_term *list, int x, int y);
void				ft_mark_x(char **lines);
void				ft_mark_y(char **lines);
void				ft_replace_space(char **str, t_term *list);
void				ft_put_error(char ch);
void				ft_smart_lstdel(t_term **alst);
void				ft_arr_del(char **str);
void				ft_set_start(t_term *list, int size);

char				**ft_sort_space(char **str, t_term *list, int i, int j);
char				**ft_result(t_term *block, int max);
char				**ft_del_cut(char **lines);
char				**ft_create_map(int size);
int					ft_right_tetri(char *str);

#endif
