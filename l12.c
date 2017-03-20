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
	t_pt *nw;

	nw = (t_pt*)malloc(sizeof(t_pt));
	while (start)
	{
		if (start->pos == path)
		{
			nw->name = ft_strdup(start->name);
			nw->if_ant = 0;
			nw->prev = way;
			nw->next = NULL;
		}
		start = start->next;
	}
	return(nw);
}

t_pt	*new_way(int path, t_lst *start, int dest)
{
	//int i;
	t_pt *new;

	//i = 1;
	new = (t_pt*)malloc(sizeof(t_pt));
	while (start)
	{
		if (start->pos == path)
		{
			new->name = ft_strdup(start->name);
			new->if_ant = 0;
			new->ant_num = 0;
			new->next = NULL;
		}
		start = start->next;
	}
	//i++;
	return(new);
}

void	create_path(t_pt **way, t_dfs *path, t_lst *start, int i)
{
	t_pt *p;
	int j;

	j = 1;
	while (path->best_paths[i][j - 1] != path->dest)
	{
		if (!*way)
			*way = new_way(path->best_paths[i][0], start, path->dest);
		p = *way;
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

int 	traffic_jam(t_pt *path)
{
	t_pt *p;
	p = path;
	while (p)
	{
		if (p->if_ant == 0)
			return(0);
		p = p->next;
	}
	return(1);
}

t_pt 	*go_end(t_pt *go)
{
	t_pt *end;

	end = go;
	while (end)
		end = end->next;
	return(end);
}

void	print_the_fuck(t_pt **go, int p)
{
	t_pt **end;
	int i;
	int j;

	j = 0;
	end = go;
	//end = go_end(end);
	i = end->len;
	while(i > 0)
	{
		end[j] = go_end(end[j]);
		if (end[j]->if_ant == 1)
			printf;
		
	}
}

void	fuck_the_path(t_pt **go, t_dfs *path, t_lst *start)
{
	int i;
	int ant;
	int f;
	t_pt **p;

	
	p = go;
	ant = 1;
	f = 0;
	while (ant <= start->ants)
	{
		
	}
}

int		pt_len(t_pt *start)
{
	int i;

	i = 0;
	while(start)
	{
		i++;
		start = start->next;
	}
	return(i);
}

void	what_len(t_pt **go, t_dfs *path)
{
	int i;

	i = 0;
	while (i < path->amount)
	{
		go[i]->len = pt_len(go[i]) - 1;
		i++;
	}

}

void	print_path(t_lst *start, t_dfs *path)
{
	t_pt	**go;
	int i;

	i = 0;
	go = (t_pt **)malloc(sizeof(t_pt *) * path->amount);
	while (i < path->amount)
	{
		//go[i] = (t_pt *)malloc(sizeof(t_pt) * path->amount);
		create_path(&go[i], path, start, i);
		i++;
	}
	what_len(go, path);
	fuck_the_path(go, path, start);
	/*i = 0;
	while (i < path->amount)
	{
		while (go[i])
		{
			printf("%s ", go[i]->name);
			go[i] = go[i]->next;
		}
		printf("\n");
		i++;
	}*/
}



































