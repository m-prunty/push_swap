/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:09:34 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/10 12:58:54 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
void print_list(t_dll **lst)
{
	//t_dll *start = *lst;
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_dllstrd(lst, 1);
	/*	if (!lst)
		{
		printf("List is empty.\n");
		return;
		}
		do
		{
		printf("[%d] ", (*lst)->ele);
	 *lst = (*lst)->next;
	 } while (*lst != start);
	 printf("\n");
	 */
}

/*
   void test_add_back(t_dll **list)
   {
   printf("Testing ft_dllstadd_back\n");
   ft_dllstadd_back(list, ft_dllstnew(10, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_back(list, ft_dllstnew(20, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_back(list, ft_dllstnew(30, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dealloc(list);
   }

   void test_add_front(t_dll **list)
   {
   printf("Testing ft_dllstadd_front\n");
   ft_dllstadd_front(list, ft_dllstnew(10, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_front(list, ft_dllstnew(20, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_front(list, ft_dllstnew(30, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dealloc(list);
   }

   void test_mixed_add(t_dll **list)
   {
   printf("Testing mixed ft_dllstadd_front and ft_dllstadd_back\n");
   ft_dllstadd_back(list, ft_dllstnew(10, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_front(list, ft_dllstnew(5, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_back(list, ft_dllstnew(15, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dllstadd_front(list, ft_dllstnew(1, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(list);
   ft_dealloc(list);
   }

   void test_push(t_dll **a, t_dll **b)
   {
   printf("Testing push\n");
   ft_dllstadd_back(a, ft_dllstnew(10, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   ft_dllstadd_back(a, ft_dllstnew(20, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   ft_dllstadd_back(a, ft_dllstnew(30, (t_loc){0}, (t_idx){0}, (t_idx){0}));
   print_list(a);
   print_list(b);
   pb(a, b);
   print_list(a);
   print_list(b);
   pb(a, b);
   print_list(a);
   print_list(b);
   pa(a, b);
   print_list(a);
   print_list(b);
   pa(a, b);
   print_list(a);
   print_list(b);
   ft_dealloc(a);
   ft_dealloc(b);
   }
   int main()
   {
   t_dll	*a[3];
   t_dll	*b[3];

   init_lst(a);
   test_add_back(a);
   init_lst(b);
   test_add_front(b);
init_lst(a);
test_mixed_add(a);
init_lst(a);
init_lst(b);
test_push(a, b);
return 0;
}
	*/
t_dll	*dllstget_dist(t_dll **lst, int idx)
{
	size_t	size;

	get_pos(lst);
	size = *get_size(lst);
	while ((*lst)->idx.y != idx && size--)
		*lst = (*lst)->next;
	return (*lst);
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
	t_dll	***ab;
	t_dll	*a[3];
	t_dll	*b[3];
	long	*intv;
	char	**charv;

	ft_bzero(a, sizeof(*a) * 3);
	ft_bzero(b, sizeof(*b) * 3);
	ab = (t_dll ***)malloc(sizeof(t_dll **) * 2);
	charv = check_args(&ac, av);
	intv = (long *)malloc((ac - 1) * sizeof(long));
	if (!intv || !charv || !*charv)
		return (error_code(1));
	fill_intv(ac - 1, ac - 1, charv, intv);
	free(charv);
	init_lst(a);
	init_lst(b);
	ab[0] = a;
	ab[1] = b;
	init_chunks(a, b);
	if (fill_stack(a, intv, ac))
	{
		//if (ft_dllstsorted(a))
		//	return (clear_all(a, b, (int *)intv));
		//else
		sort(ab);
	}
	ft_dllstrd(a, 1);
	ft_dllstrd(b, 1);
	return (clear_all(a, b, (int *)intv));
}

