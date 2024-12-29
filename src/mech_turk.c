/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:36:24 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/29 10:13:45 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_median_idx(t_dll **lst)
{
	int	median;

	median = *get_size(lst) / 2 ;
	median += *get_size(lst) % 2 ;
	return (median);
}

int	split_stack(t_dll **a, t_dll **b)
{
	while (*get_size(a) > 3)
		pb(a, b);
	solve_ltthree(a);
	return (0);
}

int	get_cost(t_dll **lst)
{
	t_dll	*cursor;
	int		median;
	int		len;
	int		i;

	if (!*get_size(lst))
		return (-1);
	i = 0;
	len = *get_size(lst);
	if (len <= 1)
	{
		(*get_head(lst))->idx = 0;
		return (0);
	}
	median = get_median_idx(lst);
	cursor = *get_head(lst);
	while (i < median && cursor)
	{
		cursor->idx = i;
		cursor = cursor->next;
		i++;
	}
	while (i < len && cursor)
	{
		cursor->idx = i - len;
		cursor = cursor->next;
		i++;
	}
	return (0);
}

void init_cheapest(t_dll **lst)
{
	*lst = ft_dllstnew(0);
	(*lst)->idx = MAX_INT;
	(*lst)->i = MAX_INT;
	(*lst)->next = NULL;
	(*lst)->prev = NULL;
}
int	cost_analysis(t_dll **a, t_dll **b)
{
	t_dll	*anode;
	t_dll	*bnode;
	int		i;
	int		cost;
	int		found;
	t_dll	**cheapest;

	i = *get_size(b);
	found = 0;
	get_cost(a);
	get_cost(b);
	bnode = *get_head(b);
	cheapest = get_cheapest_pair(b);
	(*cheapest)->next = NULL;
	(*cheapest)->prev = NULL;
	(*cheapest)->idx = MAX_INT;
	(*cheapest)->i = MAX_INT;
	while (i--)
	{
		anode = *get_head(a);
		while (!found )
		{
			if ((bnode->i > anode->prev->i && bnode->i < anode->i)
				|| (anode->prev->i > anode->i && (bnode->i > anode->prev->i
						|| bnode->i < anode->i)))
			{
				found = 1;
			}
			else
				anode = anode->next;
		}
		if (!found)
			anode = *get_head(a); // Default to head if no better position found
		cost = ft_abs(anode->idx) + ft_abs(bnode->idx);
		if (!(*cheapest)->prev || cost < get_cheapest_cost(b))
		{
			(*cheapest)->idx = bnode->idx;
			(*cheapest)->i = anode->idx;
			(*cheapest)->next = bnode;
			(*cheapest)->prev = anode;
		}
		bnode = bnode->next;
	}
	return (0);
}


int	move_nodes(t_dll **a, t_dll **b)
{
	t_dll **cheapest;
	int aidx;
	int bidx;

	cheapest = get_cheapest_pair(b);
	aidx = (*cheapest)->i;
	bidx = (*cheapest)->idx;
	while (aidx && bidx)
	{
		if ((aidx > 0 && bidx > 0) && rr(a,b))
		{
			aidx--;
			bidx--;
		}
		else if ((aidx < 0 && bidx < 0) && rrr(a,b))
		{
			aidx++;
			bidx++;
		}
	}
	while (aidx || bidx)
	{
		if ((aidx > 0) && ra(a))
			aidx--;
		else if ((aidx < 0) && rra(a))
			aidx++;
		if ((bidx > 0) && rb(b))
			bidx--;
		else if ((bidx < 0) && rrb(b))
			bidx++;
	}
	if (*a == (*cheapest)->prev && *b == (*cheapest)->next)
		pa(a, b);
	return (0);
}

int	turk_sort(t_dll **a, t_dll **b)
{
	split_stack(a, b);
	while(*get_size(b))
	{
		cost_analysis(a,b);
		move_nodes(a,b);
		ft_dllstupdate(a);
		ft_dllstupdate(b);
	}
	if (!(ft_dllstordered(a)))
		return (error_code(6));
	if ((*get_head(a))->i != get_min(a))
	{
		get_cost(a);
		(*get_cheapest_pair(a))->i = ft_dllstfind(a, get_min(a), *get_size(a))->idx;
		while (--(*get_cheapest_pair(a))->i > 0)
			ra(a);
		while (++(*get_cheapest_pair(a))->i < 0)
			rra(a);
	}
	if (!(ft_dllstsorted(a)))
		return (error_code(6));
	return 1;
}
