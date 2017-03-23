
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
#define N 8

typedef struct		s_lst
{
	char			*name;
	int				vert;
	int 			pos;
	char			*links;
	char			**llinks;
	int				amount;
	int				place;
	int				ants;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_dfs
{
	int				indx;
	int 			dest;
	int				*path;
	int				**all_paths;
	int				**best_paths;
	int				amount;
	int				*visited;
	int				i;
	int 			vert;
	int 			all_len;
}					t_dfs;


//l1.c
//char	*get_name(char *line, char f);
t_lst	*new_lst(t_lst *start, char *name, int flag);
void	create_list(t_lst **start, char *line, int flag);
void	set_links(t_lst **start, char *name, char *s_name);
void	get_links(t_lst **start, char *line);
int		main(void);
//l2.c
void	org_links(t_lst **start);
void	org_pos(t_lst **start);
t_lst	*org_path(t_lst **start);
int		lst_len(t_lst *start);
void	set_ants(t_lst **start, int ants);
//l4.c
int 	row_char(int i, t_lst *p, t_lst *start);
int		*get_row(t_lst *start, int pos, int len);
void	matrix(t_lst **start);
//l10.c
int   loc_dest(t_lst *start);
void  get_stack_elements(int indx, int *way, t_dfs *path);
void remember_path(int start, int dest, t_dfs *path, int **matrix);
void  all_paths_search(int **matrix, t_lst *start);
//l11.c
void choose_path(t_dfs *path, t_lst *start);
int		check_rep(int *a, int **b, int p, int dest);
int 	path_len(int *path, int dest);
//l13.c
int		*all_len(int **p, t_dfs *path);
int 	**dup_zero(int **p, t_dfs *path);
char 	*gets_name(t_lst *start, int place);
void	print_path(t_lst *start, t_dfs *path);

#endif