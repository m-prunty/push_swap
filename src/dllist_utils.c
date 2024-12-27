/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:56 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/27 01:46:05 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* get_tail:
 * 	 Returns the tail of lst, a pointer stored at lst[1].prev */
dl_list	**get_tail(dl_list **lst)
{
	return (&lst[1]->prev);
}

/* get_head:
 * 	 Returns the head of list a pointer stored at lst[1].next */
dl_list	**get_head(dl_list **lst)
{
	return (&lst[1]->next);
}

/* get_size:
 * 	 Returns the size of lst i.e number of nodes. 
 *  an integer stored at lst[1].i */
int	*get_size(dl_list **lst)
{
	return (&lst[1]->i);
}

/* get_cheapest:
 * 	 Returns the  a pointer to the info on cheapest nodes.
 * 	 a pointer stored at lst[2]
 *          lst->next/previous = pointers to cheapest this/other
 *          lst->i =  cheappest idx b 
 *          lst->idx = cheapest idx a
 * 	 */
dl_list	**get_cheapest(dl_list **lst)
{
	return (&lst[2]);
}

int	ft_abs(int i)
{
	//ft_printf("%i %i \n", i, -i);
	if (i >= 0)
		return (i);
	else 
		return (-i);
}

int	calc_cheapest(dl_list **anode, dl_list **bnode){
	int cost;

	cost = (ft_abs((*anode)->i) + ft_abs((*bnode)->i)); 
	return (cost) ;
}

/* get_cheapest_cost:
 * 	 Returns the cheapest move cost found so far,absolute sum of;
 * 	 lst[2].i - bindex and lst[2].idx - aindex */
int	get_cheapest_cost(dl_list **lst)
{
	int cost;

	cost = (ft_abs((lst[2])->idx) + ft_abs((lst[2])->i)); 
	//ft_printf("%i \n",cost) ;
	return (cost) ;
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
	i = *(get_size(lst)  );
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
 *          lst->i = size
 *  
 *      dl_list at idx 2 stores pointers to:
 *          lst->next/previous = pointers to cheapest this/other
 *          lst->i =  cheappest value
 *          lst->idx = cheapest idx
 */
void	init_lst(dl_list **lst)
{
	lst[0] = ft_dllstnew(0);
	lst[1] = ft_dllstnew(0);
	lst[2] = ft_dllstnew(0);
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
