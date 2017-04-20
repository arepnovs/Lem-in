/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:18:58 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/25 15:19:45 by arepnovs         ###   ########.fr       */
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

int check_name_with_dash(char *line)
{
	int i;
	int dash;

	i = 0;
	dash = 0;
	while(line[i])
	{
		if (line[i] == '-')
			dash++;
		i++;
	}
	return (dash > 1) ? 1 : 0;
}

int 	is_ok_name(t_lst *start, char *line)
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

char *id_first_dash_name_in_link(t_lst *start, char *line)
{
	char *name;
	char *t;
	int i;
	int ok;

	ok = -1;
	i = 0;
	while (ok < 0)
	{
		while (line[i])
		{
			if (line[i] == '-')
				break;
			i++;
		}
		name = ft_strnew(i);
		name = strncpy(name, line, i);
		i++;
		if ((ok = is_ok_name(start, name)) < 0)
			ft_strdel(&name);
	}
	return(name);
}

char *id_second_dash_name_in_link(t_lst *start, char *line, char *f_name)
{
	char *name;
	int i;
	int len;

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
	return(name);
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
	}
	else
	{
		name = id_first_dash_name_in_link(*start, line);
		s_name = id_second_dash_name_in_link(*start, line, name);
	}
	set_links(start, name, s_name);
	set_links(start, s_name, name);
	ft_strdel(&line2);
	ft_strdel(&name);
}
