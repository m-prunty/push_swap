/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:03:03 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 04:03:23 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* get_tail:
 * 	 Returns the tail of lst, a pointer stored at lst[1].prev */
t_dll	**get_tail(t_dll **lst)
{
	return (&lst[1]->prev);
}

/* get_head:
 * 	 Returns the head of list a pointer stored at lst[1].next */
t_dll	**get_head(t_dll **lst)
{
	return (&lst[1]->next);
}

/* get_size:
 * 	 Returns the size of lst i.e number of nodes.
 *  an integer stored at lst[1].i */
int	*get_size(t_dll **lst)
{
	return (&lst[1]->ele);
}

t_idx	*get_minmax(t_dll **lst)
{
	return (&lst[1]->idx);
}

/*  reset_head:
 *      attachs a new head to the head pointer at lst 1 next
 */
void	reset_head(t_dll **lst, t_dll *head)
{
	*(get_head(lst)) = head;
	*(get_tail(lst)) = head->prev;
	ft_dllstupdate(lst);
	return ;
}
