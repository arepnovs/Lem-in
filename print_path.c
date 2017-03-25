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
		while (p[i][j - 1] != path->dest)
		{
			ants[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ants);
}

void	free_dfs(t_dfs *path)
{
	int		i;
	t_dfs	*p;

	i = 0;
	p = path;
	free(p->path);
	while (i < 10000)
	{
		free(p->all_paths[i]);
		i++;
	}
	free(p->all_paths);
	free(p->visited);
}

int		print_move(int len, int **ants, t_dfs *path, t_lst *start)
{
	int		f;
	char	*name;

	f = 0;
	while (len > 0)
	{
		if (ants[0][len - 1] != 0)
		{
			ants[0][len] = ants[0][len - 1];
			name = restore_name(start, path->best_paths[path->l][len]);
			put_move(ants[0][len], name, path->l);
			f++;
			ants[0][len - 1] = 0;
		}
		len--;
	}
	return (f);
}

int		actually_print_path(t_lst *start, t_dfs *path, int **ants, int *len)
{
	int		f;
	char	*name;

	f = 0;
	while (path->l < path->amount)
	{
		f = print_move(len[path->l], &ants[path->l], path, start);
		if (ants[path->l][1] == 0)
		{
			if (path->ant <= start->ants)
			{
				ants[path->l][1] = path->ant;
				name = restore_name(start, path->best_paths[path->l][1]);
				put_move(ants[path->l][1], name, path->l);
				f++;
			}
			path->ant++;
		}
		else if (path->best_paths[path->l][1] == path->dest && ants[path->l][1] != 0)
		{
			if (path->ant <= start->ants)
			{
				ants[path->l][1] = path->ant;
				name = restore_name(start, path->best_paths[path->l][1]);
				put_move(ants[path->l][1], name, path->l);
			}
			path->ant++;
		}
		path->l++;
	}
	if (f != 0)
		ft_putstr("\n");
	f = 0;
	path->l = 0;
	return (path->ant);
}

void	print_path(t_lst *start, t_dfs *path)
{
	int		**ants;
	int		*len;

	path->l = 0;
	path->ant = 1;
	ants = dup_zero(path->best_paths, path);
	len = all_len(path->best_paths, path);
	ft_putstr("\n");
	while (path->ant < start->ants + path->all_len)
		path->ant = actually_print_path(start, path, ants, len);
	path->l = -1;
	while (++path->l < path->amount)
		free(ants[path->l]);
	free(ants);
	free(len);
}
