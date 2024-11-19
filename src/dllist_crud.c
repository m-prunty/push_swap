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

/*  ft_dllstnew:
 *      takes an int i and creates a new link in a dl_list, where;
 *      i = i;
 *      next/prev = NULL;
 *      idx = 0;
 */
dl_list	*ft_dllstnew(int i)
{
	dl_list	*link;

	link = (dl_list *)malloc(sizeof(*link));
	if (!(link))
		return (NULL);
	link->i = i;
	link->next = NULL;
	link->prev = NULL;
	link->idx = 0;
	return (link);
}

void	ft_dllstrd(dl_list **lst, int dir)
{
	size_t	i;

	i = *get_size(lst);
	if (i)
	{
		ft_printf("#########################");
		ft_printf("\nhead:%i tail:%i size:%i ",((lst[1])->next)->i, 
				((lst[1])->prev)->i,*get_size(lst));
        ft_printf("\n|prev\t|i\t|next\t|idx\t|");
		ft_printf("\n----________________________----");
		if (dir < 0)
			*lst = (*lst)->prev;
		while (i--)
		{
			ft_printf("\n");
			ft_printf("|%i\t", ((*lst)->prev)->i);
			ft_printf("|%i\t", (*lst)->i);
			ft_printf("|%i\t", ((*lst)->next)->i);
			ft_printf("|%i\t|", (*lst)->idx);
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
void	ft_dllstupdate(dl_list **lst)
{
	(*get_tail(lst))->next = *get_head(lst);
	(*get_head(lst))->prev = *get_tail(lst);
	//(*get_head(lst))->idx = 1;
	//(*get_tail(lst))->idx = -1;
}
/*  ft_dllstrm:
 *     removes a node reference from dl_list and relinks with the nodes on either side  
 * */
void	ft_dllstrm(dl_list **lst)
{
	((*lst)->next)->prev = (*lst)->prev;
	((*lst)->prev)->next = (*lst)->next;
    *get_tail(lst) = (*lst)->prev;
    *get_head(lst) = (*lst)->next;
	if ((*lst)->idx != 0)
	{
		(*get_head(lst))->idx = (*lst)->idx;
		(*lst)->idx = 0;
	}
	*lst = *(get_head(lst));// get_head(lst);
    //ft_dllstrd(lst, 1);
	return ;
}
