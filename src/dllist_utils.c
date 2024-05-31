/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:56 by mprunty           #+#    #+#             */
/*   Updated: 2024/04/26 20:48:05 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

dl_list *ft_dllstnew(int i)
{
	dl_list *elt;

	if (!(elt = (dl_list*)malloc(sizeof(*elt))))
		return (NULL);
	elt->i = i;
	elt->next = NULL;
	elt->prev = NULL;
	elt->idx = 0;
	return (elt);
}

void	ft_dllstupdate(dl_list **lst)
{
	(lst[1]->prev)->next = lst[1]->next;
	(lst[1]->next)->prev = lst[1]->prev;
	//(lst[1]->next)->idx = 1;
	//(lst[1]->prev)->idx = -1;
}

dl_list **get_tail(dl_list **lst)
{
	return (&lst[1]->prev);
}

dl_list **get_head(dl_list **lst)
{
	return (&lst[1]->next);
}

dl_list **get_storage(dl_list **lst)
{
	return (&lst[2]);
}

int *get_size(dl_list **lst)
{
	return (&lst[1]->idx);
}
void 	reset_head(dl_list **lst, dl_list *head)
{
	*(get_head(lst)) = head; 
	*(get_tail(lst)) = head->prev; 
	ft_dllstupdate(lst);
	return ;
}
void	rm_dllst(dl_list **lst)
{
	//dl_list **tmp;
	
	//tmp = lst;
	((*lst)->next)->prev = (*lst)->prev;
	((*lst)->prev)->next = (*lst)->next;
//	if (lst[0]->idx < 0)
	*(get_tail(lst)) = (lst[0]->prev);
//	else if (lst[0]->idx > 0)
	*(get_head(lst)) = (lst[0]->next);
	if ((*lst)->idx != 0)
	{
		(*get_head(lst))->idx = (*lst)->idx;
		(*lst)->idx = 0;
	}
	//	ft_dllstupdate(lst);

	*lst = *(get_head(lst));// lst[1]->next;
	return;
}
void	ft_dealloc(dl_list **lst)
{
	dl_list  *tmp;
	int i;
	i = ((lst[1]->idx) );
	if (!i)
		free(*lst);
	while(i--)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(lst[1]);
	free(lst[2]);
	return ;

}

void	ft_dllstadd_back(dl_list **lst, dl_list *new)
{
	dl_list  *last;

	if (lst)
	{
		new->idx = -1;
		if (lst[1]->prev)
		{
			new->next = lst[1]->next;
			last = lst[1]->prev;//ft_dllstlast(*lst);
			new->prev = last;
			last->next = new;
			last->idx = 0;

		}
		else
		{
			new->prev = new;
			new->next = new;
			free(*lst);
			*lst = new;
			lst[1]->next = new;
		}
		lst[1]->prev = new;
		lst[1]->idx += 1;
		if (*get_size(lst) > 1)
			lst[0]->idx = 1;
		//(*get_head(lst))->idx = 1;
		ft_dllstupdate(lst);
	}
}


void	ft_dllstadd_front(dl_list **lst, dl_list *new)
{
	if (lst)
	{
		//new->idx = 1;
		if (lst[1]->next)
		{
			new->next = *lst;
			new->prev = (lst[1])->prev;
			(*lst)->prev = new;
			(*lst)->idx = 0;
		}
		else
			free(*lst);
		*lst = new;
		(*lst)->idx = 1;
		if (*get_size(lst) < 2)
			(*lst)->idx = -1;
		//add head
		if(!lst[1]->prev)
			lst[1]->prev = new;
		lst[1]->next = new;
		lst[1]->idx += 1;
		ft_dllstupdate(lst);
		}
}

void	print_list(dl_list **lst, int dir)
{
	size_t i;

	i = *get_size(lst);
	if (i)
	{
		ft_printf("#########################");
		ft_printf("\nhead:%i ", ((lst[1])->next)->i);
		ft_printf("tail:%i ", ((lst[1])->prev)->i);
		ft_printf("size:%i ", (lst[1])->idx);
		ft_printf("\n________________________");
		if (dir < 0)
			*lst = (*lst)->prev;
		while(i--)// <  (size_t)(lst[1]->idx))
		{
			ft_printf("\n");
			ft_printf("i:%i ",  (*lst)->i);
			ft_printf("idx:%i ", (*lst)->idx);
			ft_printf("prev:%i ", ((*lst)->prev)->i);
			ft_printf("next:%i ", ((*lst)->next)->i);
			if (dir>0)
				*lst = (*lst)->next;
			else if (dir < 0)
				*lst = (*lst)->prev;
		}
		ft_printf("\n________________________\n");
	}
	return;
}

void	init_lst(dl_list **lst)
{

	lst[0] = ft_dllstnew(0);
	lst[1] = ft_dllstnew(0);
	lst[2] = ft_dllstnew(0);
	lst[1]->idx = 0;
	//lst[1]->idx = 0;
	return ;
}
/*/
int main()
{
	
	dl_list *lst[2];
	init_lst(lst);
	//ft_dllstadd_back(lst,  ft_dllstnew("1"));
	//ft_dllstadd_back(lst,  ft_dllstnew("2"));
	ft_dllstadd_front(lst,  ft_dllstnew("3"));
	//ft_dllstadd_back(lst,  ft_dllstnew("4"));
	//ft_dllstadd_back(lst,  ft_dllstnew("5"));
	ft_dllstadd_front(lst,  ft_dllstnew("6"));
	ft_dllstadd_front(lst,  ft_dllstnew("7"));
	ft_dllstadd_front(lst,  ft_dllstnew("8"));
	print_list(lst, 1);	
	print_list(lst, -1);	
	//ft_printf("%i", ft_isascii('a'));
	//ft_printf("%s", lst->i);
	return 0;
}

/*/
