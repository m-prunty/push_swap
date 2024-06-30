/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:25:42 by mprunty           #+#    #+#             */
/*   Updated: 2024/06/30 19:52:51 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	ft_dllstadd_back(dl_list **lst, dl_list *new)
{
	dl_list	*last;

	if (lst)
	{
		new->idx = -1;
		if (lst[1]->prev)
		{
			new->next = lst[1]->next;
			last = lst[1]->prev;
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
		ft_dllstupdate(lst);
	}
}

void	ft_dllstadd_front(dl_list **lst, dl_list *new)
{
	if (lst)
	{
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
		if (!lst[1]->prev)
			lst[1]->prev = new;
		lst[1]->next = new;
		lst[1]->idx += 1;
		ft_dllstupdate(lst);
	}
}
