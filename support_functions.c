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

void	ft_exit(int f)
{
	if (f < 0)
		ft_putstr("ERROR INPUT\n");
	else if (f == 0)
		ft_putstr("No ants to move\n");
	else if (f == 2)
		ft_putstr("Not valid room\n");
	exit(0);
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
