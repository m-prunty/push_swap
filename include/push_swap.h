/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:26:39 by mprunty           #+#    #+#             */
/*   Updated: 2024/04/26 21:26:28 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

#ifndef STRUCT_DL_LIST
# define STRUCT_DL_LIST
/*  dl_list struct:
 *      struct dl_list	*next;
 *      struct dl_list	*prev;
 *      int		i;
 *      int		idx;
 * */
typedef struct dl_list
{
        struct dl_list	*next;
        struct dl_list	*prev;
        int		i;
        int		idx;
    }       dl_list;
#endif
/*/
#ifndef STRUCT_DL_LIST
# define STRUCT_DL_LIST

typedef struct dl_head
{
        struct dl_list	*next;
        struct dl_list	*prev;
        int		i;
        int		idx;

#endif
/*/
#define MIN_INT  1<<((sizeof(int)*8)-1)
#define MAX_INT  -((1<<((sizeof(int)*8)-1)) +1)
dl_list *ft_dllstnew(int i);
dl_list *ft_dllstlast(dl_list *lst);
void	ft_dllstupdate(dl_list **lst);
void    ft_dllstadd_back(dl_list **lst, dl_list *new_link);
void    ft_dllstadd_front(dl_list **lst, dl_list *new_link);
void	ft_dllstrd(dl_list **lst, int dir);
void	init_lst(dl_list **lst);
void    ft_dealloc(dl_list **lst);
void    ft_dllstrm(dl_list **lst);
void    reset_head(dl_list **lst, dl_list *head);
dl_list	**get_head(dl_list **lst);
dl_list	**get_tail(dl_list **lst);
dl_list **get_storage(dl_list **lst);
dl_list **get_cheapest(dl_list **lst);
dl_list	*dllstgoto(dl_list **lst, int pos);
dl_list *ft_dllstfind(dl_list **lst, int i, int len);
int ft_dllstsorted(dl_list **lst);
int ft_dllstordered(dl_list **lst);
int		*get_size(dl_list **lst);
int get_cheapest_cost(dl_list **lst);
int calc_cheapest(dl_list **anode, dl_list **bnode);

int ft_abs(int i);
int ft_isnum(char *str);
int	error_code(int i);
int fill_stack(dl_list **stack, int *ilst, int ac);
int	push(dl_list **src, dl_list **dest);
int	rotate(dl_list **lst, int dir);
int	swap(dl_list **lst);
int get_max(dl_list **lst);
int get_min(dl_list **lst);

int merge_sort(dl_list **a, dl_list **b);
int bubble_sort(dl_list **lst);
int solve_ltthree(dl_list **lst);
int turk_sort(dl_list **a, dl_list **b);
int get_median_idx(dl_list **lst);

int	sa(dl_list **a);
int	sb(dl_list **b);
int	ss(dl_list **a, dl_list **b);
int	pa(dl_list **a, dl_list **b);
int	pb(dl_list **a, dl_list **b);
int	ra(dl_list **a);
int	rb(dl_list **b);
int	rr(dl_list **a, dl_list **b);
int	rra(dl_list **a);
int	rrb(dl_list **b);
int	rrr(dl_list **a, dl_list **b);


#endif
