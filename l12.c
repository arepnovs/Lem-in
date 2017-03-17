#include "lemin.h" 

char 	*r_name(t_lst *start, int place, char **name)
{
	t_lst *p;

	p = start->all;
	while(p)
	{
		if (place == p->place)
			*name = ft_strdup(p->name);
		p = p->next;
	}
	return (0);
}

t_pt	*new_way_prev(int path, t_lst *start, int dest, t_pt *way)
{
	//int i;
	t_pt *nw;

	//i = 1;
	nw = (t_pt*)malloc(sizeof(t_pt));
	while (start)
	{
		if (start->pos == path)
		{
			//nw->name = ft_strnew(0);
			//nw->name = ft_strjoin(nw->name, start->name);
			nw->name = ft_strdup(start->name);
			nw->ant = 0;
			nw->prev = way;
			nw->next = NULL;
		}
		start = start->next;
	}
	//i++;
	return(nw);
}

t_pt	*new_way(int path, t_lst *start, int dest)
{
	int i;
	t_pt *new;

	i = 1;
	new = (t_pt*)malloc(sizeof(t_pt));
	while (start)
	{
		if (start->pos == path)
		{
			new->name = ft_strdup(start->name);
			new->ant = 0;
			new->next = NULL;
		}
		start = start->next;
	}
	i++;
	return(new);
}

void	create_path(t_pt **way, t_dfs *path, t_lst *start, int i)
{
	//t_pt *way;
	t_pt *p;
	//int i;
	int j;

	//i = 0;
	j = 1;
	p = *way;
	if (!*way)
		*way = new_way(path->best_paths[i][0], start, path->dest);
	else
	{
		while (path->best_paths[i][j - 1] != path->dest)
		{
			while(p)
			{
				if (p->next == NULL)
				{
					p->next = new_way_prev(path->best_paths[i][j], start, path->dest, p);
					break;
				}
				p = p->next;
			}
			j++;
		}
	}
	//return(way);
}

void	print_path(t_lst *start, t_dfs *path)
{
	t_pt	**go;
	int i;

	i = 0;
	go = (t_pt **)malloc(sizeof(t_pt *) * path->amount);
	while (i < path->amount)
	{
		create_path(&go[i], path, start, i);
		i++;
	}
	i = 0;
	while (go[i])
	{
		printf("%s\n", go[i]->name);
		go[i] = go[i]->next;
	}
}



































