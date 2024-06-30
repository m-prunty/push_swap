/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_crud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:26:01 by mprunty           #+#    #+#             */
/*   Updated: 2024/06/30 20:08:55 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

dl_list	*ft_dllstnew(int i)
{
	dl_list	*elt;

	elt = (dl_list *)malloc(sizeof(*elt));
	if (!(elt))
		return (NULL);
	elt->i = i;
	elt->next = NULL;
	elt->prev = NULL;
	elt->idx = 0;
	return (elt);
}

void	ft_dllstrd(dl_list **lst, int dir)
{
	size_t	i;

	i = *get_size(lst);
	if (i)
	{
		ft_printf("#########################");
		ft_printf("\nhead:%i tail:%i size:%i ",((lst[1])->next)->i, 
				((lst[1])->prev)->i,(lst[1])->idx);
		ft_printf("\n________________________");
		if (dir < 0)
			*lst = (*lst)->prev;
		while (i--)
		{
			ft_printf("\n");
			ft_printf("i:%i ", (*lst)->i);
			ft_printf("idx:%i ", (*lst)->idx);
			ft_printf("prev:%i ", ((*lst)->prev)->i);
			ft_printf("next:%i ", ((*lst)->next)->i);
			if (dir > 0)
				*lst = (*lst)->next;
			else if (dir < 0)
				*lst = (*lst)->prev;
		}
	}
	return ;
}

void	ft_dllstupdate(dl_list **lst)
{
	(lst[1]->prev)->next = lst[1]->next;
	(lst[1]->next)->prev = lst[1]->prev;
	//(lst[1]->next)->idx = 1;
	//(lst[1]->prev)->idx = -1;
}

void	ft_dllstrm(dl_list **lst)
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
	return ;
}
