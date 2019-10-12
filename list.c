#include <stdlib.h>
#include "header.h"

t_list	*list_new(t_pformat *data)
{
	t_list	*list;

	if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return NULL;
	list->data = data;
	list->next = NULL;
	return (list);
}

t_list	*list_destroy(t_list *list)
{
	while (list != NULL)
		list_pop_front(&list);
	return (NULL);
}


void	list_push_front(t_list **list, t_list *new_front)
{
	new_front->next = *list;
	*list = new_front;
}

void	list_push_back(t_list **list, t_list *new_back)
{
	t_list	*cursor;

	if (*list == NULL)
	{
		*list = new_back;
		return ;
	}
	cursor = *list;
	while (cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = new_back;
}

void	list_pop_front(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	tmp = (*list)->next;
	free((*list)->data);
	free(*list);
	*list = tmp;
}
