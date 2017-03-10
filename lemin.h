
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
	int				place;
	int				ants;
	struct s_lst	*all;
	struct s_lst	*next;
}					t_lst;

#endif