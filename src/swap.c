/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:08:58 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/28 03:20:10 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int	swap(t_dll **lst)
{
	t_dll	*two;
	t_dll	*three;

	if (*(get_size(lst)) == 2)
		return (rotate(lst, 1));
	if (*(get_size(lst)) < 2)
		return (0);
	two = *lst;
    ft_dllstrm(lst);
 
    three = ((*get_head(lst))->next);
	//three->idx = 1;
	three->prev = two;
	two->next = three;
	two->prev = *(get_head(lst));
	//two->idx = -1;
	//two->prev->idx = 0;
	((*get_head(lst))->next) = two;
	ft_dllstupdate(lst);
/*	if ((*lst)->idx == -1)
	{
		(*lst)->idx = 0;
		(*lst)->next->idx = -1;
	}i
    */
	return (1);
}

/* sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 */
int	sa(t_dll **a)
{
	if (!swap(a))
		return (error_code(0));
	return (ft_printf("%s\n", "sa"));
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 */
int	sb(t_dll **b)
{
	if (!swap(b))
		return (error_code(0));
	return (ft_printf("%s\n", "sb"));
}

/* ss : sa and sb at the same time.
 */
int	ss(t_dll **a, t_dll **b)
{
	if ((*get_size(a)) < 2 || (*get_size(b)) < 2)
		return (error_code(4));
	swap(a);
	swap(b);
	return (ft_printf("%s\n", "ss"));
}
