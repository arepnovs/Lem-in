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
	free(*line);
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

void		solve(t_lst *start, int ants)
{
	if (ants <= 0)
		ft_exit(ants);
	org_links(&start);
	set_ants(&start, ants);
	start = org_path(&start);
	matrix(&start);
}

int			main(void)
{
	char	*line;
	t_lst	*start;
	int		ants;
	int		f;

	while ((get_next_line(0, &line)) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		//validation(line);
		if (line[1] == '#' && (line[2] == 's' || line[2] == 'e'))
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
		else if (line[0] >= 'b')
			break ;
		ft_strdel(&line);
	}
	solve(start, ants);
	//sleep(20);
	return (0);
}
