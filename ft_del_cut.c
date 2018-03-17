/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:47:57 by okupin            #+#    #+#             */
/*   Updated: 2017/11/12 23:47:58 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_skip_delim(int i, char *str)
{
	while (str[i] == 'x')
		i++;
	return (i);
}

static char		*ft_smart_trim(char *s)
{
	size_t	i;
	size_t	scope_i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	scope_i = ft_strlen(s) - 1;
	i = ft_skip_delim(0, s);
	if (s[i] == '\0' || s[i] == '\n')
	{
		new = ft_strdup("e");
		return (new);
	}
	while (s[scope_i] == 'x')
		scope_i--;
	scope_i = scope_i - i;
	new = ft_strsub(s, i, scope_i + 1);
	return (new);
}

static int		ft_count_e(char **str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (str[i][0] != 'e')
			count++;
		i++;
	}
	return (count);
}

static	void	ft_finall(char **new, char **tmp)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (tmp[i][0] != 'e')
		{
			new[count] = ft_strdup(tmp[i]);
			count++;
		}
		free(tmp[i]);
		i++;
	}
	free(tmp[i]);
	new[count] = NULL;
}

char			**ft_del_cut(char **lines)
{
	char	*tmp[4];
	char	**new;
	int		i;

	i = 0;
	ft_mark_x(lines);
	ft_mark_y(lines);
	while (i < 4)
	{
		tmp[i] = ft_smart_trim(lines[i]);
		i++;
	}
	ft_arr_del(lines);
	free(lines);
	new = (char**)malloc(sizeof(char*) * (ft_count_e(tmp)) + 1);
	if (new == NULL)
		return (NULL);
	ft_finall(new, tmp);
	return (new);
}
