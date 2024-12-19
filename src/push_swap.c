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
int ft_dllstordered(dl_list **lst)
{
    dl_list **tmp;
    tmp = lst;
    *tmp =  (ft_dllstfind(lst, get_min(lst), *get_size(lst)));
    return (ft_dllstsorted(tmp));
}

int	ft_dllstsorted(dl_list **lst)
{
	dl_list	*ptr;
    int size;

	ptr = *lst;
    size = *get_size(lst);
	while (--size)
	{
		if ((ptr)->i < ((ptr)->next)->i)
			ptr = (ptr)->next;
		else
			return (0);
	}
	//ft_printf("%s", "\nis sorted!");
	return (1);
}

dl_list	*ft_dllstfind(dl_list **lst, int i, int len)
{
	if (len < 1)
        return (NULL);
    if ((*lst)->i == i)
        return (*lst);
    return (ft_dllstfind((&(*lst)->next), i, --len));
}

int	error_code(int i)
{
    if (i==0)
        return(0);
    ft_putendl_fd("Error", 2);
    if (i == 1)
        ft_printf("%s","not a number");
    else if (i == 2)
        ft_printf("%s","duplicate");
    else if (i == 3)
        ft_printf("%s","n is larger than int");
    else if (i == 4)
        ft_printf("%s","lst len is to short");
    else if (i == 5)
        ft_printf("%s","push failed");
    else if (i == 6)
        ft_printf("%s","turk sort failed");
    return (0);
}

int	fill_stack(dl_list **stack, int *ilst, int ac)
{
	while (--ac)
	{
		if (!ft_dllstfind(stack, *ilst, *get_size(stack)))
		{
			ft_dllstadd_back(stack, ft_dllstnew(*ilst));
			(ilst)++;
		}
		else
			return (error_code(2));
	}
	return (1);
}
