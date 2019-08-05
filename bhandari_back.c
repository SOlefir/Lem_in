#include <stdlib.h>
#include <stdio.h>
typedef struct	s_ways		t_ways;

struct			s_ways
{
	int		*way;
	int		len_way;
	t_ways	*next;
};

void show_way(t_ways *a)
{
	int i;

	i = 0;
	while (i < a->len_way)
		printf("%d ", a->way[i++]);
	printf("\n");
}

int				find_int(int *array, int len, int to_find)
{
	int i;

	i = 1;
	while (i < len && array[i] != to_find)
		i++;
	if (i == len)
		return 0;
	return i;
}

void			copy_way(t_ways *a, t_ways *b, t_ways *new_a, int a_place)
{
	int 	i;
	int		j;

	i = -1;
	while (++i < a_place)
		new_a->way[i] = a->way[i];
	j = a_place + b->len_way - new_a->len_way - 1;
	while (++j < b->len_way)
		new_a->way[i++] = b->way[j];
}

t_ways			do_the_way(t_ways *a, t_ways *b)
{
	int			a_place;
	int			b_place;
	t_ways		new_a;

	a_place = 0;
	while (++a_place < a->len_way - 1)
		if ((b_place = find_int(b->way, b->len_way - 1, a->way[a_place])) > 0)
			break;
	new_a.len_way = a_place + (b->len_way - b_place);
	new_a.way = (int *)malloc(sizeof(int) * new_a.len_way);
	copy_way(a, b, &new_a, a_place);
	return (new_a);
}

static void		bhandari_disijoint(t_ways *a, t_ways *b)
{
	t_ways		new_a;
	t_ways		new_b;

	new_a = do_the_way(a, b);
	new_b = do_the_way(b, a);
	free(a->way);
	a->way = new_a.way;
	a->len_way = new_a.len_way;
	free(b->way);
	b->way = new_b.way;
	b->len_way = new_b.len_way;
}

int main()
{
	t_ways	*a;
	t_ways	*b;

	a = (t_ways *)malloc(sizeof(t_ways));
	b = (t_ways *)malloc(sizeof(t_ways));
	a->way = (int *)malloc(sizeof(int) * 4);
	a->len_way = 4;
	a->way[0] = 0;
	a->way[1] = 3;
	a->way[2] = 4;
	a->way[3] = 7;
	b->way = (int *)malloc(sizeof(int) * 8);
	b->len_way = 8;
	b->way[0] = 0;
	b->way[1] = 1;
	b->way[2] = 2;
	b->way[3] = 4;
	b->way[4] = 3;
	b->way[5] = 5;
	b->way[6] = 6;
	b->way[7] = 7;
	show_way(a);
	show_way(b);
	printf("\n");
	bhandari_disijoint(a, b);
	show_way(a);
	show_way(b);
	while (1)
		a->len_way++;
}