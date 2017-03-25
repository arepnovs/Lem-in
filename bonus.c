#include "lemin.h"

void	show_best_paths(t_dfs *p, t_lst *start)
{
	int i;
	int j;
	char *name;

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
			ft_putstr(name);
			if (p->best_paths[i][j] != p->dest)
				ft_putstr("->");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	ft_putstr("----------------------------------\n");
}