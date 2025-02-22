/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:46:13 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/21 18:23:30 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_dll *chunk_head(t_dll **lst)
{
	return (lst[2]);
}
/*t_idx calc_chunkrange(t_dll *chunk)
{
	chunk->range = (t_idx){
		chunk->range.x + chunk->idx.x / 3,
		chunk->range.x +chunk->idx.x / 3 * 2};	
}
*/ 

void chunk_set_head(t_dll **src, int start, int size, t_loc_e loc)
{
	t_dll	*head;
	t_dll	*min;
	t_dll	*mid;
	t_dll	*max;
	
	head = chunk_head(src);
	head->ele = size;
	head->idx = (t_idx){start, start + size};
	head->range = (t_idx){start + (size / 3), start + (size / 3 * 2)};
	head->loc = loc;
	if (size > 5)
	{
		min = ft_chunk(src, set_destination(loc, head->range.x - 1, head->range));
		mid = ft_chunk(src, set_destination(loc, head->range.y - 1, head->range));
		max = ft_chunk(src, set_destination(loc, start + size - 1, head->range));
		min->range = (t_idx){start, head->range.x - 1};
		mid->range = (t_idx){head->range.x, head->range.y - 1};
		max->range = (t_idx){head->range.y, start + size - 1};
		min->ele = head->range.x - start;
		mid->ele = head->range.y - head->range.x;
		max->ele = start + size - head->range.y;
	}
	else
	{
		max = ft_chunk(src, loc);
		max->range = (t_idx){start, start + size - 1};
		max->ele = size;
	}
}

/*void	calc_chunk(t_dll **src, int start, int size)
  {


//(void)b;
//mid = ft_dllstfind_finidx(a, head->range.x, size); 	
}
*/
t_loc_e	set_destination(t_loc_e loc, int finidx, t_idx pivot)
{
	if (loc % 2)
	{
		if (finidx < pivot.x)
			return (BOTTOM_B);
		else if (finidx < pivot.y)
			return (TOP_B);
		else if (loc == TOP_A)
			return (BOTTOM_A);
		else if (loc == BOTTOM_A)
			return (TOP_A);
	}
	else
	{
		if (finidx < pivot.x && loc == TOP_B)
			return (BOTTOM_B);
		else if (finidx < pivot.x && loc == BOTTOM_B)
			return (TOP_B);
		else if (finidx < pivot.y)
			return (BOTTOM_A);
		else
			return (TOP_A);
	}
	return (loc);
}

void move_destinations(t_dll **a, t_dll **b, t_loc_e loc)
{
	t_loc_e	dest_loc;

	//dest_loc = set_destination(loc, (*a)->idx.y, (*a)->range);
	
	if (loc % 2)
	{
		dest_loc = (*a)->loc;//set_destination(*a, (t_idx){});
		if (dest_loc == 3)
			ra(a);
		if (dest_loc == 1)
			rra(a);
		else if (dest_loc == TOP_B)
			pb(a, b);
		else if (dest_loc == BOTTOM_B && pb(a, b))
			rb(b);
	}
	else
	{
		dest_loc = (*b)->loc;//set_destination(*b, range);
		if (dest_loc == 4)
			rb(b);
		if (dest_loc == 2)
			rrb(b);
		else if (dest_loc == TOP_A)
			pa(a, b);
		else if (dest_loc == BOTTOM_A && pa(a, b))
			ra(a);
	}
}
/*
   t_loc	from_topa(t_dll **a, t_dll **b,  t_loc loc)
   {
   if (loc % 2)
   ra(a);
   else if (loc == TOP_B)
   pb(a, b);
   else if (loc == BOTTOM_B && pb(a, b))
   rb(b);
   }

   t_loc	from_topb(t_dll **a, t_dll **b, t_loc loc)
   {
   if (!(dest_loc % 2))
   rb(a);
   else if (dest_loc == TOP_A)
   pa(a, b);
   else if (dest_loc == BOTTOM_A && pa(a, b))
   ra(b);
   }
   }

   t_loc	from_bota(t_dll **a, t_idx range, t_loc loc)
   {
   if (get_fin_idx(*a) <= range.x)
   (*src)->loc = BOTTOM_B;
   else if (get_fin_idx(*a) <= range.y)
   (*src)->loc = TOP_B;
   else
   (*src)->loc = TOP_A;
   }

   t_loc	from_botb(t_dll **b,  t_idx range, t_loc loc)
   {
   if (get_fin_idx(*b) <= range.x)
   (*src)->loc = TOP_B;
   else if (get_fin_idx(*b) <= range.y)
   (*src)->loc = BOTTOM_A;
   else 
   (*src)->loc = TOP_A;
   }

   t_loc	get_destination(t_dll **a, t_dll**b, t_idx range, t_loc loc)
   {
   int		lst_loc;

   if (loc == TOP_A)
   (*src)->loc = from_topa(a, b, range, loc);
   else if (loc == TOP_B)
   (*src)->loc = from_topb(a, b, range, loc);
   else if (loc == BOTTOM_A)
   (*src)->loc = from_bota(a, b, range, loc);
   else if (loc == BOTTOM_B)
   (*src)->loc = from_botb(a, b, range, loc);
   (*src)->loc = 0;
   }
   */
