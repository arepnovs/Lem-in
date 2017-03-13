
#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define RED 	"\x1B[31m"
# define BLUE   "\x1B[34m"
# define GREEN  "\x1B[32m"
# define RESET  "\x1B[0m"

typedef struct		s_lst
{
	char			*name;
	int				y;
	int				x;
	char			*links;
	char			**llinks;
	int				*cost;
	int				value;
	//int				new_val;
	int				amount;
	int				place;
	int				ants;
	struct s_lst	*all;
	struct s_lst	*next;
	struct s_lst	**gr;
}					t_lst;


void	org_links(t_lst **start);
int		ft_abs(int x);
void	set_costs(t_lst **start);
void	graph_links(t_lst **start);
void	algo(t_lst **start);
void	recu_alg(t_lst **p, char **path, int *i);

#endif