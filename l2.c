#include "lemin.h"

void	org_links(t_lst **start)
{
	t_lst *p;

	p = *start;
	while(p)
	{
		p->llinks = ft_strsplit(p->links, '|');
		//ft_strdel(&(p->links));
		p = p->next;
	}
}

void	org_pos(t_lst **start)
{
	t_lst *p;
	int i;

	i = 0;
	p = *start;
	while (p)
	{
		p->pos = i;
		i++;
		p = p->next;
	}
}

t_lst	*org_path(t_lst **start)
{
	t_lst *p1;
	t_lst *p2;
	t_lst *p3;

	p1 = *start;
	p2 = *start;
	if (p1->place != 1)
	{
		while (p1->place != 1)
		{
			p3 = p1;
			p1 = p1->next;
			p2 = p1->next;
		}
		p1->next = *start;
		start = &p1;
		p3->next = p2;
	}
	org_pos(start);
	return(*start);
}

int		ft_abs(int x)
{
	if (x < 0)
		return(-x);
	else
		return(x);
}

int		list_len(t_lst *start)
{
	int i;

	i = 0;
	while(start)
	{
		i++;
		start = start->next;
	}
	return(i);
}

void	set_costs(t_lst **start)
{
	t_lst *p1;
	t_lst *p2;
	int i;

	p1 = *start;
	p2 = p1->all;
	while(p1)
	{
		p1->cost = (int*)malloc(sizeof(int) * p1->amount + 1);
		i = 0;
		while(p2 && i < p1->amount)
		{
			if (strcmp(p1->llinks[i], p2->name) == 0)
			{
				p1->cost[i] = (ft_abs(p1->x - p2->x) + ft_abs(p1->y - p2->y));
				i++;
				p2 = p1->all;
			}
			else
				p2 = p2->next;
		}
		p2 = p1->all;
		p1 = p1->next;
	}
}