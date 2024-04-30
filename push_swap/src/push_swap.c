/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:59 by mprunty           #+#    #+#             */
/*   Updated: 2024/04/26 20:39:52 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int	ft_dllstsorted(dl_list **lst)
{
	dl_list	*ptr;

	ptr = *lst;
	while ((ptr)->idx >= 0)
		if ((ptr)->i < ((ptr)->next)->i)
			ptr = (ptr)->next;
		else
			return (0);
	//ft_printf("%s", "\nis sorted!");
	return (1);
}

int ft_dllstfind(dl_list **lst, int i)
{
	//dl_list tmp;

	if (!(*get_size(lst)))
		return 0;
	if ((*lst)->i == i)
		return 1;
	if((*lst)->idx != -1)
		return (ft_dllstfind((&(*lst)->next), i));	
	return 0;
}
int	error_code(int i)
{
	ft_putendl_fd("Error", 2);
	i++;
	//ft_printf("\n%s","Error: ");
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
	return (1);
}
int	fill_stack(dl_list **stack, int *ilst, int ac) 
{
	int atoi;

	while(*ilst)
	{
		//if (ft_isnum(*av))
		//{
			if (!ft_dllstfind(stack, atoi))
			{
				//*ilst = atoi;
				ft_dllstadd_back(stack,  ft_dllstnew(*ilst));
			//	free(*av);
			//	(av)++;
				(ilst)++;
			}
			else
				return (error_code(2));//ft_printf("%s","Error: duplicate");
		//}
		//else
		//	return (error_code(1));//t_printf("%s","Error: not num");

	}
	return (1);
}

int	push(dl_list **src, dl_list **dest)
{
	dl_list *tmp;
	
	if (*(get_size(src)) < 1)
		return (0);
	tmp = *src;
	rm_dllst(src);
	*(get_size(src)) -= 1;
	ft_dllstadd_front(dest,tmp);
	ft_dllstupdate(dest);
	ft_dllstupdate(src);
	return (1);
}

int	rotate(dl_list **lst, int dir)
{
	dl_list *head;
	if (*(get_size(lst)) < 2)
		return (0);
	if (dir > 0)
	{
		head  = (*(get_head(lst)));
		//(*(get_tail(lst)))->idx = 0;
		*(get_tail(lst)) = head;//*(get_head(lst)) 
		*(get_head(lst)) = head->next;//*(get_head(lst)) 
	}
	else if(dir < 0)
	{
		head  = (*(get_tail(lst)));
		//(*(get_head(lst)))->idx = 0;
		*(get_head(lst)) = (*(get_tail(lst)));//head;//*(get_head(lst)) 
		*(get_tail(lst)) = head->prev;//*(get_head(lst)) 
	}
	//ft_dllstupdate(lst);
	*lst = *(get_head(lst));
	return (1);
}

int	swap(dl_list **lst)
{
	dl_list *two;
	dl_list *three;
	
	if (*(get_size(lst)) == 2)
		return (rotate(lst, 1));
	if (*(get_size(lst)) < 2)
		return (0);
	two = *lst;
	rm_dllst(lst);
	three = ((*get_head(lst))->next);
	//three->idx = 1;
	three->prev = two;
	two->next = three;
	two->prev = *(get_head(lst));
	//two->idx = -1;
	//two->prev->idx = 0;
	((*get_head(lst))->next) = two;
	ft_dllstupdate(lst);
	if ((*lst)->idx == -1)
	{
		(*lst)->idx = 0;
		(*lst)->next->idx = -1;
	}
	return (1);
}
/*/
 * int	main(int ac, char **av)
{
	dl_list	*a[2];
	dl_list	*b[2];
	int 	*ilst;

	if (ac <= 3)
		return (0);
	init_lst(a);
	init_lst(b);
	ilst = (int *)(malloc(sizeof(int ) * ac ));
	
	fill_stack(a, av, ilst, ac);
	
	print_list(a, 1);
        ft_dllstadd_front(a,  ft_dllstnew(6));
        ft_dllstadd_front(a,  ft_dllstnew(7));
        ft_dllstadd_front(a,  ft_dllstnew(8));
	print_list(a, 1);
	swap(a);
	print_list(a, 1);
	rotate(a, 1);
	rotate(a, 1);
	swap(a);
	rotate(a, 1);
	rotate(a, 1);
	swap(a);

	rotate(a, -1);
	print_list(a, 1);

	push(a,b); 
	push(a,b); 
	push(a,b); 
	push(b,a); 
	push(a,b); 
//	print_list(b, 1);
//	print_list(a, 1);
	//print_list(b, 1);
	ft_dealloc(a);
	ft_dealloc(b);
	free(ilst);
        return 1;
}
/*/
