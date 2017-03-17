#include "lemin.h" 

int 	path_len(int *path, int dest)
{
	int i;

	i = 0;
	while (path[i] != dest)
		i++;
	return(i);
}

int		check_rep(int *a, int **b, int p, int dest)
{
	int i;
	int j;
	int k;

	k = 0;
	while (k < p)
	{
		i = 1;
		while (a[i] != dest)
		{
			j = 1;
			while (b[k][j] != dest)
			{
				if (a[i] == b[k][j])
					return(0);
				j++;
			}
			i++;
		}
		k++;
	}
	return(1);
}

void choose_path(t_dfs *path, t_lst *start)
{
	int i;
	int j;
	int len;
	int new_len;

	i = 0;
	j = 0;
	new_len = 100000;
	path->best_paths = (int**)malloc(sizeof(int*) * path->i);
	while (i < path->i)
	{
		if ((len = path_len(path->all_paths[i], path->dest)) < new_len)
		{
			new_len = len;
			path->best_paths[j] = (int*)malloc(sizeof(int) * new_len);
			path->best_paths[j] = path->all_paths[i];
		}
		i++;
	}
	j++;
	while (j < start->amount)
	{
		i = 0;
		new_len = 100000;
		while (i < path->i)
		{
			if (path->all_paths[i][1] != path->best_paths[j - 1][1]
				&& check_rep(path->all_paths[i], path->best_paths, j, path->dest) != 0
				&& (len = path_len(path->all_paths[i], path->dest)) < new_len)
			{
				if (j)
				new_len = len;
				path->best_paths[j] = (int*)malloc(sizeof(int) * new_len);
				path->best_paths[j] = path->all_paths[i];
			}
			i++;
		}
		if (!path->best_paths[j])
			break;
		j++;
	}
	path->amount = j;
	print_path(start, path);
  int f = 0;
  int g;
  /*printf("------------------------------------\n");
  while (f < j)
  {
    g = 0;
    while (path->best_paths[f][g - 1] != path->dest)
    {
      printf("%d ", path->best_paths[f][g]);
      g++;
    }
    f++;
    printf("\n");
  }
  printf("------------------------------------\n");*/
}