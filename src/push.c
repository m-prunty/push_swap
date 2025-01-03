/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:08:58 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/28 03:29:00 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	push(t_dll **src, t_dll **dest)
{
	t_dll	*tmp;

	if (*(get_size(src)) < 1)
		return (0);
	tmp = *src;
	ft_dllstrm(src);
	*(get_size(src)) -= 1;
	ft_dllstadd_front(dest, tmp);
	*dest = *get_head(dest);
    ft_dllstupdate(src);
	//ft_dllstupdate(dest);
	return (1);
}

/* pa (push a):
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty. */
int	pa(t_dll **a, t_dll **b)
{
	if (!push(b, a))
		return (error_code(0));
	return (ft_printf("%s\n", "pa"));
}

/* pb (push b):
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
int	pb(t_dll **a, t_dll **b)
{
	if (!push(a, b))
		return (error_code(0));
	return (ft_printf("%s\n", "pb"));
}
