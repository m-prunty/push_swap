/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:26:39 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/02 13:58:03 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/include/libft.h"

# ifndef STRUCT_TLOC_
#  define STRUCT_T_LOC
typedef enum e_loc
{
	TOP_A = 1,
	BOTTOM_A,   // Rotate to bottom of A
	TOP_B,      // Push to top of B
	BOTTOM_B    // Push to B and rotate to bottom
} t_loc;
# endif

# ifndef STRUCT_T_IDX
#  define STRUCT_T_IDX
typedef struct s_idx
{
	int		x;
	int		y;
}	t_idx;
# endif

# ifndef STRUCT_T_DLL
#  define STRUCT_T_DLL

typedef struct s_dll
{
	struct s_dll	*next;
	struct s_dll	*prev;
	int				ele;
	t_idx			idx;
	t_idx			*range;
	t_loc			loc;
}	t_dll;
# endif

t_dll	*ft_chunk(t_dll **lst, t_loc *loc);

int		turk_sort(t_dll **a, t_dll **b);
t_dll	**get_storage(t_dll **lst);
int		ft_abs(int i);
int		calc_cheapest(t_dll **anode, t_dll **bnode);
void	ft_dllstadd_back(t_dll **lst, t_dll *new_link);
void	ft_dllstadd_front(t_dll **lst, t_dll *new_link);
t_idx	ft_idxnew(int x, int y);
t_dll	*ft_dllstnew(int i, t_loc loc, t_idx idx, t_idx *range);
void	ft_dllstrd(t_dll **lst, int dir);
void	ft_dllstupdate(t_dll **lst);
void	ft_dllstrm(t_dll **lst);
t_dll	**get_head(t_dll **lst);
t_dll	**get_tail(t_dll **lst);
int		*get_size(t_dll **lst);
void	reset_head(t_dll **lst, t_dll *head);
void	ft_dealloc(t_dll **lst);
t_idx	*calc_chunkrange(t_dll **lst);
t_loc	get_destination(t_dll **a, t_loc loc, int min, int mid);
void	set_chunks(t_dll **lst);
t_dll	*get_chunks(t_dll **lst, t_loc loc);
void	init_lst(t_dll **lst);
int		get_min_rec(t_dll *lst, int min, int len);
int		get_min(t_dll **lst);
int		get_max_rec(t_dll *lst, int max, int len);
t_dll	*get_min_node(t_dll **lst);
t_dll	*get_max_node(t_dll **lst);
int		get_max(t_dll **lst);
int		dllstget_dist(t_dll **lst, t_dll *node, int dir);
int		clear_all(t_dll **a, t_dll **b, int *intv);
void	ft_strlcpy_mult(char **dest, char **src, int count, size_t n);
void	fill_intv(int ac, int i, char **charv, long *intv);
int		ft_isnumi_ps(char *str);
char	**check_args(int *ac, char **av);
void	rotate_ordered(t_dll **lst);
int		solve_ltthree(t_dll **a);
t_dll	*rotate_help(t_dll **lst, int n, int lst_loc);
int		solve_ltfive(t_dll **a, t_dll **b);
t_dll	*dllstgoto(t_dll **lst, int pos);
int		main(int ac, char **av);
int		get_fin_idx(t_dll *node);
void	update_idx(t_dll **a);
int		in_range(t_dll *lst, t_idx idx);
int		split_stack(t_dll **a, t_dll **b, int size);
int		get_median_idx(t_dll **lst);
int		get_pos(t_dll **lst);
t_dll	*get_node_at_position(t_dll *stack, int position);
int		cost_analysis(t_dll **a, t_dll **b);
void	init_storage(t_dll **lst, t_dll *next, t_dll *prev, t_idx idx);
int		move_nodes(t_dll **a, t_dll **b);
int		bubble_sort(t_dll **lst);
int		bubble_sort_rev(t_dll **lst);
int		turk_sort(t_dll **a, t_dll **b);
int		ft_dllstsorted_rev(t_dll **lst);
int		ft_dllstordered(t_dll **lst);
t_dll	*ft_dllstfind(t_dll **lst, int i, int len);
int		error_code(int i);
int		final_position(int *sorted, int i, int len);
t_idx	*get_range(t_dll **stack, t_loc loc);
int		fill_stack(t_dll **stack, long *ilst, int ac);
void	qs_swap(int *a, int *b);
int		partition(int arr[], int low, int high);
void	quick_sort(int arr[], int low, int high);
int		*sorted_arr(int *arr, int size);

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
