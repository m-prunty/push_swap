/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:56 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/28 03:19:08 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* get_tail:
 * 	 Returns the tail of lst, a pointer stored at lst[1].prev */
t_dll	**get_tail(t_dll **lst)
{
	return (&lst[1]->prev);
}

/* get_head:
 * 	 Returns the head of list a pointer stored at lst[1].next */
t_dll	**get_head(t_dll **lst)
{
	return (&lst[1]->next);
}

/* get_size:
 * 	 Returns the size of lst i.e number of nodes.
 *  an integer stored at lst[1].i */
int	*get_size(t_dll **lst)
{
	return (&lst[1]->i);
}


/*  reset_head:
 *      attachs a new head to the head pointer at lst 1 next
 */
void	reset_head(t_dll **lst, t_dll *head)
{
	*(get_head(lst)) = head;
	*(get_tail(lst)) = head->prev;
	ft_dllstupdate(lst);
	return ;
}

void	ft_dealloc(t_dll **lst)
{
	t_dll	*tmp;
	int		i;

	i = *(get_size(lst));
	if (!i)
		free(*lst);
	while (i--)
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
 *      allocates memory for new structure comprised of three t_dll.
 *      t_dll at idx 0 behaves like normal double-linked, i.e;
 *          lst->next/previous are respective nodes in the list.
 *          lst->i = node value int.
 *          lst->idx = index int.
 *
 *      t_dll at idx 1 stores pointers to:
 *          lst->next/previous = pointers to head/tail
 *          lst->i = size
 * 
 *      t_dll at idx 2 stores pointers to:
 *          lst->next/previous = pointers to cheapest this/other
 *          lst->i =  cheappest value
 *          lst->idx = cheapest idx
 */
void	init_lst(t_dll **lst)
{
	lst[0] = ft_dllstnew(0);
	lst[1] = ft_dllstnew(0);
	lst[2] = ft_dllstnew(0);
	return ;
}

/*/
  int main()
  {

  t_dll *lst[2];
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
