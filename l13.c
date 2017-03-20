#include "lemin.h" 

int 	ppath_len(int *path, int dest)
{
	int i;

	i = 0;
	while (path[i] != dest)
		i++;
	return (i + 1);
}

int		*ant_am(int ants, int **p, t_dfs *path)
{
	int i;
	int len;
	float t;
	int *am;

	i = 0;
	am = (int *)malloc(sizeof(int) * path->amount);
	while (i < path->amount)
	{
		len = ppath_len(p[i], path->dest);
		if (len > ants)
		{
			am[i] = ants / len;
			t = (float)am[i] / (float)path->all_len;
			am[i] = (float)ants * (float)t;
		}
		else
		{
			t = (float)path->all_len /(float)ants;
			t = t * (float)path->all_len;
			am[i] = t * ants;
		}
		i++;
	}
	return(am);
}                                  

int		*all_len(int **p, t_dfs *path)
{
	int i;
	int *p_len;

	i = 0;
	p_len = (int *)malloc(sizeof(int) * path->amount);
	while (i < path->amount)
	{
		p_len[i] = ppath_len(p[i], path->dest) - 1;
		i++;
	}
	return(p_len);
}

int 	**dup_zero(int **p, t_dfs *path)
{
	int i;
	int j;
	int len;
	int **ants;

	i = 0;
	ants = (int **)malloc(sizeof (int*) * path->amount + 1);
	while (i < path->amount)
	{
		j = 0;
		len = ppath_len(p[i], path->dest);
		path->all_len = path->all_len + len;
		ants[i] = (int *)malloc(sizeof(int) * len);
		while (p[i][j - 1] != path->dest)
		{
			ants[i][j] = 0;
			j++;
		}
		i++;
	}
	return(ants);
}

char 	*gets_name(t_lst *start, int place)
{
	t_lst *p;

	p = start;
	while (p)
	{
		if (p->pos == place)
			return(p->name);
		p = p->next;
	}
	return(p->name);
}

int 	sh_len(int len, int *all, int amount)
{
	int i;

	i = 0;
	while (i < amount)
	{
		if (len > all[i])
			return(0);
		i++;
	}
	return(1);
}

void	ppath_path(t_lst *start, t_dfs *path)
{
	int **ants;
	//int *am;
	int *p_len;
	int *d_len;
	int ant;
	int i;
	int j;
	char *name;

	i = 0;
	path->all_len = 0;
	ant = 1;
	ants = dup_zero(path->best_paths, path);
	p_len = all_len(path->best_paths, path);
	d_len = all_len(path->best_paths, path);
	//am = ant_am(start->ants, path->best_paths, path);
	while(ant < start->ants + path->all_len)
	{
		while (i < path->amount)
		{
			/*need some optimization for better path choose*/
			j = p_len[i];
			while (j > 0)
			{
				if (ants[i][j - 1] != 0/* && sh_len(d_len[i], d_len, path->amount) == 1*/)
				{
					d_len[i]++;
					ants[i][j] = ants[i][j - 1];
					name = gets_name(start, path->best_paths[i][j]);
					printf("L%d->%s ", ants[i][j], name);
					ants[i][j - 1] = 0;
				}
				j--;
			}
			j = p_len[i];
			if (ants[i][1] == 0 && sh_len(d_len[i], d_len, path->amount) == 1)
			{
				if (ant <= start->ants)
				{
					ants[i][1] = ant;
					name = gets_name(start, path->best_paths[i][1]);
					printf("L%d->%s ", ants[i][1], name);
					d_len[i]++;
				}				
				ant++;
			}			
			i++;
		}
		if (sh_len(d_len[i], d_len, path->amount) == 1)
			printf("\n");
		i = 0;
	}
}

















































