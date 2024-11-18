/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:56 by mprunty           #+#    #+#             */
/*   Updated: 2024/06/30 20:02:14 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

/* get_tail:
 * 	 Returns the tail of lst, a pointer stored at lst[1].prev */
dl_list **get_tail(dl_list **lst)
{
	return (&lst[1]->prev);
}

/* get_head:
 * 	 Returns the head of list a pointer stored at lst[1].next */
dl_list **get_head(dl_list **lst)
{
	return (&lst[1]->next);
}

/* get_storage:
 * 	 Returns the storage element of lst, a pointer stored at lst[2] */
dl_list **get_storage(dl_list **lst)
{
	return (&lst[2]);
}

/* get_size:
 * 	 Returns the size of lst i.e number of nodes, 
 *  an integer stored at lst[1].idx */
int *get_size(dl_list **lst)
{
	return (&lst[1]->idx);
}

/*  reset_head:
 *      attachs a new head to the head pointer at lst 1 next 
 */
void    reset_head(dl_list **lst, dl_list *head)
{
	*(get_head(lst)) = head; 
	*(get_tail(lst)) = head->prev; 
	ft_dllstupdate(lst);
	return ;
}

void	ft_dealloc(dl_list **lst)
{
	dl_list  *tmp;
	int i;
	i = ((lst[1]->idx) );
	if (!i)
		free(*lst);
	while(i--)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(lst[1]);
	free(lst[2]);
	return ;

}

/*  init_lst:
 *      allocates memory for new structure comprised of three dl_list.
 *      dl_list at idx 0 behaves like normal double-linked, i.e;
 *          lst->next/previous are respective nodes in the list.
 *          lst->i = node value int.
 *          lst->idx = index int.
 *
 *      dl_list at idx 1 stores pointers to:
 *          lst->next/previous = pointers to head/tail
 *          lst->idx = size
 */
void	init_lst(dl_list **lst)
{
	lst[0] = ft_dllstnew(0);
	lst[1] = ft_dllstnew(0);
	lst[2] = ft_dllstnew(0);
	lst[1]->idx = 0;
	//lst[1]->idx = 0;
	return ;
}
/*/
int main()
{
	
	dl_list *lst[2];
	init_lst(lst);
	//ft_dllstadd_back(lst,  ft_dllstnew("1"));
	//ft_dllstadd_back(lst,  ft_dllstnew("2"));
	ft_dllstadd_front(lst,  ft_dllstnew("3"));
	//ft_dllstadd_back(lst,  ft_dllstnew("4"));
	//ft_dllstadd_back(lst,  ft_dllstnew("5"));
	ft_dllstadd_front(lst,  ft_dllstnew("6"));
	ft_dllstadd_front(lst,  ft_dllstnew("7"));
	ft_dllstadd_front(lst,  ft_dllstnew("8"));
	ft_dllstrd(lst, 1);	
	ft_dllstrd(lst, -1);	
	//ft_printf("%i", ft_isascii('a'));
	//ft_printf("%s", lst->i);
	return 0;
}

/*/
