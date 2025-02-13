/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:42:06 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/07 21:38:44 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_dll	*get_min_node(t_dll *lst, int size)
{
	t_dll	*min;

	min = lst;
	while (size--)
	{
		if ((lst)->ele < min->ele)
			min = lst;
		lst = (lst)->next;
	}
	return (min);
}

t_dll	*get_max_node(t_dll *lst, int size)
{
	t_dll	*max;

	max = lst;
	while (size--)
	{
		if ((lst)->ele > max->ele)
			max = lst;
		lst = (lst)->next;
	}
	return (max);
}

int	get_min(t_dll **lst)
{
	t_dll	*tmp;
	int		min;
	int		i;

	tmp = *lst;
	min = INT_MAX;
	i = *get_size(lst);
	while (i--)
	{
		if (tmp->ele < min)
			min = tmp->ele;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_dll **lst)
{
	t_dll	*tmp;
	int		i;
	int		max;

	max = INT_MAX;
	tmp = *lst;
	i = *get_size(lst);
	while (i--)
	{
		if (tmp->ele > max)
			max = tmp->ele;
		tmp = tmp->next;
	}
	return (max);
}


