
#include "../includes/lem_in.h"

void		print_graph(t_room **graph)
{
	int j = -1;
	int i = -1;
	while (++i < g_count_room)
	{
		printf("[%d]'%s' steps: %d\n", i, graph[i]->name, graph[i]->count_steps);
		while (++j < graph[i]->count_links)
			printf("(%d)", graph[i]->links[j]);
		j = -1;
		printf("\n");
	}
}

void	print_way(int *way, int size_way)
{
	int i;

	i = -1;
	while (++i < size_way)
		printf("%d ", way[i]);
	printf("\n");
}

void	print_ways(t_ways *ways)
{
	int	i;

	i = -1;
	if (ways == NULL)
		printf("NULL");
	while (ways != NULL)
	{
		printf("\n");
		printf(" [%d] ", ways->len_way);
		print_way(ways->way, ways->len_way);
		printf("\n");
		ways = ways->next;
	}
}
