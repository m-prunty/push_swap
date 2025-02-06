/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:09:34 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/06 10:01:13 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_dll	*dllstget_dist(t_dll **lst, int idx)
{
	size_t	size;

	get_pos(lst);
	size = *get_size(lst);
	while ((*lst)->idx.y != idx && size--)
		*lst = (*lst)->next;
	return (*lst);
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
	t_dll	***ab;
	t_dll	*a[3];
	t_dll	*b[3];
	long	*intv;
	char	**charv;

	ft_bzero(a, sizeof(*a) * 3);
	ft_bzero(b, sizeof(*b) * 3);
	ab = (t_dll ***)malloc(sizeof(t_dll **) * 2);
	charv = check_args(&ac, av);
	intv = (long *)malloc((ac - 1) * sizeof(long));
	if (!intv || !charv || !*charv)
		return (error_code(1));
	fill_intv(ac - 1, ac - 1, charv, intv);
	free(charv);
	init_lst(a);
	init_lst(b);
	ab[0] = a;
	ab[1] = b;
	init_chunks(a, b);
	if (fill_stack(a, intv, ac))
	{
		//if (ft_dllstsorted(a))
		//	return (clear_all(a, b, (int *)intv));
		//else
			sort(ab);
	}
	ft_dllstrd(a, 1);
	ft_dllstrd(b, 1);
	return (clear_all(a, b, (int *)intv));
}
