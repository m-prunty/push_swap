/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:56:25 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 08:57:24 by mprunty          ###   ########.fr       */
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
		if (!lst_loc)
			sa(lst);
		else
			sb(lst);
	}
	return (0);
}

t_dll	*rotate_help(t_dll **lst, int n, int lst_loc)
{
	if (lst_loc == 0)
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

int	solve_ltfive_util(t_dll **a, t_dll **b, int lst_loc)
{
	t_dll	*min;
	int		i;
	int		move;
	
	if (lst_loc == 0)
	{
		min = ft_dllstfind(a, get_min(a), *get_size(a));
		i = 0;
		move = 0;
		while ((*get_size(a) > 3) && (min->ele != (*get_head(a))->ele))
		{
			*a = rotate_help(a, 1, lst_loc);
			i++;
		}
		if ((*get_size(a) > 3))
			move += pb(a, b);
	}
	else
	{
		min = ft_dllstfind(a, get_min(a), *get_size(a));
		i = 0;
		move = 0;
		while ((*get_size(a) > 3) && (min->ele != (*get_head(a))->ele))
		{
			*a = rotate_help(a, 1, lst_loc);
			i++;
		}
		if ((*get_size(a) > 3))
			move += pa(a, b);
	}
	return (move);
}

int	solve_ltfive(t_dll **a, t_dll **b, int lst_loc)
{
//	t_dll	*min;
	int		i;
	int		move;

	move = 0;
	if (ft_dllstordered(a))
		rotate_ordered(a);
	if (ft_dllstsorted(a))
		return (1);
	i = 0;
	while (*get_size(a) > 3)
		move += solve_ltfive_util(a, b, lst_loc);
	move += (solve_ltthree(a, lst_loc));
	while (*get_size(a) < 5)
		i += pa(a, b);
	return (ft_dllstsorted(a));
}
