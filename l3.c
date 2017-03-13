#include "lemin.h"

void	algo(t_lst **start)
{
	t_lst *p1;
	t_lst *p2;
	int i;
	char	*path;

	p1 = *start;
	path = ft_strnew(0);
	//p2 = p1->gr;
	while (p1)
	{
		if (p1->place == 1)
		{
			i = 0;
			while (p1->gr[i]->place != 9 || i < p1->gr[i]->amount)
			{
				p1 = p1->gr[i]->gr[i];
				path = ft_strjoin(path, p1->gr[i]->name);
				recu_alg(&p1, &path, &i);
				//path[i] = ft_strjoin(path[i], p1->gr[i]->name)
				//i++;
			}
		}
		p1 = p1->next;
	}
}

void	recu_alg(t_lst **p, char **path, int *i)
{
	t_lst **g;

	g = p;
	while (g[(*i)]->place != 9 || (*i) < g[(*i)]->amount)
	{
		
		*path = ft_strjoin(*path, g[(*i)]->name);
		(*i)++;
		p = &g[(*i)]->gr[(*i)];
		recu_alg(p, path, i);
	}
}