/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllcrud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:58:09 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/21 16:32:54 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  ft_dllstnew:
 *      takes an int i and creates a new link in a t_dll, where;
 *      i = i;
 *      next/prev = NULL;
 *      idx = 0;
 */
t_dll	*ft_dllstnew(int i, t_loc_e loc, t_idx idx, t_idx range)
{
	t_dll	*link;

	link = (t_dll *)malloc(sizeof(*link));
	if (!(link))
		return (NULL);
	link->ele = i;
	link->next = NULL;
	link->prev = NULL;
	link->idx = idx;
	link->loc = loc;
	link->range = range;
	return (link);
}

void	ft_dllstrd(t_dll **lst, int dir)
{
	int	i;
	//t_dll *chunk;

	i = *get_size(lst);
	if (i)
	{
		ft_printf("#########################");
		ft_printf("\nhead: %i tail: %i size: %i, med :%i ", ((lst[1])->next)->ele,
			((lst[1])->prev)->ele,*get_size(lst), get_median_idx(lst));
		ft_printf("\n|prev\t|i\t|next\t|cost\t|idx\t|rngx\t|rngy\t|t_loc_e\t|");
		ft_printf("\n----________________________________________----");
		if (dir < 0)
			*lst = (*lst)->prev;
		while (i--)
		{
			//chunk = ft_chunk(lst, (*lst)->loc);
			ft_printf("\n|%i\t|%i\t|%i\t|%i\t|%i\t|%i\t|%i\t|%i\t|",
				((*lst)->prev)->ele, (*lst)->ele, ((*lst)->next)->ele,
				(*lst)->idx.x, (*lst)->idx.y, (*lst)->range.x, (*lst)->range.y,
				(*lst)->loc
				//chunk->range.x, chunk->range.y,
				//chunk->loc
				);
			if (dir > 0)
				*lst = (*lst)->next;
			else if (dir < 0)
				*lst = (*lst)->prev;
		}
		ft_printf("\n");
	}
	return ;
}

/*  ft_dllstupdate:
 *      updates the head and tail reference of lst,
 *      to point at the tail and head respectivley,
 *      maintaining a circular llist
 */
void	ft_dllstupdate(t_dll **lst)
{
	if ((*get_size(lst)))
	{
		(*get_tail(lst))->next = *get_head(lst);
		(*get_head(lst))->prev = *get_tail(lst);
	}
	lst[1]->range.x = get_min(lst);
	lst[1]->range.y = get_max(lst);
}

/*  ft_dllstrm:
 *     removes a node reference from t_dll and relinks with the nodes on either side 
 * */
void	ft_dllstrm(t_dll **lst)
{
	if (*get_size(lst) > 1)
	{
		((*lst)->next)->prev = (*lst)->prev;
		((*lst)->prev)->next = (*lst)->next;
		*get_tail(lst) = (*lst)->prev;
		*get_head(lst) = (*lst)->next;
	}
	else
	{
		*get_tail(lst) = NULL;
		*get_head(lst) = NULL;
	}
	*lst = *get_head(lst);
	return ;
}

