/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:42:06 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 08:24:34 by mprunty          ###   ########.fr       */
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
int	get_min_rec(t_dll *lst, int min, int len)
{
	if (!len)
		return (min);
	if (lst->ele < min)
		min = lst->ele;
	if (len--)
		min = (get_min_rec(lst->next, min, len));
	return (min);
}

int	get_min(t_dll **lst)
{
	t_dll	*tmp;
	int		min;
	int		i;

	tmp = *lst;
	min = INT_MAX;
	i = *get_size(lst);
	return (get_min_rec(tmp, min, i));
}

int	get_max_rec(t_dll *lst, int max, int len)
{
	if (!len)
		return (max);
	if (lst->ele > max)
		max = lst->ele;
	if (len--)
		max = (get_max_rec(lst->next, max, len));
	return (max);
}

int	get_max(t_dll **lst)
{
	t_dll	*tmp;
	int		i;

	tmp = *lst;
	i = *get_size(lst);
	return (get_max_rec(tmp, INT_MIN, i));
}


