/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash_names_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:02:42 by arepnovs          #+#    #+#             */
/*   Updated: 2017/04/21 15:05:42 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_name_with_dash(char *line)
{
	int i;
	int dash;

	i = 0;
	dash = 0;
	while (line[i])
	{
		if (line[i] == '-')
			dash++;
		i++;
	}
	return (dash > 1) ? 1 : 0;
}

int		is_ok_name(t_lst *start, char *line)
{
	t_lst *t;

	t = start;
	while (t)
	{
		if (ft_strcmp(t->name, line) == 0)
			return (1);
		t = t->next;
	}
	return (-1);
}

char	*id_first_dash_name_in_link(t_lst *start, char *line)
{
	char	*name;
	int		i;
	int		ok;

	ok = -1;
	i = 0;
	while (ok < 0)
	{
		while (line[i])
		{
			if (line[i] == '-')
				break ;
			i++;
		}
		name = ft_strnew(i);
		name = strncpy(name, line, i);
		i++;
		if ((ok = is_ok_name(start, name)) < 0 && (size_t)i < ft_strlen(line))
			ft_strdel(&name);
		else if ((size_t)i >= ft_strlen(line))
			ft_exit(3);
	}
	return (name);
}

char	*id_second_dash_name_in_link(char *line, char *f_name)
{
	char	*name;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	while (line[i] == f_name[i])
		i++;
	i++;
	name = ft_strnew(len - i);
	len = 0;
	while (line[i])
	{
		name[len] = line[i];
		len++;
		i++;
	}
	return (name);
}
