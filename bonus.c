/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:07:36 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/27 20:08:20 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	put_move(int ant, char *name, int i)
{
	if (i == 0)
		ft_putstr("\x1B[39m");
	else if (i == 1)
		ft_putstr("\x1B[32m");
	else if (i == 2)
		ft_putstr("\x1B[33m");
	else if (i == 3)
		ft_putstr("\x1B[31m");
	else if (i == 4)
		ft_putstr("\x1B[34m");
	else if (i == 5)
		ft_putstr("\x1B[35m");
	else if (i == 6)
		ft_putstr("\x1B[36m");
	else if (i == 7)
		ft_putstr("\x1B[37m");
	else if (i == 8)
		ft_putstr("\x1B[38m");
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("->");
	ft_putstr(name);
	ft_putstr(" ");
	ft_putstr("\x1B[0m");
}

void	color_paths(char *name, int i, t_dfs *p, int best)
{
	if (i == 0)
		ft_putstr("\x1B[39m");
	else if (i == 1)
		ft_putstr("\x1B[32m");
	else if (i == 2)
		ft_putstr("\x1B[33m");
	else if (i == 3)
		ft_putstr("\x1B[31m");
	else if (i == 4)
		ft_putstr("\x1B[34m");
	else if (i == 5)
		ft_putstr("\x1B[35m");
	else if (i == 6)
		ft_putstr("\x1B[36m");
	else if (i == 7)
		ft_putstr("\x1B[37m");
	else if (i == 8)
		ft_putstr("\x1B[38m");
	ft_putstr(name);
	if (best != p->dest)
		ft_putstr("->");
	ft_putstr("\x1B[0m");
}

void	show_best_paths(t_dfs *p, t_lst *start)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	ft_putstr("\n");
	ft_putstr("Best paths\n");
	while (i < p->amount)
	{
		j = 0;
		ft_putstr("----------------------------------\n");
		while (p->best_paths[i][j - 1] != p->dest)
		{
			name = restore_name(start, p->best_paths[i][j]);
			color_paths(name, i, p, p->best_paths[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	ft_putstr("----------------------------------\n");
}
