/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:29:59 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/22 13:28:52 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* get_cheapest:
 * 	 Returns the  a pointer to the info on cheapest nodes.
 * 	 a pointer stored at lst[2]
 *          lst->next/previous = pointers to cheapest this/other
 *          lst->i =  cheappest idx b
 *          lst->idx = cheapest idx a
 * 	 */
t_dll	**get_storage(t_dll **lst)
{
	return (&lst[2]);
}

int	ft_abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (-i);
}

int	calc_cheapest(t_dll **anode, t_dll **bnode)
{
	int	cost;

	cost = (ft_abs((*anode)->idx.x) + ft_abs((*bnode)->idx.x));
	return (cost);
}
/* get_cheapest_cost:
 * 	 Returns the cheapest move cost found so far,absolute sum of;
 * 	 lst[2].i - bindex and lst[2].idx - aindex */
/*
int	get_cheapest_cost(t_dll **lst)
{
	int	cost;

	cost = (ft_abs((lst[2])->idx) + ft_abs((lst[2])->i));
	return (cost);
}*/
