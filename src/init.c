/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:40:02 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/22 12:38:29 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
void	init_chunks(t_dll **lst, t_dll **lst2)
{
	enum e_loc	loc;
	t_dll		*chunk;
	int			i;
	t_idx		idx;

	idx = ft_idxnew(0, 0);
	i = 0;
	loc = i;
	chunk = ft_dllstnew(0, loc, idx, idx);
	chunk->range = idx;
	lst[2] = chunk;
	lst2[2] = chunk;
	while (++i < 5)
	{
		chunk->next = ft_dllstnew(0, i, idx, idx);
		chunk = chunk->next;
	}
}
*/
/**
 * @brief 
 * 	 init_lst:
 *      allocates memory for new structure comprised of two t_dll.
 *      t_dll at idx 0 behaves like normal double-linked, i.e;
 *		  	lst->next/prev = pointers to next/previous nodes
 *          lst->ele = node value int.
 *          lst->idx = t_complex where x = cost, y = sorted postion
 *          lst->range = t_complex where x = min, y = max
 *		  	lst->loc = enum t_loc_e of location in list.
 *      t_dll at idx 1 stores pointers to:
 *          lst->next/previous = pointers to head/tail
 *          lst->ele = size of list
 *
 * @param lst a double pointer to the head of a malloc'd t_dll[2] 
 */
void	init_lst(t_dll **lst)
{
	enum e_loc	loc;
	t_idx		idx;

	idx = ft_idxnew(INT_MIN, INT_MAX);
	loc = 0;
	lst[0] = ft_dllstnew(0, loc,
			ft_idxnew(INT_MAX, INT_MIN), idx);
	lst[1] = ft_dllstnew(0, loc,
			ft_idxnew(INT_MAX, INT_MIN), idx);
	return ;
}


