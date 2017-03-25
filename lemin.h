/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:24:36 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/25 15:27:00 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
//# include "alala/ft_printf.h"
//# include "priii/printf.h"
//# include "libft/ft_printf/printf.h"

typedef struct		s_lst
{
	char			*name;
	int				vert;
	int				pos;
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
	int				ant;
	int				dest;
	int				*path;
	int				**all_paths;
	int				**best_paths;
	int				amount;
	int				*visited;
	int				i;
	int				l;
	int				vert;
	int				all_len;
}					t_dfs;

//main_read.c
void				need_next_line(char **line);
int					start_end_read(char **line);
void				validation(char *line);
void				solve(t_lst *start, int ants);
int					main(void);
//organize_info1.c
void				put_move(int ant, char *name, int i);
t_lst				*new_lst(char *name, int flag);
void				create_list(t_lst **start, char *line, int flag);
void				set_links(t_lst **start, char *name, char *s_name);
void				get_links(t_lst **start, char *line);
//organize_info2.c
char				*get_name(char *line, char f);
void				org_links(t_lst **start);
void				org_pos(t_lst **start);
t_lst				*org_path(t_lst **start);
void				set_ants(t_lst **start, int ants);
//support_functions.c
void				ft_exit(int f);
int					lst_len(t_lst *start);
int					loc_dest(t_lst *start);
int					path_len(int *path, int dest);
char				*restore_name(t_lst *start, int place);
//build_matrix.c
int					row_char(int i, t_lst *p, t_lst *start);
int					*get_row(t_lst *start, int pos, int len);
void				matrix(t_lst **start);
//dfs_algo.c
void				get_stack_elements(int indx, int *way, t_dfs *path);
void				remember_path(int start, int dest, t_dfs *path,
	int **matrix);
void				all_paths_search(int **matrix, t_lst *start);
//choose_paths.c
int					*all_len(int **p, t_dfs *path);
int					if_repeat(int *a, int **b, int p, int dest);
void				choose_more_paths(t_lst *start, t_dfs *p, int j, int i);
void				choose_path(t_dfs *p, t_lst *start);
//print_path.c
int					**dup_zero(int **p, t_dfs *path);
void				free_dfs(t_dfs *path);
int					print_move(int len, int **ants, t_dfs *path, t_lst *start);
int					actually_print_path(t_lst *start, t_dfs *path, int **ants,
	int *len);
void				print_path(t_lst *start, t_dfs *path);

void				show_best_paths(t_dfs *p, t_lst *start);

#endif
