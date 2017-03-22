/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:22:53 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/22 12:24:33 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_name(char *line, char f)
{
	char *t;

	if (f == ' ' || f == '-')
	{
		t = (f == ' ') ? ft_strchr(line, ' ') : ft_strchr(line, '-');
		*t = '\0';
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

t_lst	*new_lst(t_lst *start, char *name, int flag)
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

void	create_list(t_lst **start, char *line, int flag)
{
	char	*name;
	t_lst	*p;

	name = get_name(line, ' ');
	p = *start;
	if (!*start)
		*start = new_lst(*start, name, flag);
	else
	{
		while (p)
		{
			if (p->next == NULL)
			{
				p->next = new_lst(*start, name, flag);
				break ;
			}
			p = p->next;
		}
		p->next = new_lst(*start, name, flag);
	}
	ft_strdel(&name);
}

void	set_links(t_lst **start, char *name, char *s_name)
{
	t_lst *p;

	p = *start;
	while (p)
	{
		if (ft_strcmp(name, p->name) == 0)
		{
			p->links = ft_strjoin(p->links, s_name);
			p->links = ft_charjoin(p->links, '|');
			p->amount++;
		}
		p = p->next;
	}
}

void	get_links(t_lst **start, char *line)
{
	char	*name;
	char	*s_name;
	char	*line2;

	line2 = ft_strdup(line);
	name = get_name(line, '-');
	s_name = get_name(line2, 'z');
	set_links(start, name, s_name);
	set_links(start, s_name, name);
}

void	free_lst(t_lst **start)
{
	t_lst *p;
	int i;

	i = 0;
	p = *start;
	while (p)
	{
		ft_strdel(&(p->name));
		ft_strdel(&(p->links));
		while (i < p->amount)
		{
			free(p->llinks[i]);
			i++;
		}
		free(p->llinks);
		free(p);
		p = p->next;
	}
}

int		main(void)
{
	char	*line;
	t_lst	*start;
	t_lst	*p;
	int		ants;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		printf("%s\n", line);
		if (line[2] == 's' && line[1] == '#')
		{
			while (line[0] == '#' || !ft_strchr(line, ' '))
			{
				get_next_line(0, &line);
				if (line[0] == '#' || !ft_strchr(line, ' '))
				{
					printf("%s\n", line);
					free(line);
				}
			}
			printf("%s\n", line);
			create_list(&start, line, 1);
		}
		else if (line[2] == 'e' && line[1] == '#')
		{
			while (line[0] == '#' || !ft_strchr(line, ' '))
			{
				get_next_line(0, &line);
				if (line[0] == '#' || !ft_strchr(line, ' '))
				{
					printf("%s\n", line);
					free(line);
				}
			}
			printf("%s\n", line);
			create_list(&start, line, 9);
		}
		else if (ft_strchr(line, ' ') && line[0] != '#')
			create_list(&start, line, 0);
		else if (ft_strchr(line, '-') && line[0] != '#')
			get_links(&start, line);
		else if (!ft_strchr(line, ' ') && line[0] >= '0' && line[0] <= '9')
			ants = ft_atoi(line);
		else if (line[0] == 'b')
			break ;
		free(line);
	}
	org_links(&start);
	set_ants(&start, ants);
	start = org_path(&start);
	matrix(&start);
	free_lst(&start);
	sleep(30);
	return (0);
}
