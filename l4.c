/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:25:44 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/22 12:29:11 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		row_char(int i, t_lst *p, t_lst *start)
{
	t_lst *p2;

	p2 = start;
	while (p2)
	{
		if (ft_strstr(p->links, p2->name))
		{
			if (i == p2->pos)
				return (1);
		}
		p2 = p2->next;
	}
	return (0);
}

int		*get_row(t_lst *start, int pos, int len)
{
	int		i;
	t_lst	*p;
	int		*row;

	p = start;
	i = 0;
	row = (int*)malloc(sizeof(int) * len + 1);
	while (i < pos)
	{
		p = p->next;
		i++;
	}
	i = 0;
	while (i < len)
	{
		row[i] = row_char(i, p, start);
		i++;
	}
	return (row);
}

void	matrix(t_lst **start)
{
	t_lst	*p1;
	int		len;
	int		**matrix;
	int		i;

	p1 = *start;
	len = lst_len(*start);
	p1->vert = len;
	matrix = (int**)malloc(sizeof(int*) * len);
	i = 0;
	while (i < len)
	{
		matrix[i] = get_row(*start, i, len);
		i++;
	}
	p1 = *start;
	all_paths_search(matrix, p1);
}
