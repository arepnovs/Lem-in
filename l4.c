#include "lemin.h"

int 	row_char(int i, t_lst *p)
{
	t_lst *p2;

	p2 = p->all;
	while (p2)
	{
		if (ft_strstr(p->links, p2->name))
		{
			if (i == p2->pos)
				return(1);
		}
		p2 = p2->next;
	}
	return(0);
}

int		*get_row(t_lst *start, int pos, int len)
{
	int i;
	t_lst *p;
	int	*row;

	p = start;
	i = 0;
	row = (int*)malloc(sizeof(int) * len + 1);
	while (i < pos)
	{
		p = p->next;
		i++;
	}
	i = 0;
	while (i < len)
	{
		row[i] = row_char(i, p);
		i++;
	}
	return(row);
}

void	matrix(t_lst **start)
{
	t_lst *p1;
	t_lst *p2;
	int	len;
	int **matrix;
	int i;
	int j;

	p1 = *start;
	p2 = p1->all;
	len = lst_len(*start);
	p1->vert = len;
	matrix = (int**)malloc(sizeof(int*) * len);
	i = 0;
	while (i < len)
	{
		//matrix[i] = (char*)malloc(sizeof(char) * len + 1);
		//j = 0;
		matrix[i] = get_row(*start, i, len);
		i++;
	}
	recucu(matrix, p1);
	/*i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}*/
}