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

void	print_move(int len, int **ants, t_dfs *path, t_lst *start)
{
	char	*name;

	while (len > 0)
	{
		if (ants[0][len - 1] != 0)
		{
			ants[0][len] = ants[0][len - 1];
			name = restore_name(start, path->best_paths[path->l][len]);
			put_move(ants[0][len], name, path->l);
			path->f++;
			ants[0][len - 1] = 0;
		}
		len--;
	}
}

int		*when_stop(t_dfs *path, int *len, t_lst *start)
{
	int i;
	int *stop;

	i = -1;
	stop = (int *)malloc(sizeof(int) * path->amount + 1);
	while (++i < path->amount + 1)
		stop[i] = 0;
	i = 0;
	while (i < path->amount)
	{
		if (len[i] > 0)
		{
			if (i > 1)
				stop[i] = stop[i - 1] + len[i] - len[i - 1] + i - 1;
			else if (i == 1)
				stop[i] = len[1] - len[0];
		}
		i++;
	}
	i = -1;
	while (++i < path->amount)
		stop[i] = (i == 0) ? start->ants : start->ants - stop[i];
	return (stop);
}

void	print_put(t_lst *start, t_dfs *path, int i, int **ants)
{
	char *name;

	if (ants[i][1] == 0 && path->ant <= path->stop[i])
	{
		if (path->ant <= start->ants)
		{
			ants[i][1] = path->ant;
			name = restore_name(start, path->best_paths[i][1]);
			put_move(ants[i][1], name, i);
			path->f++;
		}
		path->ant++;
	}
	else if (path->best_paths[i][1] == path->dest
		&& ants[i][1] != 0 && path->ant <= path->stop[i])
	{
		if (path->ant <= start->ants)
		{
			ants[i][1] = path->ant;
			name = restore_name(start, path->best_paths[i][1]);
			put_move(ants[i][1], name, i);
		}
		path->ant++;
	}
}

int		actually_print_path(t_lst *start, t_dfs *path, int **ants, int *len)
{
	path->f = 0;
	while (path->l < path->amount)
	{
		print_move(len[path->l], &ants[path->l], path, start);
		print_put(start, path, path->l, ants);
		path->l++;
	}
	if (path->f != 0)
		ft_putstr("\n");
	else
		path->ant++;
	path->f = 0;
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
	path->stop = when_stop(path, len, start);
	ft_putstr("\n");
	while ((unsigned long)path->ant <= (unsigned long)(start->ants
		+ path->all_len))
		path->ant = actually_print_path(start, path, ants, len);
	path->l = -1;
	while (++path->l < path->amount)
		free(ants[path->l]);
	free(ants);
	free(len);
}
