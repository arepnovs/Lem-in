
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
	int				y;
	int				x;
	char			*links;
	char			**llinks;
	int				*cost;
	int				value;
	//int			new_val;
	int				amount;
	int				place;
	int				ants;
	int				was_here;
	int 			finish;
	struct s_lst	*all;
	struct s_lst	*next;
	//struct s_lst	**gr;
}					t_lst;

typedef struct		s_dfs
{
	int				indx;
	int 			dest;
	int				*path;
	int				**all_paths;
	int				**best_paths;
	//int 			**ant_paths;
	int				amount;
	int				*visited;
	int				i;
	int 			vert;
	int 			all_len;
}					t_dfs;

typedef struct		s_pt
{
	char			*name;
	int 			len;
	int				ant_num;
	int				if_ant;
	int 			full;
	struct s_pt		*prev;
	struct s_pt		*next;
}					t_pt;


void	org_links(t_lst **start);
int		ft_abs(int x);
void	set_costs(t_lst **start);
void	graph_links(t_lst **start);
void	algo(t_lst **start);
void	recu_alg(t_lst *p, char **path, int *i);
t_lst 	*org_path(t_lst **start);
void	recu(t_lst *p1, t_lst *p2, char **path, int *j);
int		check_end(t_lst *start);
int		check_finish(t_lst *start, char *links);
void	pathfind(t_lst **start);
int		lst_len(t_lst *start);
void	matrix(t_lst **start);
void 	dfs_rec (int **matrix, t_lst *start, t_dfs *path);
void 	printPath(int src, int dest, t_dfs *path, int **matrix);
void 	print_stack_elements (int indx, int *way, t_dfs *path);
void  	recucu(int **matrix, t_lst *start);
int 	path_len(int *path, int dest);
void 	choose_path(t_dfs *path, t_lst *start);
void	print_path(t_lst *start, t_dfs *path);
void	print_path(t_lst *start, t_dfs *path);
int		pt_len(t_pt *start);
void	ppath_path(t_lst *start, t_dfs *path);
int 	ppath_len(int *path, int dest);


#endif