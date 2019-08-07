
#include "../includes/lem_in.h"

void				out_ways(t_room **graph, t_way *meta)
{
	t_way	*path;
	t_way	*dupl;

	path = meta;
	while ((path = path->next))
	{
		dupl = path;
		printf("PATH_LEN:	%d\n", path->len);
		while ((dupl = dupl->parent))
			printf("[%s] ", graph[dupl->id]->name);
		printf("\n\n");
	}
	printf("\nLOOP!\n\n\n");
}

void		print_graph(t_room **graph)
{
	int j = -1;
	int i = -1;
	while (++i < g_count_room)
	{
		printf("'%s' index: %d\n", graph[i]->name, graph[i]->index);
		while (++j < graph[i]->count_links)
			printf("(%s)", graph[graph[i]->links[j]]->name);
		j = -1;
		printf("\n");
	}
}

//printf("FROM1->TO1: %d->%d\nFROM2->TO2: %d->%d\n\n\n", from[0]->id, to[0]->id, from[1]->id, to[1]->id);