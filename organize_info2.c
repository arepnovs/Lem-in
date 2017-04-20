/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:24:45 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/22 12:25:24 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

char	*get_name(char *line, char f)
{
	char *t;

	if (f == ' ' || f == '-')
	{
		t = (f == ' ') ? ft_strchr(line, ' ') : ft_strchr(line, '-');
		*t = '\0';
		t++;
		while (*t)
		{
			if ((*t < '0' || *t > '9') && *t != ' ' && f == ' ')
				ft_exit(-1);
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

void	org_links(t_lst **start)
{
	t_lst *p;

	p = *start;
	while (p)
	{
		p->llinks = ft_strsplit(p->links, '|');
		p = p->next;
	}
}

void	org_pos(t_lst **start)
{
	t_lst	*p;
	int		i;

	i = 0;
	p = *start;
	while (p)
	{
		p->pos = i;
		i++;
		p = p->next;
	}
}

t_lst	*org_path(t_lst **start)
{
	t_lst *p1;
	t_lst *p2;
	t_lst *p3;

	p1 = *start;
	p2 = *start;
	if (p1->place != 1)
	{
		while (p1->place != 1)
		{
			p3 = p1;
			p1 = p1->next;
			p2 = p1->next;
		}
		p1->next = *start;
		start = &p1;
		p3->next = p2;
	}
	org_pos(start);
	return (*start);
}

void	set_ants(t_lst **start, int ants)
{
	t_lst *p;

	p = *start;
	while (p)
	{
		if (p->place == 1)
			p->ants = ants;
		p = p->next;
	}
}
