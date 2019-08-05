typedef struct	s_list
{
	int				id;
	struct s_list	*parent;
	struct s_list	*next;
}				t_list;

t_list		*new_list(int id, t_list *parent)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->id = id;
	new->parent = parent;
	new->next = NULL;
	return (new);
}


int			check_presence(t_list *list, int id)
{
	while (list)
	{
		if (id == list->id)
			return (0);
		list = list->next;
	}
	return (1);
}

t_list		*new_path(t_room ***graph)
{
	t_list	*list;
	t_list	*step;
	t_list	*front;
	t_list	*path;
	int		*link;
	int		i;

	list = new_list(g_count_room - 1, NULL);
	step = list;
	front = list;
	while (step)
	{
		link = (*graph)[step->id]->links;
		i = 0;
		while (i < (*graph)[step->id]->count_links)
		{
			if (link[i] != -1 && check_presence(list, link[i]))
			{
				front->next = new_list(link[i], step);
				front = front->next;
			}
			i++;
		}
		step = step->next;
	}
	step = list;
	while (step && step->id)
		step = step->next;
	path = new_list(step->id, NULL);
	while (step->parent)
	{
		path->next = new_list(step->parent->id, step);
		i = 0;
		link = (*graph)[step->parent->id]->links;
		while (i < (*graph)[step->parent->id]->count_links)
		{
			if (link[i] == step->id)
				link[i] = -1;
			i++;
		}
		path = path->next;
		step = step->parent;
	}
	return (step);
}

int					AlexD(t_room ***graph)
{
	t_list	*meta;
	t_list	*path;

	meta = new_list(-1 , NULL);
	path = meta;
	while (path)
	{
		path->parent = new_path(-1, NULL);
		path = path->parent;
		path->next = new_path(graph);
	}
}
