/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:03:43 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/21 16:22:52 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_dll	*ft_chunk(t_dll **chunk, t_loc_e loc)
{
	/*t_dll	*chunk;
	int		i;

	i = 0;
	chunk = chunk_head(lst);
	while (i < (int)loc)
	{
		chunk = chunk->next;
		i++;
	}*/
	return (chunk[loc]);
}

t_idx	chunkrange(int start, int fin)//, t_loc loc)
{
	int	size;

	size = fin - start;
	return (ft_idxnew(start + size / 3, start + size / 3 * 2));
}

t_dll	*get_chunk(t_dll **chunks, t_loc_e loc)
{
	//int		i;

	//i = 0;
	//while (chunk[i++]->loc != loc)
	//	;
	return (chunks[(int)loc]);
}

void	init_chunks(t_dll **chunks)
{
	int	i;

	i = 0; 
	while (i <= 4)
	{
		chunks[i] = ft_dllstnew(0, (t_loc_e)i, (t_idx){0, 0}, (t_idx){0, 0});
		i++;
	}
}

/*
 * chunks is a a malloc'd array of 5 t_dll pointers.
 */
void	set_chunks(t_dll **chunks, int size, t_loc_e curr_loc, t_idx curr_range)
{
	t_idx	pivot;
	t_loc_e	loc[3];

	pivot = (t_idx){curr_range.x + (size / 3), curr_range.x + (size / 3 * 2)}; 
	loc[0] = set_destination(curr_loc, pivot.x - 1, pivot);
	loc[1] = set_destination(curr_loc, pivot.y - 1, pivot);
	loc[2] = set_destination(curr_loc, size - 1, pivot);
	chunks[0] = ft_dllstnew(size, curr_loc, pivot, curr_range);
	chunks[(int)loc[0]] = ft_dllstnew(pivot.x - curr_range.x,
			loc[0],
			(t_idx){0, 0},
			(t_idx){curr_range.x, pivot.x - 1});
	chunks[(int)loc[1]] = ft_dllstnew(pivot.y - pivot.x,
			loc[1],
			(t_idx){0, 0},
			(t_idx){pivot.x, pivot.y - 1});
	chunks[(int)loc[2]] = ft_dllstnew(curr_range.y - pivot.y,
			loc[2],
			(t_idx){0, 0},
			(t_idx){pivot.y, curr_range.y});
	return ;
}
