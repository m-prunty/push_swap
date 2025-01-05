/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:25:42 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/04 14:54:30 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * @brief adds link to back of list and sets it as tail (also sets it to head 
 * if tail does not exist)
 *
 * @param lst 
 * @param new_link 
 */
void	ft_dllstadd_back(t_dll **lst, t_dll *new_link)
{
	t_dll	*last;

	if (lst)
	{
		if (*get_tail(lst))
		{
			new_link->next = *get_head(lst);
			last = *get_tail(lst);
			new_link->prev = last;
			last->next = new_link;
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
		ft_dllstupdate(lst);
	}
}

/**
 * @brief adds link to front of list nand sets it to head (also sets it to tail
 * if head does not exist)
 *
 * @param lst 
 * @param new_link 
 */
void	ft_dllstadd_front(t_dll **lst, t_dll *new_link)
{
	if (lst)
	{
		if (*get_head(lst))
		{
			new_link->next = *lst;
			new_link->prev = *get_tail(lst);
			(*lst)->prev = new_link;
		}
		*lst = new_link;
		if (!*get_tail(lst))
			*get_tail(lst) = new_link;
		*get_head(lst) = new_link;
		*get_size(lst) += 1;
		ft_dllstupdate(lst);
	}
}
