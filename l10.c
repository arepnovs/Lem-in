/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l10.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:34:40 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/24 16:05:39 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	get_stack_elements(int indx, int *way, t_dfs *path)
{
	int	i;

	i = 0;
	path->all_paths[path->i] = (int*)malloc(sizeof(int) * path->vert);
	while (i < indx)
	{
		path->all_paths[path->i][i] = way[i];
		i++;
	}
	path->i++;
}

void	remember_path(int start, int dest, t_dfs *path, int **matrix)
{
	int	i;

	path->visited[start] = 1;
	path->path[path->indx] = start;
	path->indx++;
	if (start == dest)
		get_stack_elements(path->indx, path->path, path);
	else
	{
		i = 0;
		while (i < path->vert)
		{
			if (path->visited[i] == 0 && matrix[start][i])
				remember_path(i, dest, path, matrix);
			i++;
		}
	}
	path->visited[start] = 0;
	path->indx--;
}

void	all_paths_search(int **matrix, t_lst *start)
{
	t_dfs	path;

	path.dest = loc_dest(start);
	path.vert = start->vert;
	path.path = (int*)malloc(sizeof(int) * start->vert);
	path.visited = (int*)malloc(sizeof(int) * start->vert);
	path.all_paths = (int**)malloc(sizeof(int*) * 10000);
	path.indx = 0;
	path.i = 0;
	ft_memset(path.visited, 0, sizeof(path.visited));
	remember_path(0, path.dest, &path, matrix);
	if (path.all_paths[0])
		choose_path(&path, start);//1 leaks
	else
		printf("Impossible to reach destination\n");
  free_dfs(&path);
  free(path.best_paths);
}
