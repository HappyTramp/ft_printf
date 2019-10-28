#include <stdlib.h>
#include "header.h"

t_flist	*list_new(t_pformat *content)
{
	t_flist	*lst;

	if ((lst = (t_flist*)malloc(sizeof(t_flist))) == NULL)
		return NULL;
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	*list_destroy(t_flist **lst)
{
	if (lst == NULL)
		return (NULL);
	while (*lst != NULL)
		list_pop_front(lst);
	return (NULL);
}


void	list_push_front(t_flist **lst, t_flist *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	list_pop_front(t_flist **lst)
{
	t_flist	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = (*lst)->next;
	free((*lst)->content);
	free(*lst);
	*lst = tmp;
}

void	list_reverse(t_flist **lst)
{
	t_flist	*cursor;
	t_flist	*prev;
	t_flist	*tmp;

	prev = NULL;
	cursor = *lst;
	while (cursor != NULL)
	{
		tmp = cursor;
		cursor->next = prev;
		prev = cursor;
		cursor = tmp->next;
	}
	*lst = prev;
}
