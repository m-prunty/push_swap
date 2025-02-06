/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:56:25 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/06 10:37:39 by mprunty          ###   ########.fr       */
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
int	solve_ltthree(t_dll **lst, int lst_loc)
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

t_dll	*rotate_help(t_dll **lst, int n, int lst_loc)
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

int	solve_ltfive_util(t_dll **src, t_dll **dest, int lst_loc)
{
	t_dll	*min;
	t_dll	*chunk;
	int		size;
	int		move;

	chunk = ft_chunk(src, lst_loc);
	size = chunk->ele;
	move = 0;
	while (size-- > 3)
	{
		get_pos(src);
		min = ft_dllstfind(src, chunk->range.x, chunk->ele);
		while ((size > 3) && (min->ele != (*get_head(src))->ele))
			*src = rotate_help(src, min->idx.y, lst_loc);
		if (lst_loc % 2)
			move += pb(src, dest);
		else
			move += pa(dest, src);
	}
	return (move);
}

int	solve_ltfive(t_dll ***ab, int lst_loc)
{
	t_dll	**stack;
	int		move;

	move = 0;
	stack = ab[!(lst_loc % 2)];
	if (ft_dllstordered(stack))
		rotate_ordered(stack);
	if (*get_size(stack) > 3)
	{
		if (lst_loc % 2)
			pb(ab[0], ab[1]);
		else
			pa(ab[0], ab[1]);
	}
	move += (solve_ltthree(stack, lst_loc));
	return (ft_dllstsorted(stack));
}
