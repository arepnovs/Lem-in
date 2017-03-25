/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:03:04 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/24 16:03:20 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_exit(void)
{
	printf("ERROR INPUT\n");
	exit(0);
}

void		need_next_line(char **line)
{
	printf("%s\n", *line);
	free(*line);
}

char		*get_name(char *line, char f)
{
	char *t;
	char *name;
	char *s_name;

	if (f == ' ' || f == '-')
	{
		t = (f == ' ') ? ft_strchr(line, ' ') : ft_strchr(line, '-');
		*t = '\0';
		t++;
		while (*t)
		{
			if ((*t < '0' || *t > '9') && *t != ' ' && f == ' ')
				ft_exit();
			t++;
		}
		line = ft_strdup(line);
		return (line);
	}
	else
	{
		t = ft_strchr(line, '-');
		t++;
		line = t;
		return (line);
	}
}

char	*restore_name(t_lst *start, int place)
{
	t_lst *p;

	p = start;
	while (p)
	{
		if (p->pos == place)
			return (p->name);
		p = p->next;
	}
	return (p->name);
}

void		get_links(t_lst **start, char *line)
{
	char	*name;
	char	*s_name;
	char	*line2;

	line2 = ft_strdup(line);
	name = get_name(line, '-');
	s_name = get_name(line2, 'z');
	set_links(start, name, s_name);
	set_links(start, s_name, name);
	ft_strdel(&line2);
	ft_strdel(&name);
}
