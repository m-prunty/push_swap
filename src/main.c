/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:09:34 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/05 10:42:06 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_min_rec(t_dll *lst, int min, int len)
{
	if (!len)
		return (min);
	if (lst->i < min)
		min = lst->i;
	if (len--)
		min = (get_min_rec(lst->next, min, len));
	return (min);
}

int	get_min(t_dll **lst)
{
	t_dll	*tmp;
	int		min;
	int		i;

	tmp = *lst;
	min = INT_MAX;
	i = *get_size(lst);
	return (get_min_rec(tmp, min, i));
}

int	get_max_rec(t_dll *lst, int max, int len)
{
	if (!len)
		return (max);
	if (lst->i > max)
		max = lst->i;
	if (len--)
		max = (get_max_rec(lst->next, max, len));
	return (max);
}

int	get_max(t_dll **lst)
{
	t_dll	*tmp;
	int		i;

	tmp = *lst;
	i = *get_size(lst);
	return (get_max_rec(tmp, INT_MIN, i));
}

int	dllstget_dist(t_dll **lst, t_dll *node, int dir)
{
	int	i;

	i = 0;
	if (dir < 0)
	{
		while (node != *get_tail(lst))
		{
			i++;
			*node = *node->next;
		}
	}
	else if (dir > 0)
	{
		while (node != *get_head(lst))
		{
			i++;
			*node = *node->next;
		}
	}
	return (i);
}

int	clear_all(t_dll **a, t_dll **b, int *intv)
{
	ft_dealloc(a);
	ft_dealloc(b);
	free(intv);
	return (1);
}

void	ft_strlcpy_mult(char **dest, char **src, int count, size_t n)
{
	char	*tmp;

	while (count--)
	{
		tmp = (char *)(malloc(13 * sizeof(char )));
		ft_strlcpy((tmp), (*src), n);
		*dest = tmp;
		dest++;
		src++;
	}
	return ;
}

int	ft_isnum(char *str, int symok)
{
	int	i;

	i = 1;
	if (!(*str))
		return (1);
	if (symok && (*str == '-' || *str == '+' || *str == ' '))
		str++;
	i = ft_isdigit((int)*(str));
	if (i)
		return (ft_isnum(++(str), 0) * i);
	return (0);
}

void	fill_intv(int ac, int i, char **charv, long *intv)
{
	if (!i || !*charv)
		return (free(*charv));
	*intv = (ft_atol(*charv));
	if (i-- && ++(charv) && ++(intv))
		return (fill_intv(ac, i, charv, intv));
	return (free(*(--(charv))));
}

char	**check_args(int *ac, char **av)
{
	char	**charv;
	int		i;

	i = 0;
	if (*ac == 2)
	{
		charv = ft_split(av[1], ' ');
		while (charv[i++])
			;
		*ac = i ;
	}
	else
	{
		charv = (char **)(malloc((*ac) * sizeof(char *)));
		ft_strlcpy_mult(charv, ++av, (*ac) - 1, 13);
	}
	i = 0;
	while (*(charv + i) && ft_isnum(*(charv + i), 1) && i++ < *ac - 1)
		;
	if (i < *ac - 1)
		return (NULL);
	return (charv);
}

void	rotate_ordered(t_dll **lst)
{
	t_dll	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp->i != get_min(lst))
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *get_head(lst);
	if (i > *get_size(lst) / 2)
	{
		while (tmp->i != get_min(lst) && rra(lst))
			tmp = tmp->prev;
	}
	else
	{
		while (tmp->i != get_min(lst) && ra(lst))
			tmp = tmp->next;
	}
}
/*
 * solve_ltthree:
 *	  checks if first or 2nd is max and if so ensures
 *	  its last using ra/rra or:
 *	  checks if first is bigger and if so swaps.
 */
int	solve_ltthree(t_dll **a)
{
	if ((*get_head(a))->i == get_max(a))
		ra(a);
	else if (((*a)->next)->i == get_max(a))
		rra(a);
	if ((*get_head(a))->i > ((*a)->next)->i)
		sa(a);
	return (0);
}
t_dll	*rotate_help(t_dll **lst, int n)
{
	if (n > 0)
		while (n--)
			ra(lst);
	else
		while (n++)
			rra(lst);
	return (*lst);
}

int	solve_ltfive(t_dll **a, t_dll **b)
{
	t_dll	*min;
	int		i;

	if (ft_dllstordered(a))
		rotate_ordered(a);
	if (ft_dllstsorted(a))
		return (1);
	i = 0;
	while (i++ <= *get_size(a) - 3)
	{
		min = ft_dllstfind(a, get_min(a), *get_size(a));
		get_cost(a);
		if ((*get_head(a))->i != min->i)
			*a = rotate_help(a, min->idx.x);
		pb(a, b);
	}
	(solve_ltthree(a));
	while (*get_size(b))
		pa(a, b);
	return (ft_dllstsorted(a));
}

t_dll	*dllstgoto(t_dll **lst, int pos)
{
	t_dll	*node;

	node = *lst;
	while (pos--)
		node = (node)->next;
	return (node);
}

int	main(int ac, char **av)
{
	t_dll	*a[3];
	t_dll	*b[3];
	long	*intv;
	char	**charv;

	charv = check_args(&ac, av);
	intv = (long *)malloc((ac - 1) * sizeof(long));
	if (!intv || !charv || !*charv)
		return (error_code(1));
	fill_intv(ac - 1, ac - 1, charv, intv);
	free(charv);
	init_lst(a);
	init_lst(b);
	if (fill_stack(a, intv, ac))
	{
		if (ft_dllstsorted(a))
			return (clear_all(a, b, (int *)intv));
		else if (ac - 1 <= 3)
			solve_ltthree(a);
		else if (ac - 1 <= 5)
			solve_ltfive(a, b);
		else
			turk_sort(a, b);
	}
	return (clear_all(a, b, (int *)intv));
}
