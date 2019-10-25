#include <stdlib.h>
#include "header.h"

t_pformat_list				*list_new(t_pformat *content)
{
	t_pformat_list	*lst;

	if ((lst = (t_pformat_list*)malloc(sizeof(t_pformat_list))) == NULL)
		return NULL;
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void						*list_destroy(t_pformat_list **lst)
{
	if (lst == NULL)
		return (NULL);
	while (*lst != NULL)
		list_pop_front(lst);
	return (NULL);
}


void						list_push_front(t_pformat_list **lst, t_pformat_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void						list_push_back(t_pformat_list **lst, t_pformat_list *new)
{
	t_pformat_list	*cursor;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	cursor = *lst;
	while (cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = new;
}

void						list_pop_front(t_pformat_list **lst)
{
	t_pformat_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = (*lst)->next;
	free((*lst)->content);
	free(*lst);
	*lst = tmp;
}
