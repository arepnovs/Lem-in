#include "lemin.h"

int		check_finish(t_lst *start, char *links)
{
	int i;

	while (start)
	{
		if (start->place == 9)
		{
			if (!(ft_strstr(links, start->name)))
				return(0);
		}
		start = start->next;
	}
	return(1);
}

int		check_end(t_lst *start)
{
	int i;

	while (start)
	{
		if (start->was_here != 0)
			return(1);
		start = start->next;
	}
	return(0);
}

void	pathfind(t_lst **start)
{
	t_lst *p1;
	t_lst *p2;
	int i;
	int j;
	int finish;
	int len;
	char	**path;

	p1 = *start;
	p2 = p1->all;
	//len = list_len(*start);
	path = (char**)malloc(sizeof(char*) * 1000);
	i = 0;
	j = 0;
	/*while(p1)
	{
		path[i] = (char*)malloc(sizeof(char) * len);
		path[i] = ft_strjoin(path[i], p1->name);
		//i++;
		j = 0;
		path[i] = ft_strjoin(path[i], llinks[j]);
		//llinks[j]
		while(p2 && i < p1->amount)
		{
			if (strcmp(p1->llinks[j], p2->name) == 0)
			{
				p1->cost[i] = (ft_abs(p1->x - p2->x) + ft_abs(p1->y - p2->y));
				i++;
				p2 = p1->all;
			}
			else
				p2 = p2->next;
		}
		p2 = p1->all;
		p1 = p1->next;
	}*/
	while(p1->llinks[i])
	{
		while (check_end(*start) != 1)
		{
			path[j] = (char*)malloc(sizeof(char) * len);
			path[j] = ft_strjoin(path[j], p1->name);
			//if(p2->flag == 0)
				recu(p1, p2, &path[j], &j);
			j++;
		}
		i++;
	}
	//ft_arr_putstr(path);
}

void	recu(t_lst *p1, t_lst *p2, char **path, int *j)
{
	t_lst *p3;

	while (p2)
	{
		if (ft_strcmp(p1->llinks[(*j)], p2->name) == 0 && p2->was_here == 0)
		{
			//*path = ft_strjoin(*path, p3->name);
			if (check_finish(p1->all, p2->links) == 1)
			{
				p2->was_here++;
				//path[(*j)] = ft_strjoin(path[(*j)], p2->name);
			}
			p3 = p2->next;
			*path = ft_strjoin(*path, p3->name);
			if (p2->was_here == 0)
				recu(p2, p3, path, j);
			p2 = p1->all;
		}
		else
			p2 = p2->next;
		//(*j)++;
	}
	//i++;
}










