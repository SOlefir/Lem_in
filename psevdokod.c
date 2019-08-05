/*
лемин. создание массива с линками (направленный граф)

main
1. валидация входящих параметров. 
2. сохранить параметры в структуру data;
3. создание листов с комнатами;
4. создание массива с линками и направлением;
5. 
*/


typedef struct s_data
{
	int		lemins_coun;
	int		rooms_count;
	char*	room_name;
	char*	links;
}				t_data;

typedef struct	s_room
{
	char*	name;
	int		index;
	int		steps; //кол-во шагов к финишу из этой к. но это нужно будет вынести в структуру с линками наверн. 
	t_room	**next; //массив поинтеров на комнаты с которыми связана данная комната
}				t_room;


typedef	struct s_way
{
	int		count_step;
	t_room	*room;
	t_way	*next;
}				t_way;

typedef struct s_all_ways
{
	int			index;
	t_way		*way;
	t_all_ways	*next
}				t_all_ways;

/*
создаю 2д массив  интов размера count_room. 
каждому индексу и по y и по x соответствует какая-то комната.
y - комната
х - линк с комнатой

я нахожу нужную мне комнату в листе, и использцю ее индекс как номер массива массивов. 
Дальше я ищу линк с данной комнатой, если он есть, то я ставлю 1 по индексу комнаты с которой линкую. 
Если там уже стоит 1, значит эту комнату я уже посещала, тогда это выход из нее, значит надо поставить -1, 
что означает, что обратного пути нет. (нельзя двигаться к старту, только к финишу). потому очень важно начинать со стартовой комнаты
*/

//дописать проверки для случая, когда у комнаты 2 линка, как идти дальше//

t_room *find_room(char *name, t_room *room) // возвращает ссылку на нужную нам комнату (как в гнл был поиск фдшника по листам)
int	find_link(char *name, t_struct *links) // возвращает номер индекса комнаты с которой линк комнаты, которую получила фнкц

t_struct *links;
t_room *room;

int **ar;

arr = make_2d_arr;
room = find_room(t_data->room_name);
while (y < data->rooms_count)
	{

		while (x < data->rooms_count)
			if (x = find_link(room->room_name, t_data->links))
				arr[room->index][x] == arr[room->index][x] == 0 ? 1 : -1;  
		
	}



int		main(void)
{
	if (errors_n = validations_and_read)
		return(error);
	if (errors_n = get_data)
		return (error);
	if (start->next >= 1 && end->next >= 1)
		ways = start->next < end->next ? start->next : end->next;
	while (ways)
	{
		dejkstra;
		edit_graph;
		bhandari;
		ways--;
	}
	go_to_finish;
	return (1);



	int 	j;
	int 	step;
	t_room	*room;
	t_room	*link;

	step = 0;
	room = graph[0];
	room->count_steps = step;
	while (room != NULL && step <= room->count_steps)
	{
		j = -1;
		++step;
		while (++j < room->count_links)
		{
			while (room->links[j] < 0 && j < room->count_links)
				j++;
			if (j >= room->count_links)
				break;
			link = graph[room->links[j]];
			link->count_steps = link->count_steps > step ? step : link->count_steps;
		}
		j = 0;
		while (j < room->count_links && room->links[j] > 0 &&
				graph[room->links[j]]->count_steps <= step)
			j++;
		if (j < room->count_links)
			room = graph[room->links[j]];
	}
}