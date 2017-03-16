#include "lemin.h"
#define N 8
 
/*int graph[N][N] = {
  {0, 1, 1, 0, 0, 0, 0 ,0},
  {1, 0, 0, 1, 1, 0, 1, 0},
  {1, 0, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 0, 0, 1, 1},
  {0, 1, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 1, 1},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 1, 0, 1, 0, 0},
};*/
 
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

void print_stack_elements(int indx, int path[N])
{
  int i;

  i = 0;
  while (i < indx)
  {
    printf ("%d ", path[i]);
    i++;
  }
  printf ("\n");
}
 
void printPath(int start, int dest, t_dfs *path, int **matrix)
{
  int i;
  path->visited[start] = 1;
  path->path[path->indx] = start;
  path->indx++;
 
  if (start == dest)
    {
      print_stack_elements (path->indx, path->path);
    }
  else
    {
      i = 0;
      while (i < N)
      {
        if (path->visited[i] == 0 && matrix[start][i])
          printPath (i, dest, path, matrix);
        i++;
      }
    }
  path->visited[start] = 0;
  path->indx--;
}

void dfs_rec(int **matrix, t_lst *start)
{
  t_dfs path;
  //int start;
  int dest;

  dest = loc_dest(start);
  path.path = (int*)malloc(sizeof(int) * start->vert);
  path.visited = (int*)malloc(sizeof(int) * start->vert);
  path.indx = 0;
// set all nodes unvisited
  ft_memset (path.visited, 0, sizeof (path.visited));
  printPath (0, dest, &path, matrix);
}