/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:45:29 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/13 19:03:30 by mprunty          ###   ########.fr       */
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
	t_dll	*tmp;
	int		i;

	i = 0;
	tmp = chunk_head(lst);
	while (tmp)
	{
		ft_printf("Chunk %d: %d - %d | size; %d \n", i, tmp->range.x, tmp->range.y, tmp->ele);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	split_stack(t_dll ***ab, int start, int size, int lst_loc)
{
	t_dll	**stack;
	t_dll	*chunk;
	int		moves;

	moves = 0;
	stack = ab[!(lst_loc % 2)];
	ft_dllstrd(stack, 1);
	chunk_set_head(stack, start, size, lst_loc);
	print_chunks(stack);
	chunk = chunk_head(stack); 
	if (size <= 5)
		return (solve_ltfive(ab, lst_loc));
	while (size--)
	{
		(*stack)->loc = set_destination((*stack)->loc, (*stack)->idx.y,  chunk->range);
		move_destinations(ab[0], ab[1], 1);
	}
	size = chunk->ele;
	split_stack(ab, chunk->range.y, size - 2 * size / 3,
			set_destination(lst_loc,  size - 1, chunk->range));
	split_stack(ab, chunk->range.x, size,
			set_destination(lst_loc, chunk->range.y - 1, chunk->range));
	split_stack(ab, start, size / 3,
			set_destination(lst_loc, chunk->range.x - 1, chunk->range));
	return (moves);
}

int sort(t_dll ***ab)
{
	int	moves;
	int	size;

	moves = 0;
	if (*get_size(*ab) <= 3)
		return (solve_ltfive(ab, 1));
	get_pos(ab[0]);
	get_pos(ab[1]);
	size = *get_size(ab[0]);
	moves += split_stack(ab, 0, size, 1);
	return (moves);
}

