#include "lemin.h"

int		get_coord(char *line, int f)
{
	char *t;

	if (f == 1)
	{
		t = ft_strchr(line, ' ');
		return(ft_atoi(t));
	}
	else
	{
		t = ft_strchr(line, ' ');
		t++;
		t = ft_strchr(t, ' ');
		return(ft_atoi(t));
	}
}

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
		return(line);
	}
}

t_lst	*new_lst(t_lst *start, char *name, int flag, char *line)
{
	t_lst	*new;

	new = (t_lst*)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->name = ft_strnew(0);
	new->name = ft_strjoin(new->name, name);
	new->place = flag;
	new->ants = 0;
	new->was_here = 0;
	new->amount = 0;
	new->value = (flag == 1) ? 0 : 9999999;
	new->links = ft_strnew(0);
	new->y = get_coord(line, 1);
	new->x = get_coord(line, 2);
	new->next = NULL;
	return (new);
}

void	create_list(t_lst **start, char *line, int flag)
{
	char	*name;
	char 	*coord;
	t_lst	*p;

	coord = ft_strdup(line);
	name = get_name(line, ' ');
	p = *start;
	if (!*start)
	{
		*start = new_lst(*start, name, flag, coord);
	}
	else
	{
		while (p)
		{
			if (p->next == NULL)
			{
				p->next = new_lst(*start, name, flag, coord);
				break;
			}
			p = p->next;
		}
		p->next = new_lst(*start, name, flag, coord);
	}
}

void	set_ants(t_lst **start, int ants)
{
	t_lst *p;

	p = *start;
	while(p)
	{
		if (p->place == 1)
			p->ants = ants;
		p = p->next;
	}

}

void	set_links(t_lst **start, char *name, char *s_name)
{
	t_lst *p;

	p = *start;
	while(p)
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
	char 	*name;
	char	*s_name;
	char	*line2;

	line2 = ft_strdup(line);
	name = get_name(line, '-');
	s_name = get_name(line2, 'z');
	set_links(start, name, s_name);
	set_links(start, s_name, name);
}

void	add_all(t_lst **start)
{
	t_lst *p;

	p = *start;
	while(p)
	{
		p->all = *start;
		p = p->next;
	}
}

int		main(void)
{
	char	*line;
	t_lst	*start;
	t_lst	*p;
	int 	ants;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[2] == 's' && line[1] == '#')
		{
			get_next_line(0, &line);
			create_list(&start, line, 1);
		}
		else if (line[2] == 'e' && line[1] == '#')
		{
			get_next_line(0, &line);
			create_list(&start, line, 9);
		}
		else if (ft_strchr(line, ' ') && line[0] != '#')
			create_list(&start, line, 0);
		else if (ft_strchr(line, '-') && line[0] != '#')
			get_links(&start, line);
		else if (ft_strchr(line, ' ') == NULL && line[0] >= '0' && line[0] <= '9')
			ants = ft_atoi(line);
		else if (line[0] == 'b')
			break;
		free(line);
	}
	start->ants = ants;
	set_ants(&start, ants);
	org_links(&start);
	start = org_path(&start);
	add_all(&start);
	matrix(&start);
	p = start;
	printf("ants = %d\n", ants);
	while(p)
	{
		printf("name = %s, (%d, %d), place = %d, ant = %d, links = %s, amount = %d, pos = %d\n", 
			p->name, p->y, p->x, p->place, p->ants, p->links, p->amount, p->pos);
		p = p->next;
	}
	/*int i;
	t_lst *p1;
	//write(1, "AAA\n", 4);
	p = start;
	p1 = *p->gr;
	while(p)
	{
		i = 0;
		while(i < p->amount)
		{
			printf("name = %s\n", p->gr[i]->name);
			i++;
		}
		//p1 = p1->next;
		printf("--------\n");		
		p = p->next;
	}*/
	return (0);
}

/*1 4 11
0 12 13 11
0 2 6 8 11
0 3 9 10 11*/






























