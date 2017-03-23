/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l13.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:43:40 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/22 12:47:58 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*all_len(int **p, t_dfs *path)
{
	int	i;
	int	*p_len;

	i = 0;
	p_len = (int *)malloc(sizeof(int) * path->amount);
	while (i < path->amount)
	{
		p_len[i] = path_len(p[i], path->dest) - 1;
		i++;
	}
	return (p_len);
}

int		**dup_zero(int **p, t_dfs *path)
{
	int i;
	int j;
	int len;
	int **ants;

	i = 0;
	ants = (int **)malloc(sizeof(int*) * path->amount + 1);
	while (i < path->amount)
	{
		j = 0;
		len = path_len(p[i], path->dest);
		path->all_len = path->all_len + len;
		ants[i] = (int *)malloc(sizeof(int) * len);
		while (j != path->dest)
		{
			ants[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ants);
}

char	*gets_name(t_lst *start, int place)
{
	t_lst *p;

	p = start;
	while (p)
	{
		if (p->pos == place)
			return (p->name);
		p = p->next;
	}
	return (p->name);
}

void	free_dfs(t_dfs **path)
{
	int i;
	t_dfs	*p;

	i = 0;
	p = *path;
	free(p->path);
	while (i < p->i)
	{
		free(p->all_paths[i]);
		i++;
	}
	free(p->all_paths);
	free(p->visited);
}

void	print_path(t_lst *start, t_dfs *path)
{
	int		**ants;
	int		*p_len;
	int		ant;
	int		i;
	int		j;
	char	*name;
	int		f;

	i = 0;
	path->all_len = 0;
	ant = 1;
	f = 0;
	ants = dup_zero(path->best_paths, path);
	p_len = all_len(path->best_paths, path);
	printf("\n");
	while (ant < start->ants + path->all_len)
	{
		while (i < path->amount)
		{
			j = p_len[i];
			while (j > 0)
			{
				if (ants[i][j - 1] != 0)
				{
					ants[i][j] = ants[i][j - 1];
					name = gets_name(start, path->best_paths[i][j]);
					printf("L%d->%s ", ants[i][j], name);
					f++;
					ants[i][j - 1] = 0;
				}
				j--;
			}
			j = p_len[i];
			if (ants[i][1] == 0)
			{
				if (ant <= start->ants)
				{
					ants[i][1] = ant;
					name = gets_name(start, path->best_paths[i][1]);
					printf("L%d->%s ", ants[i][1], name);
					f++;
				}
				ant++;
			}
			i++;
		}
		if (f != 0)
			printf("\n");
		f = 0;
		i = 0;
	}
	//sleep(20);
	/*while (f < path->amount)
	{
		i = 0;
		while (i < path->vert)
		{
			free(ants[i]);
			i++;
		}
		f++;
	}
	free(ants);*/

	free_dfs(&path);
}
