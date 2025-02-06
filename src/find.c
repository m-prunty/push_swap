/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:01:27 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/05 06:19:31 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * @brief finds the node with the value i in the list and returns it
 *
 * @param lst 
 * @param i 
 * @param len 
 * @return *t_dll ptr to node
 */
t_dll	*ft_dllstfind(t_dll **lst, int i, int len)
{
	if (len < 1)
		return (NULL);
	if ((*lst)->ele == i)
		return (*lst);
	return (ft_dllstfind((&(*lst)->next), i, --len));
}

t_dll	*ft_dllstfind_finidx(t_dll **lst, int i, int len)
{
	if (len < 1)
		return (NULL);
	if ((*lst)->idx.y == i)
		return (*lst);
	return (ft_dllstfind_finidx((&(*lst)->next), i, --len));
}
