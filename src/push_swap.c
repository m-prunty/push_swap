/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:59 by mprunty           #+#    #+#             */
/*   Updated: 2024/06/30 18:17:32 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int	ft_dllstsorted(dl_list **lst)
{
	dl_list	*ptr;

	ptr = *lst;
	while ((ptr)->idx >= 0)
	{
		if ((ptr)->i < ((ptr)->next)->i)
			ptr = (ptr)->next;
		else
			return (0);
	}
	//ft_printf("%s", "\nis sorted!");
	return (1);
}

int	ft_dllstfind(dl_list **lst, int i)
{
	//dl_list tmp;
	if (!(*get_size(lst)))
		return (0);
	if ((*lst)->i == i)
		return (1);
	if ((*lst)->idx != -1)
		return (ft_dllstfind((&(*lst)->next), i));
	return (0);
}

int	error_code(int i)
{
	ft_putendl_fd("Error", 2);
	i++;
	/*/
	 * if (i == 1)
		ft_printf("%s","not a number");
	else if (i == 2)
		ft_printf("%s","duplicate");
	else if (i == 3)
		ft_printf("%s","n is larger than int");
	else if (i == 4)
		ft_printf("%s","lst len is to short");
	/*/
	return (0);
}

int	fill_stack(dl_list **stack, int *ilst, int ac)
{
	while (--ac)
	{
		if (!ft_dllstfind(stack, *ilst))
		{
			ft_dllstadd_back(stack, ft_dllstnew(*ilst));
			(ilst)++;
		}
		else
			return (error_code(2));
	}
	return (1);
}
