/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:13:59 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/04 15:14:00 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_tetrim_count(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n' && str[i + 1] == '\n'))
			j++;
		if (str[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}

static int			ft_right_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 19] != '\n')
			return (1);
		if (str[i + 20] != '\0' && str[i + 20] != '\n')
			return (0);
		i += 21;
	}
	return (1);
}

static char			*ft_read(char *av)
{
	int		fd;
	int		fr;
	char	buff[600];
	char	*str;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_put_error('E');
	fr = read(fd, buff, 600);
	if (fr > 545)
		ft_put_error('E');
	if (fr < 20)
		ft_put_error('E');
	buff[fr] = '\0';
	if ((str = ft_strdup(buff)) == NULL)
		ft_put_error('E');
	close(fd);
	return (str);
}

int					main(int argc, char **argv)
{
	t_term	*list;
	char	*str;

	if (argc != 2)
		ft_put_error('U');
	if (ft_right_str(str = ft_read(argv[1])) != 1)
		ft_put_error('E');
	if ((list = ft_pars_list(str, ft_tetrim_count(str))) == NULL)
		ft_put_error('E');
	ft_set_start(list, ft_tetrim_count(str));
	ft_smart_lstdel(&list);
	return (0);
}
