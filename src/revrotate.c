/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:23 by mprunty           #+#    #+#             */
/*   Updated: 2024/06/30 18:10:02 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 */
int	rra(dl_list **a)
{
	if (!rotate(a, -1))
		return (error_code(0));
	return (ft_printf("%s\n", "rra"));
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 */
int	rrb(dl_list **b)
{
	if (!rotate(b, -1))
		return (error_code(0));
	return (ft_printf("%s\n", "rrb"));
}

/* rrr : rra and rrb at the same time.
 */
int	rrr(dl_list **a, dl_list **b)
{
	if ((*get_size(a)) < 2 || (*get_size(b)) < 2)
		return (error_code(4));
	rra(a);
	rrb(b);
	return (ft_printf("%s\n", "rrr"));
}
