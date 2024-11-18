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

void	ft_dllstadd_back(dl_list **lst, dl_list *new_link)
{
	dl_list	*last;

	if (lst)
	{
	//	new_link->idx = -1;
		if (*get_tail(lst))
		{
			new_link->next = *get_head(lst);
			last = *get_tail(lst);
			new_link->prev = last;
			last->next = new_link;
			last->idx = 0;
		}
		else
		{
			new_link->prev = new_link;
			new_link->next = new_link;
			free(*lst);
			*lst = new_link;
			*get_head(lst) = new_link;
		}
		*get_tail(lst) = new_link;
		*get_size(lst) += 1;
		if (*get_size(lst) > 1)
			lst[0]->idx = 1;
		ft_dllstupdate(lst);
	}
}

void	ft_dllstadd_front(dl_list **lst, dl_list *new_link)
{
	if (lst)
	{
		if (*get_head(lst))
		{
			new_link->next = *lst;
			new_link->prev = (lst[1])->prev;
			(*lst)->prev = new_link;
			(*lst)->idx = 0;
		}
		else
			free(*lst);
		*lst = new_link;
		(*lst)->idx = 1;
		if (*get_size(lst) < 2)
			(*lst)->idx = -1;
		if (!*get_tail(lst))
			*get_tail(lst) = new_link;
		*get_head(lst) = new_link;
		*get_size(lst) += 1;
		ft_dllstupdate(lst);
	}
}
