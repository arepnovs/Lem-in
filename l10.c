#include "lemin.h" 
 
int   loc_dest(t_lst *start)
{
  while (start)
  {
    if (start->place == 9)
      return(start->pos);
    start = start->next;
  }
  return(0);
} 

void print_stack_elements(int indx, int *way, t_dfs *path)
{
  int i;

  i = 0;
  path->all_paths[path->i] = (int*)malloc(sizeof(int) * path->vert);
  while (i < indx)
  {
    path->all_paths[path->i][i] = way[i];
    //printf ("%d ", way[i]);
    i++;
  }
  path->i++;
  //printf ("\n");
}
 
void printPath(int start, int dest, t_dfs *path, int **matrix)
{
  int i;
  path->visited[start] = 1;
  path->path[path->indx] = start;
  path->indx++;
 
  if (start == dest)
      print_stack_elements (path->indx, path->path, path);
  else
    {
      i = 0;
      while (i < path->vert)
      {
        if (path->visited[i] == 0 && matrix[start][i])
          printPath (i, dest, path, matrix);
        i++;
      }
    }
  path->visited[start] = 0;
  path->indx--;
}

void dfs_rec(int **matrix, t_lst *start, t_dfs *path)
{
  ft_memset (path->visited, 0, sizeof (path->visited));
  printPath (0, path->dest, path, matrix);
}

void  recucu(int **matrix, t_lst *start)
{
  t_dfs path;
 
  path.dest = loc_dest(start);
  path.vert = start->vert;
  path.path = (int*)malloc(sizeof(int) * start->vert);
  path.visited = (int*)malloc(sizeof(int) * start->vert);
  path.all_paths = (int**)malloc(sizeof(int*) * 10000);
  path.indx = 0;
  path.i = 0;
  dfs_rec(matrix, start, &path);
  choose_path(&path, start);
  /*int j = 0;
  int g;
  while (j < path.i)
  {
    g = 0;
    while (g < path.vert)
    {
      printf("%d ", path.all_paths[j][g]);
      g++;
    }
    j++;
    printf("\n");
  }*/
}






















