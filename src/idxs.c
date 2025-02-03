/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idxs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:59:27 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 04:54:01 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_idx	ft_idxnew(int x, int y)
{
	t_idx	idx;

	idx.x = x;
	idx.y = y;
	return (idx);
}

int	get_median_idx(t_dll **lst)
{
	int	size;

	if (!lst || !*lst)
		return 0;
	size = *get_size(lst);
	return (size / 2 + size % 2);
}

int	get_pos(t_dll **lst)
{
	t_dll	*cursor;
	int		median;
	int		size;
	int		i;

	i = 0;
	if (!lst || !*lst || !*get_size(lst))
		return (-1);
	size = *get_size(lst); 
	median = get_median_idx(lst);
	cursor = *get_head(lst);
	while (i < size && cursor)
	{
		if (i < median)
		{
			cursor->idx.x = i;
			cursor = cursor->next;
			i++;
		}
		else
		{
			cursor->idx.x = -(size - i);
			cursor = cursor->next;
			i++;
		}
	}
	return (0);
}

int	get_fin_idx(t_dll *node)
{
	return (node->idx.y);
}

void	update_idx(t_dll **a)
{
	(*a)->idx.x = get_fin_idx(*a) + *get_size(a) - (*get_storage(a))->ele;
	return ;
}

