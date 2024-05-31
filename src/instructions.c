/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:23 by mprunty           #+#    #+#             */
/*   Updated: 2024/04/26 19:57:07 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 */
int	sa(dl_list **a)
{
	if (!swap(a))
		return (error_code(0));
	return (ft_printf("%s\n", "sa"));
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 */
int	sb(dl_list **b)
{
	if (!swap(b))
		return (error_code(0));
	return (ft_printf("%s\n", "sb"));
}

/* ss : sa and sb at the same time.
 */
int	ss(dl_list **a, dl_list **b)
{
	if ((*get_size(a)) < 2 || (*get_size(b)) < 2)
		return (error_code(4));
	swap(a);
	swap(b);
	return (ft_printf("%s\n", "ss"));
}

/* pa (push a): Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
int	pa(dl_list **a, dl_list **b)
{
	if (!push(b, a))
		return (error_code(0));
	return (ft_printf("%s\n", "pa"));
}

/* pb (push b): Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
int	pb(dl_list **a, dl_list **b)
{
	if (!push( a, b))
		return (error_code(0));
	return (ft_printf("%s\n", "pb"));
}

/* ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
int	ra(dl_list **a)
{
	if (!rotate(a, 1))
		return (error_code(0));
	return (ft_printf("%s\n", "ra"));
}

/* rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
int	rb(dl_list **b)
{
	if (!rotate(b, 1))
		return (error_code(0));
	return (ft_printf("%s\n", "rb"));
}

/* rr : ra and rb at the same time.
 */
int	rr(dl_list **a, dl_list **b)
{
	if ((*get_size(a)) < 2 || (*get_size(b)) < 2)
		return (error_code(4));
	ra(a);
	rb(b);
	return (ft_printf("%s\n", "rr"));
}

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
