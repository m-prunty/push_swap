/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:56:25 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/21 19:33:51 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_ordered(t_dll **lst)
{
	t_dll	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp->ele != get_min(lst))
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *get_head(lst);
	if (i > *get_size(lst) / 2)
	{
		while (tmp->ele != get_min(lst) && rra(lst))
			tmp = tmp->prev;
	}
	else
	{
		while (tmp->ele != get_min(lst) && ra(lst))
			tmp = tmp->next;
	}
}

/*
 * solve_ltthree:
 *	  checks if first or 2nd is max and if so ensures
 *	  its last using ra/rra or:
 *	  checks if first is bigger and if so swaps.
 */
int	solve_ltthree(t_dll **lst, t_loc_e lst_loc)
{
	if ((*get_head(lst))->ele == get_max(lst))
		rotate_help(lst, 1, lst_loc);
	else if (((*lst)->next)->ele == get_max(lst))
		rotate_help(lst, -1, lst_loc);
	if ((*get_head(lst))->ele > ((*lst)->next)->ele)
	{
		if (lst_loc % 2)
			sa(lst);
		else
			sb(lst);
	}
	return (0);
}

t_dll	*rotate_help(t_dll **lst, int n, t_loc_e lst_loc)
{
	if (lst_loc % 2)
	{
		if (n > 0)
			while (n--)
				ra(lst);
		else
			while (n++)
				rra(lst);
	}
	else
	{
		if (n > 0)
			while (n--)
				rb(lst);
		else
			while (n++)
				rrb(lst);
	}
	return (*lst);
}

t_dll	*find_in_chunk(t_dll **ab, int i, t_loc_e lst_loc)
{
	t_dll	*tmp;

	tmp = ab[!(lst_loc % 2)];
	while (tmp->loc != lst_loc && !(tmp->idx.y == i ))
		tmp = tmp->next;
	return (tmp);
}
t_dll	*get_min_in_chunk(t_dll ***ab, t_dll *chunk)
{
	t_dll	*tmp;
	t_dll	*min;
	int		size;

	tmp = *ab[!(chunk->loc % 2)];
	min = tmp;
	size = chunk->ele;
	while (size--)//tmp->loc != chunk->loc)
	{
		if (tmp->loc == chunk->loc && size--)
			if (tmp->ele < min->ele)
				min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
int	solve_ltfive_util(t_dll ***ab, t_dll *chunk, t_loc_e lst_loc)
{
	t_dll	*min;
	t_dll	**src;
	int		size;
	int		move;

	src = ab[!(lst_loc % 2)];
	//chunk =	ft_chunk(src, lst_loc);	//chunk_head(src);//
	size = chunk->ele;
	move = 0;
	while (size-- > 3)
	{
		get_pos(src);
		min = get_min_in_chunk(ab, chunk);
		chunk->range.x += 1;
		*src = rotate_help(src, min->idx.x, lst_loc);
		if (lst_loc % 2)
			move += pb(ab[0], ab[1]);
		else
			move += pa(ab[0], ab[1]);
	}
	return (move);
}

int	solve_ltfive(t_dll ***ab, t_dll *chunk, t_loc_e lst_loc)
{
	t_dll	**stack;
	int		move;
	int		size;

	move = 0;
	stack = ab[!(lst_loc % 2)];
	size = chunk->ele;//chunk_head(stack)->ele;
	if (size >= 3)
		move += solve_ltfive_util(ab, chunk, lst_loc);
	move += (solve_ltthree(stack, lst_loc));
	while (size-- > 3)

	{
		if (lst_loc % 2)
			move += pa(ab[0], ab[1]);
		else
			move += pb(ab[0], ab[1]);
	}
	return (move);//(ft_dllstsorted(stack));
}
/*
		if (lst_loc % 2)
			pb(ab[0], ab[1]);
		else
			pa(ab[0], ab[1]);
			*/
