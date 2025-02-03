/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:40:02 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 09:44:44 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_chunks(t_dll **lst)
{
	enum e_loc	loc;
	t_dll		*chunk;
	int			i;
	t_idx		idx;
	t_idx		range;

	idx = ft_idxnew(0, *get_size(lst));
	range = ft_idxnew(0, *get_size(lst));
	i = 0;
	loc = i;
	chunk = lst[2];
	chunk = ft_dllstnew(0, loc, idx, &range);
	while (++i < 5)
	{
		loc = i;
		chunk->next = ft_dllstnew(0, loc, ft_idxnew(INT_MAX, INT_MIN), &idx);
		chunk->range = &idx;
	}
}

/*  init_lst:
 *      allocates memory for new structure comprised of three t_dll.
 *      t_dll at idx 0 behaves like normal double-linked, i.e;
 *          lst->next/previous are respective nodes in the list.
 *          lst->i = node value int.
 *          lst->idx = index int.
 *
 *      t_dll at idx 1 stores pointers to:
 *          lst->next/previous = pointers to head/tail
 *          lst->i = size
 * 
 *      t_dll at idx 2 stores pointers to:
 *          lst->next/previous = pointers to cheapest this/other
 *          lst->i =  cheappest value
 *          lst->idx = cheapest idx
 */
void	init_lst(t_dll **lst)
{
	enum e_loc	loc;
	t_idx		idx;

	idx = ft_idxnew(INT_MIN, INT_MAX);
	loc = 0;
	lst[0] = ft_dllstnew(0, loc,
			ft_idxnew(INT_MAX, INT_MIN), &idx);
	lst[1] = ft_dllstnew(0, loc,
			ft_idxnew(INT_MAX, INT_MIN), &idx);
	init_chunks(lst);
	return ;
}


