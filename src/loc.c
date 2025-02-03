/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:46:13 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 09:02:21 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_loc	for_topa(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (BOTTOM_B);
	else if (get_fin_idx(*a) <= mid)
		return (TOP_B);
	else
		return (BOTTOM_A);
}

t_loc	for_topb(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (BOTTOM_B);
	else if (get_fin_idx(*a) <= mid)
		return (BOTTOM_A);
	else
		return (TOP_A);
}

t_loc	for_bota(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (BOTTOM_B);
	else if (get_fin_idx(*a) <= mid)
		return (TOP_B);
	else
		return (TOP_A);
}

t_loc	for_botb(t_dll **a, int min, int mid)
{
	/*int moves;

	moves  = 0;*/
	if (get_fin_idx(*a) <= min)
		return (TOP_B);
	else if (get_fin_idx(*a) <= mid)
		return (BOTTOM_A);
	else
		return (TOP_A);
}

t_loc	get_destination(t_dll **a, t_loc loc, int min, int mid)
{
	//t_idx	idx;

	if (loc == TOP_A)
		return (for_topa(a, min, mid));
	else if (loc == TOP_B)
		return (for_topb(a, min, mid));
	else if (loc == BOTTOM_A)
		return (for_bota(a, min, mid));
	else if (loc == BOTTOM_B)
		return (for_botb(a, min, mid));
	return (0);
}
