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
	int				f;
	int				temp;
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
	int				*stop;
	int				f;
	int				i;
	int				l;
	int				vert;
	int				all_len;
}					t_dfs;

//main_read.c
void				need_next_line(char **line);
int					start_end_read(char **line);
void				solve(t_lst *start, int ants);
void				print_line(char *line, int f);
int					main(void);
//validation.c
void				ft_exit(int f);
void				validation(char *line);
void				start_end_check(t_lst *start);
void				one_more_validation(char *line);
//organize_info1.c
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
//dash_names_check
int					check_name_with_dash(char *line);
int					is_ok_name(t_lst *start, char *line);
char				*id_first_dash_name_in_link(t_lst *start, char *line);
char				*id_second_dash_name_in_link(char *line, char *f_name);
//support_functions.c
void				free_dfs(t_dfs *path);
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
int					**dup_zero(int **p, t_dfs *path);
int					*all_len(int **p, t_dfs *path);
int					if_repeat(int *a, int **b, int p, int dest);
void				choose_more_paths(t_lst *start, t_dfs *p, int j, int i);
void				choose_path(t_dfs *p, t_lst *start);
//print_path.c
void				print_move(int len, int **ants, t_dfs *path, t_lst *start);
int					actually_print_path(t_lst *start, t_dfs *path, int **ants,
	int *len);
void				print_path(t_lst *start, t_dfs *path);
//bonus
void				show_best_paths(t_dfs *p, t_lst *start);
void				put_move(int ant, char *name, int i);

#endif
