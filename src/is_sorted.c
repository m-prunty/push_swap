/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 03:59:59 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 04:00:21 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * @brief checks if list is sorted in ascending order ie head is min and tail 
 * is max
 *
 * @param lst 
 * @return 1 or 0
 */
int	ft_dllstsorted(t_dll **lst)
{
	t_dll	*ptr;
	int		size;

	ptr = (ft_dllstfind(lst, get_min(lst), *get_size(lst)));
	size = *get_size(lst);
	while (--size)
	{
		if ((ptr)->ele < ((ptr)->next)->ele)
			ptr = (ptr)->next;
		else
			return (0);
	}
	return (1);
}

int	ft_dllstsorted_rev(t_dll **lst)
{
	t_dll	*ptr;
	int		size;

	ptr = (ft_dllstfind(lst, get_max(lst), *get_size(lst)));
	size = *get_size(lst);
	while (--size)
	{
		if ((ptr)->ele > ((ptr)->next)->ele)
			ptr = (ptr)->next;
		else
			return (0);
	}
	return (1);
}

/**
 * @brief get_min from lst and calls ft_dllstfind to return the node and then 
 * calls ft_dllstsorted to check if the list is sorted in ascending order
 *
 * @param lst 
 * @return 1 or 0
 */
int	ft_dllstordered(t_dll **lst)
{
	int		res;

	res = 0;
	if (ft_dllstsorted(lst) || ft_dllstsorted_rev(lst))
		res = 1;
	*lst = *get_head(lst);
	return (res);
}

