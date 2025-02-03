/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:09:34 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 07:36:23 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	dllstget_dist(t_dll **lst, t_dll *node, int dir)
{
	int	i;

	i = 0;
	if (dir < 0)
	{
		while (node != *get_tail(lst))
		{
			i++;
			*node = *node->next;
		}
	}
	else if (dir > 0)
	{
		while (node != *get_head(lst))
		{
			i++;
			*node = *node->next;
		}
	}
	return (i);
}

int	clear_all(t_dll **a, t_dll **b, int *intv)
{
	ft_dealloc(a);
	ft_dealloc(b);
	free(intv);
	return (1);
}
t_dll	*dllstgoto(t_dll **lst, int pos)
{
	t_dll	*node;

	node = *lst;
	while (pos--)
		node = (node)->next;
	return (node);
}

int	main(int ac, char **av)
{
	t_dll	*a[3];
	t_dll	*b[3];
	long	*intv;
	char	**charv;

	charv = check_args(&ac, av);
	intv = (long *)malloc((ac - 1) * sizeof(long));
	if (!intv || !charv || !*charv)
		return (error_code(1));
	fill_intv(ac - 1, ac - 1, charv, intv);
	free(charv);
	init_lst(a);
	init_lst(b);
	if (fill_stack(a, intv, ac))
	{
		if (ft_dllstsorted(a))
			return (clear_all(a, b, (int *)intv));
		else
			turk_sort(a, b);
	}
	ft_dllstrd(a, 1);
	ft_dllstrd(b, 1);
	return (clear_all(a, b, (int *)intv));
}
