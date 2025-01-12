/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:59 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/08 00:01:28 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * @brief get_min from lst and calls ft_dllstfind to return the node and then 
 * calls ft_dllstsorted to check if the list is sorted in ascending order
 *
 * @param lst 
 * @return 1 or 0
 */
int	ft_dllstordered(t_dll **lst)
{
	int		res;

	*lst = (ft_dllstfind(lst, get_min(lst), *get_size(lst)));
	res = ft_dllstsorted(lst);
	*lst = *get_head(lst);
	return (res);
}

/**
 * @brief checks if list is sorted in ascending order ie head is min and tail 
 * is max
 *
 * @param lst 
 * @return 1 or 0
 */
int	ft_dllstsorted(t_dll **lst)
{
	t_dll	*ptr;
	int		size;

	ptr = *lst;
	size = *get_size(lst);
	while (--size)
	{
		if ((ptr)->i < ((ptr)->next)->i)
			ptr = (ptr)->next;
		else
			return (0);
	}
	return (1);
}

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
	if ((*lst)->i == i)
		return (*lst);
	return (ft_dllstfind((&(*lst)->next), i, --len));
}

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

int	fill_stack(t_dll **stack, long *ilst, int ac)
{
	int		*sorted;

	sorted = sorted_arr((int *)ilst, ac);
	while (--ac)
	{
		if (*ilst < INT_MAX && *ilst > INT_MIN)
		{
	 		if (!ft_dllstfind(stack, (int)*ilst, *get_size(stack)))
			{
				ft_dllstadd_back(stack, ft_dllstnew((int)*ilst,
						ft_idxnew(0, final_position(sorted, (int)*ilst, ac))));
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
