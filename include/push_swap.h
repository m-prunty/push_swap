/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:26:39 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/29 11:24:23 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/include/libft.h"

# define MIN_INT -2147483648 //1<<((sizeof(int)*8)-1)
# define MAX_INT 2147483647   //-((1<<((sizeof(int)*8)-1)) +1)
/*
# ifndef STRUCT_T_IDX
#  define STRUCT_T_IDX

typedef struct s_idx
{
	int		i;
	int		j;
}	t_idx;
# endif
*/
# ifndef STRUCT_T_DLL
#  define STRUCT_T_DLL

typedef struct s_dll
{
	struct s_dll	*next;
	struct s_dll	*prev;
	int				i;
	int			idx;
}	t_dll;
# endif

t_dll	*ft_dllstnew(int i);
void	ft_dllstrd(t_dll **lst, int dir);
void	ft_dllstadd_back(t_dll **lst, t_dll *new_link);
void	ft_dllstadd_front(t_dll **lst, t_dll *new_link);
t_dll	*ft_dllstlast(t_dll *lst);

void	ft_dllstupdate(t_dll **lst);
void	init_lst(t_dll **lst);
void	ft_dealloc(t_dll **lst);
void	ft_dllstrm(t_dll **lst);
void	reset_head(t_dll **lst, t_dll *head);

t_dll	**get_head(t_dll **lst);
t_dll	**get_tail(t_dll **lst);
int		*get_size(t_dll **lst);
t_dll	**get_cheapest_pair(t_dll **lst);
t_dll	**get_storage(t_dll **lst);

t_dll	*dllstgoto(t_dll **lst, int pos);
t_dll	*ft_dllstfind(t_dll **lst, int i, int len);

int		ft_dllstsorted(t_dll **lst);
int		ft_dllstordered(t_dll **lst);

int		get_cheapest_cost(t_dll **lst);
int		calc_cheapest(t_dll **anode, t_dll **bnode);
int		get_median_idx(t_dll **lst);
int		get_max(t_dll **lst);
int		get_min(t_dll **lst);

int		split_stack(t_dll **a, t_dll **b);
int		get_cost(t_dll **lst);
void	init_cheapest(t_dll **lst);
int		cost_analysis(t_dll **a, t_dll **b);
int		move_nodes(t_dll **a, t_dll **b);

int		turk_sort(t_dll **a, t_dll **b);
int		ft_abs(int i);
int		ft_isnum(char *str, int sym);
int		error_code(int i);
int		fill_stack(t_dll **stack, long *ilst, int ac);

int		merge_sort(t_dll **a, t_dll **b);
int		bubble_sort(t_dll **lst);
int		solve_ltthree(t_dll **lst);
int		turk_sort(t_dll **a, t_dll **b);

int		push(t_dll **src, t_dll **dest);
int		rotate(t_dll **lst, int dir);
int		swap(t_dll **lst);

int		sa(t_dll **a);
int		sb(t_dll **b);
int		ss(t_dll **a, t_dll **b);
int		pa(t_dll **a, t_dll **b);
int		pb(t_dll **a, t_dll **b);
int		ra(t_dll **a);
int		rb(t_dll **b);
int		rr(t_dll **a, t_dll **b);
int		rra(t_dll **a);
int		rrb(t_dll **b);
int		rrr(t_dll **a, t_dll **b);


#endif

