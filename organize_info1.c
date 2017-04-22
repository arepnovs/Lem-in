/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:18:58 by arepnovs          #+#    #+#             */
/*   Updated: 2017/04/21 15:06:20 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst		*new_lst(char *name, int flag)
{
	t_lst	*new;

	new = (t_lst*)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->name = ft_strdup(name);
	new->place = flag;
	new->ants = 0;
	new->amount = 0;
	new->links = ft_strnew(0);
	new->next = NULL;
	return (new);
}

void		create_list(t_lst **start, char *line, int flag)
{
	char	*name;
	t_lst	*p;

	name = get_name(line, ' ');
	p = *start;
	if (!*start)
		*start = new_lst(name, flag);
	else
	{
		while (p)
		{
			if (p->next == NULL)
			{
				p->next = new_lst(name, flag);
				break ;
			}
			p = p->next;
		}
	}
	ft_strdel(&name);
}

void		set_links(t_lst **start, char *name, char *s_name)
{
	t_lst	*p;
	char	*t;
	int		f;

	f = 0;
	p = *start;
	while (p)
	{
		if (ft_strcmp(name, p->name) == 0)
		{
			t = p->links;
			p->links = ft_strjoin(p->links, s_name);
			ft_strdel(&t);
			t = p->links;
			p->links = ft_charjoin(p->links, '|');
			ft_strdel(&t);
			p->amount++;
			f++;
		}
		p = p->next;
	}
	if (f == 0)
		ft_exit(2);
}

void		get_links(t_lst **start, char *line)
{
	char	*name;
	char	*s_name;
	char	*line2;

	if (!(*start))
		ft_exit(-1);
	line2 = ft_strdup(line);
	if (check_name_with_dash(line) == 0)
	{
		name = get_name(line, '-');
		s_name = get_name(line2, 'z');
		set_links(start, name, s_name);
		set_links(start, s_name, name);
	}
	else
	{
		name = id_first_dash_name_in_link(*start, line);
		s_name = id_second_dash_name_in_link(line, name);
		set_links(start, name, s_name);
		set_links(start, s_name, name);
		ft_strdel(&s_name);
	}
	ft_strdel(&line2);
	ft_strdel(&name);
}
