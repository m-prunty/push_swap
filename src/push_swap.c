/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:59 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/21 14:40:33 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


int	error_code(int i)
{
	if (i == 0)
		return (0);
	ft_putendl_fd("Error", 2);
	if (i == 1)
		ft_printf("%s", "not a number");
	else if (i == 2)
		ft_printf("%s", "duplicate");
	else if (i == 3)
		ft_printf("%s", "n is larger than int");
	else if (i == 4)
		ft_printf("%s", "lst len is to short");
	else if (i == 5)
		ft_printf("%s", "push failed");
	else if (i == 6)
		ft_printf("%s", "turk sort failed");
	return (0);
}

int	final_position(int *sorted, int i, int len)
{
	int	pos;

	pos = 0;
	while (pos < len && sorted[pos] != i)
		pos++;
	return (pos);
}

t_idx *get_range(t_dll **stack, t_loc_e loc)
{
	return (&(ft_chunk(stack, loc))->range);
}


int	fill_stack(t_dll **stack, long *ilst, int ac)
{
	int		*sorted;
	int		len;
	t_idx	range;
	t_loc_e	loc;
	t_dll	*new_ele;

	loc = TOP_A;
	len = ac - 1;
	sorted = sorted_arr((int *)ilst, len);
	range = ft_idxnew(0, len);
	while (--ac)
	{
		if (*ilst < INT_MAX && *ilst > INT_MIN)
		{
			if (!ft_dllstfind(stack, (int)*ilst, *get_size(stack)))
			{
				new_ele = ft_dllstnew((int)*ilst, loc,
						ft_idxnew(0, final_position(sorted, (int)*ilst, len)),
						range
						);
				ft_dllstadd_back(stack, new_ele);
				(ilst)++;
			}
			else
				return (error_code(2));
		}
		else
		{
			return (error_code(3));
		}
	}
	return (1);
}
