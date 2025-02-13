/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:03:43 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/13 13:10:16 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_dll	*ft_chunk(t_dll **lst, t_loc loc)
{
	t_dll	*chunk;
	int		i;

	i = 0;
	chunk = chunk_head(lst);
	while (i < (int)loc)
	{
		chunk = chunk->next;
		i++;
	}
	return (chunk);
}

t_idx	chunkrange(int start, int fin)//, t_loc loc)
{
	int	size;

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
