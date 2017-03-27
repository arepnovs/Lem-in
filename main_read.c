/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:57:12 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/24 15:59:10 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		need_next_line(char **line)
{
	ft_putstr(*line);
	ft_putstr("\n");
	validation(*line);
}

int			start_end_read(char **line)
{
	int f;

	f = (line[0][2] == 's') ? 1 : 9;
	while (line[0][0] == '#')
	{
		free(*line);
		get_next_line(0, line);
		if (line[0][0] == '#')
			need_next_line(line);
	}
	validation(*line);
	ft_putstr(*line);
	ft_putstr("\n");
	return ((f == 1) ? 1 : 9);
}

void		solve(t_lst *start, int ants)
{
	if (ants <= 0)
		ft_exit(ants);
	start_end_check(start);
	org_links(&start);
	set_ants(&start, ants);
	start = org_path(&start);
	matrix(&start);
}

void		print_line(char *line)
{
	ft_putstr(line);
	ft_putstr("\n");
	validation(line);
}

int			main(void)
{
	char	*line;
	t_lst	*start;
	int		ants;
	int		f;

	f = 0;
	while ((get_next_line(0, &line)) > 0)
	{
		print_line(line);
		if (line[1] == '#' && (ft_strstr(line, "start")
			|| ft_strstr(line, "end")))
		{
			f = start_end_read(&line);
			create_list(&start, line, f);
		}
		else if (ft_strchr(line, '-') && line[0] != '#')
			get_links(&start, line);
		else if (ft_strchr(line, ' ') && line[0] != '#' && line[0] != 'L')
			create_list(&start, line, 0);
		else if (!ft_strchr(line, ' ') && line[0] >= '0' && line[0] <= '9')
			ants = ft_atoi(line);
		ft_strdel(&line);
	}
	solve(start, ants);
	//sleep(20);
	return (0);
}
