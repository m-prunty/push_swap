/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:08:58 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/28 03:20:54 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int	rotate(t_dll **lst, int dir)
{
	t_dll	*head;

	if (*(get_size(lst)) < 2)
		return (0);
	if (dir > 0)
	{
		head = (*(get_head(lst)));
		//(*(get_tail(lst)))->idx = 0;
		*(get_tail(lst)) = head;//*(get_head(lst)) 
		*(get_head(lst)) = head->next;//*(get_head(lst)) 
	}
	else if (dir < 0)
	{
		head = (*(get_tail(lst)));
		//(*(get_head(lst)))->idx = 0;
		*(get_head(lst)) = (*(get_tail(lst)));//head;//*(get_head(lst)) 
		*(get_tail(lst)) = head->prev;//*(get_head(lst)) 
	}
    ft_dllstupdate(lst);
	*lst = *(get_head(lst));
	return (1);
}

/* ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
int	ra(t_dll **a)
{
	if (!rotate(a, 1))
		return (error_code(0));
	return (ft_printf("%s\n", "ra"));
}

/* rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
int	rb(t_dll **b)
{
	if (!rotate(b, 1))
		return (error_code(0));
	return (ft_printf("%s\n", "rb"));
}

/* rr : ra and rb at the same time.
 */
int	rr(t_dll **a, t_dll **b)
{
	if ((*get_size(a)) < 2 || (*get_size(b)) < 2)
		return (error_code(4));
	ra(a);
	rb(b);
	return (ft_printf("%s\n", "rr"));
}
