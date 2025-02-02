/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:56 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/02 14:31:12 by mprunty          ###   ########.fr       */
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

void	ft_dealloc(t_dll **lst)
{
	t_dll	*tmp;
	int	 	i;

	i = *(get_size(lst));
	if (!i)
		free(*lst);
	while (i--)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(lst[1]);
	free(lst[2]);
	return ;
}
t_loc	for_topa(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (BOTTOM_B);
	else if (get_fin_idx(*a) <= mid)
		return (TOP_B);
	else
		return (BOTTOM_A);
}

t_loc	for_topb(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (BOTTOM_B);
	else if (get_fin_idx(*a) <= mid)
		return (BOTTOM_A);
	else
		return (TOP_A);
}

t_loc	for_bota(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (BOTTOM_B);
	else if (get_fin_idx(*a) <= mid)
		return (TOP_B);
	else
		return (TOP_A);
}

t_loc	for_botb(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (TOP_B);
	else if (get_fin_idx(*a) <= mid)
		return (BOTTOM_A);
	else
		return (TOP_A);
}

t_loc	get_destination(t_dll **a, t_loc loc, int min, int mid)
{
	//t_idx	idx;

	if (loc == TOP_A)
		return (for_topa(a, min, mid));
	else if (loc == TOP_B)
		return (for_topb(a, min, mid));
	else if (loc == BOTTOM_A)
		return (for_bota(a, min, mid));
	else if (loc == BOTTOM_B)
		return (for_botb(a, min, mid));
	return (0);
}
//calc_chunkrange(t_dll **lst);

t_idx	chunkrange(int start, int fin)//, t_loc loc)
{
	int size;

	size = fin - start; 
	return (ft_idxnew(start + size / 3, start + size / 3 * 2));
}

t_dll	*get_chunk(t_dll **lst, t_loc loc)
{
	t_dll	*chunk;
	int		i;
	int		size;

	i = 0;
	size = loc;
	chunk = lst[2];
	while (i < size)
	{
		chunk = chunk->next;
		i++;
	}
	return (chunk);
}

void	init_chunks(t_dll **lst)
{
	enum e_loc	loc;
	t_dll		*chunk;
	int 		i;
	t_idx		idx;
	t_idx		range;

	idx = ft_idxnew(0, *get_size(lst));
	range = ft_idxnew(0, *get_size(lst));
	i = 0;
	loc = i;
	chunk = lst[2];
	chunk = ft_dllstnew(0, loc,  idx, &range);
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
	t_idx	idx;

	idx = ft_idxnew(INT_MIN, INT_MAX);
	loc = 0;	
	lst[0] =  ft_dllstnew(0, loc, 
			ft_idxnew(INT_MAX, INT_MIN), &idx);
	lst[1] = ft_dllstnew(0, loc, 
			ft_idxnew(INT_MAX, INT_MIN), &idx);
	set_chunks(lst);
	
	return ;
}

/*/
  int main() 
  {

  t_dll *lst[2];
  init_lst(lst);
//ft_dllstadd_back(lst,  ft_dllstnew("1"));
//ft_dllstadd_back(lst,  ft_dllstnew("2"));
ft_dllstadd_front(lst,  ft_dllstnew("3"));
//ft_dllstadd_back(lst,  ft_dllstnew("4"));
//ft_dllstadd_back(lst,  ft_dllstnew("5"));
ft_dllstadd_front(lst,  ft_dllstnew("6"));
ft_dllstadd_front(lst,  ft_dllstnew("7"));
ft_dllstadd_front(lst,  ft_dllstnew("8"));
ft_dllstrd(lst, 1);	
ft_dllstrd(lst, -1);	
//ft_printf("%i", ft_isascii('a'));
//ft_printf("%s", lst->i);
return 0;
}

/*/
