/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:08:34 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/27 20:08:39 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_exit(int f)
{
	if (f < 0)
		ft_putstr("ERROR INPUT\n");
	else if (f == 0)
		ft_putstr("No ants to move\n");
	else if (f == 2)
		ft_putstr("Not valid room\n");
	exit(0);
}

void		validation(char *line)
{
	int i;
	int f;

	i = 0;
	f = 0;
	if (line[0] == '\0')
		ft_exit(-1);
	else if (line[0] != '#' && !ft_strchr(line, '-'))
	{
		while (line[i])
		{
			if (line[i] == ' ' && line[i - 1] != ' ')
				f++;
			if (line[i + 1] == '\0' && line[i] != ' ')
				f++;
			if (line[i + 1] == '\0' && line[i] == ' ' && f == 1)
				f++;
			i++;
		}
		if ((f != 3 && f != 1) || (f == 1 && (line[0] < '0' || line[0] > '9')))
			ft_exit(-1);
	}
}

void		start_end_check(t_lst *start)
{
	t_lst	*p;
	int		f;

	f = 0;
	p = start;
	while (p)
	{
		if (p->place == 1 || p->place == 9)
			f++;
		p = p->next;
	}
	if (f != 2)
		ft_exit(-1);
}
