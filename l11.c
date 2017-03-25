/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l11.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:35:50 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/24 16:27:48 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		path_len(int *path, int dest)
{
	int	i;

	i = 0;
	while (path[i] != dest)
		i++;
	return (i + 1);
}

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

int		check_rep(int *a, int **b, int p, int dest)
{
	int i;
	int j;
	int k;

	k = 0;
	while (k < p)
	{
		i = 1;
		while (a[i] != dest)
		{
			j = 1;
			while (b[k][j] != dest)
			{
				if (a[i] == b[k][j])
					return (0);
				j++;
			}
			i++;
		}
		k++;
	}
	return (1);
}

void	choose_more_paths(t_lst *start, t_dfs *p, int j, int i)
{
	int len;
	int new_len;

	while (j < start->amount)
	{
		i = 0;
		new_len = 100000;
		while (i < p->i)
		{
			if (p->all_paths[i][1] != p->best_paths[j - 1][1]
				&& check_rep(p->all_paths[i], p->best_paths, j, p->dest) != 0
				&& (len = path_len(p->all_paths[i], p->dest)) < new_len)
			{
				if (j)
					new_len = len;
				p->best_paths[j] = p->all_paths[i];
			}
			i++;
		}
		if (!p->best_paths[j])
			break ;
		j++;
	}
	p->amount = j;
	print_path(start, p); //1 leaks after*/
}

void	choose_path(t_dfs *p, t_lst *start)
{
	int i;
	int j;
	int len;
	int new_len;

	i = 0;
	j = 0;
	new_len = 100000;
	p->best_paths = (int**)malloc(sizeof(int*) * p->i);
	while (i < p->i)
	{
		if ((len = path_len(p->all_paths[i], p->dest)) < new_len)
		{
			new_len = len;
			p->best_paths[j] = p->all_paths[i];
		}
		i++;
	}
	j++;
	p->all_len = 0;
	choose_more_paths(start, p, j, i);
}
