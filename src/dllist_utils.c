/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:56 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 09:45:33 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_dealloc(t_dll **lst)
{
	t_dll	*tmp;
	int	 	i;

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
//calc_chunkrange(t_dll **lst);

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
