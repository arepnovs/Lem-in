/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:57:12 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/24 15:59:10 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst		*new_lst(t_lst *start, char *name, int flag)
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
	char	*line_dup;
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
			free(t);
			t = p->links;
			p->links = ft_charjoin(p->links, '|');
			free(t);
			p->amount++;
			f++;
		}
		p = p->next;
	}
	if (f == 0)
		ft_exit();
}

int			start_end_read(char **line)
{
	if (line[0][2] == 's')
	{
		while (line[0][0] == '#' || !ft_strchr(*line, ' '))
		{
			free(*line);
			get_next_line(0, line);
			if (line[0][0] == '#' || !ft_strchr(*line, ' '))
				need_next_line(line);
		}
		printf("%s\n", *line);
		return (1);
	}
	else
	{
		while (line[0][0] == '#' || !ft_strchr(*line, ' '))
		{
			free(*line);
			get_next_line(0, line);
			if (line[0][0] == '#' || !ft_strchr(*line, ' '))
				need_next_line(line);
		}
		printf("%s\n", *line);
		return (9);
	}
}

int			main(void)
{
	char	*line;
	t_lst	*start;
	int		ants;
	int		f;

	while ((get_next_line(0, &line)) > 0 && printf("%s\n", line))
	{
		if (line[1] == '#' && (line[2] == 's' || line[2] == 'e'))
		{
			f = start_end_read(&line);
			create_list(&start, line, f);
		}
		else if (ft_strchr(line, ' ') && line[0] != '#' && line[0] != 'L')
			create_list(&start, line, 0);
		else if (ft_strchr(line, '-') && line[0] != '#')
			get_links(&start, line);
		else if (!ft_strchr(line, ' ') && line[0] >= '0' && line[0] <= '9')
			ants = ft_atoi(line);
		else if (line[0] == 'b')
			break ;
		ft_strdel(&line);
	}
	org_links(&start);
	set_ants(&start, ants);
	start = org_path(&start);//5 leaks after
	matrix(&start);
	sleep(20);
	return (0);
}
