/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:45:29 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/21 18:53:42 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
t_idx chunk_range(t_dll **src, int size)
{
	int	i;

	i = 5;
	//get_min_node(src, size);
	while (i--)
		ft_chunk(src, i)->range = ((t_idx){size / 3 , size / 3 * 2});
	return (ft_chunk(src, 0)->range);
}
/*
void	subtriangle(t_fractal *f, t_tri *p_tri, t_tri *c_tri, int depth)
{
	t_tri	parent[3];
	t_tri	child[3];
	int		i; 
	int		colour;

	i = 3;
	if (depth >= f->iters)
		return ;
	draw_triangle(f, c_tri, c_tri->colour + f->colour_shift);
	set_triangles(parent, child, c_tri, p_tri);
	colour = ((int)((c_tri->colour >> 16) * 0.9) << 16)
		+ ((int)(((c_tri->colour >> 8)) * 0.9) << 8)
		+ (int)((c_tri->colour) * 0.9);
	while (--i + 1)
	{
		child[i].colour = colour;
		subtriangle(f, &parent[i], &child[i], depth + 1);
	}
}

void	triangle(t_fractal *f, t_tri *t)
{
	t_complex	pixel;
	t_tri		child;

	pixel = (t_complex){0, 0};
	while (pixel.y < f->imgsize.y)
	{
		draw_line(f, pixel, (t_complex){f->imgsize.x, pixel.y}, BLACK);
		pixel.y++;
	}
	draw_triangle(f, t, t->colour + f->colour_shift);
	child.colour = RED + f->colour_shift;
	set_midpoint(&child.a, &t->a, &t->c);
	set_midpoint(&child.b, &t->b, &t->c);
	set_midpoint(&child.c, &t->a, &t->b);
	subtriangle(f, t, &child, 1);
}
*/
int	print_chunks(t_dll **lst)
{
	//t_dll	*tmp;
	int		i;

	i = 0;
	//tmp = chunk_head(lst);
	while (i < 5)
	{
		ft_printf("Chunk %d: %d - %d | size; %d \n", i, lst[i]->range.x, lst[i]->range.y, lst[i]->ele);
		i++;
	}
	return (0);
}

int	split_stack(t_dll ***ab, t_idx range, t_loc_e lst_loc)
{
	t_dll	**stack;
	t_dll	*chunks[5];
	t_dll	*curr_chunk;
	int		moves;
	int 	size;

	size = range.y - range.x;
	moves = 0;
	stack = ab[!(lst_loc % 2)];
//	chunks = malloc(sizeof(t_dll *) * 4);
	//ft_dllstrd(stack, 1);
	init_chunks(chunks);
	set_chunks(chunks, size, lst_loc, range);
	curr_chunk = chunks[0];//get_chunk(chunks, lst_loc);
	//chunk_set_head(stack, start, size, lst_loc);
	print_chunks(chunks);
	//chunk = //chunk_head(stack); 
	if (size <= 5)
		return (solve_ltfive(ab, *chunks, lst_loc));
	while (size--)
	{
		(*stack)->loc = set_destination((*stack)->loc, (*stack)->idx.x,  curr_chunk->idx);
		move_destinations(ab[0], ab[1], 1);
	}
	size = curr_chunk->ele;
	split_stack(ab, 
			(t_idx){curr_chunk->idx.y, size},
			set_destination(lst_loc,  size - 1, curr_chunk->idx));
	split_stack(ab, 
			(t_idx){curr_chunk->idx.x, size - 2 * size / 3},
			set_destination(lst_loc, curr_chunk->range.y - 1, curr_chunk->range));
	split_stack(ab, 
			(t_idx){curr_chunk->range.x, size / 3},
			set_destination(lst_loc, curr_chunk->range.x - 1, curr_chunk->range));
//	free(chunks);
	return (moves);
}

int sort(t_dll ***ab)
{
	int	moves;
	int	size;

	moves = 0;
	if (*get_size(*ab) <= 3)
		return (solve_ltfive(ab, NULL, 1));
	get_pos(ab[0]);
	get_pos(ab[1]);
	size = *get_size(ab[0]);
	moves += split_stack(ab, (t_idx){0, size}, 1);
	return (moves);
}

