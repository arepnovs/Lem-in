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
	char *name;
	char *s_name;

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
	char    *line_dup;
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

void	set_links(t_lst **start, char *name, char *s_name)
{
	t_lst *p;
	char *t;
	char *l;

	p = *start;
	while (p)
	{
		if (ft_strcmp(name, p->name) == 0)
		{
			t = p->links;
			//l = s_name;
			p->links = ft_strjoin(p->links, s_name);
			free(t);
			//free(l);
			t = p->links;
			p->links = ft_charjoin(p->links, '|');
			free(t);
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
	ft_strdel(&line2);
	ft_strdel(&name);
}

/*int	start_end_check(char **line)
{
	if (line[0][2] == 's')
		{
			while (line[0][0] == '#' || !ft_strchr(*line, ' '))
			{
				free(*line);
				get_next_line(0, line);
				if (line[0][0] == '#' || !ft_strchr(*line, ' '))
				{
					printf("%s\n", *line);
					free(*line);
				}
			}
			printf("%s\n", *line);
			return(1);
			//create_list(&start, line, 1);
		}
		else
		{
			while (line[0][0] == '#' || !ft_strchr(*line, ' '))
			{
				free(*line);
				get_next_line(0, line);
				if (line[0][0] == '#' || !ft_strchr(*line, ' '))
				{
					printf("%s\n", *line);
					free(*line);
				}
			}
			printf("%s\n", *line);
			return(9);
			//create_list(&start, line, 9);
		}
}*/

int		main(void)
{
	char	*line;
	t_lst	*start;
	int		ants;
	int		ret;
	int f;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		printf("%s\n", line);
		/*if (line[1] == '#' && (line[2] == 's' || line[2] == 'e'))
		{
			f = start_end_check(&line);
			create_list(&start, line, f);
		}*/
		if (line[2] == 's' && line[1] == '#')
		{
			while (line[0] == '#' || !ft_strchr(line, ' '))
			{
				free(line);
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
				free(line);
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
		ft_strdel(&line);
	}
	org_links(&start);
	set_ants(&start, ants);
	start = org_path(&start);
	matrix(&start);
	
	return (0);
}
