/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l11.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:35:50 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/22 12:38:22 by arepnovs         ###   ########.fr       */
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
	print_path(start, p);
	//sleep(20);

	/*int f = 0;
	char *name;
   int g;
   printf("------------------------------------\n");
   while (f < j)
   {
     g = 0;
     while (p->best_paths[f][g - 1] != p->dest)
     {
     	name = gets_name(start, p->best_paths[f][g]);
       printf("%s ", name);
       g++;
     }
    f++;
    printf("\n");
   }
   printf("------------------------------------\n");*/
}
