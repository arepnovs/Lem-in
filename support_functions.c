/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:03:04 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/24 16:03:20 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	i = 0;
	free(p->stop);
	free(p->all_paths);
	free(p->visited);
}

int		lst_len(t_lst *start)
{
	int i;

	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

int		loc_dest(t_lst *start)
{
	while (start)
	{
		if (start->place == 9)
			return (start->pos);
		start = start->next;
	}
	return (0);
}

int		path_len(int *path, int dest)
{
	int	i;

	i = 0;
	while (path[i] != dest)
		i++;
	return (i + 1);
}

char	*restore_name(t_lst *start, int place)
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
