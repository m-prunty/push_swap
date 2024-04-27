/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:26:39 by mprunty           #+#    #+#             */
/*   Updated: 2024/04/16 19:26:34 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

#ifndef STRUCT_DL_LIST
# define STRUCT_DL_LIST
typedef struct dl_list
{
        struct dl_list	*next;
        struct dl_list	*prev;
        int		i;
        int		idx;
}       dl_list;

#ifndef STRUCT_DL_LIST
# define STRUCT_DL_LIST

typedef struct dl_head
{
        struct dl_list	*next;
        struct dl_list	*prev;
        int		i;
        int		idx;

#endif
#endif


dl_list *ft_dllstnew(int i);
dl_list *ft_dllstlast(dl_list *lst);
void	ft_dllstupdate(dl_list **lst);
void    ft_dllstadd_back(dl_list **lst, dl_list *new);
void    ft_dllstadd_front(dl_list **lst, dl_list *new);
void	print_list(dl_list **lst, int dir);
void	init_lst(dl_list **lst);
#endif
