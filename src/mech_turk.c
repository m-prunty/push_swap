/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:36:24 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/05 03:00:15 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


int	in_range(t_dll *lst, t_idx idx)
{
	//if (idx
	(void)lst;
	(void)idx;
	return (0);
}

t_loc perform_action(t_dll **lst);


/*
   int find_target_position(int value, t_dll *stack_a, int size)
   {
   t_dll	*current;
   int		min_pos;
   int		min_val;
   int		target_pos;
   int		i;

   i = 0;
   current = stack_a;
   min_pos = 0;
   min_val = INT_MAX;
   target_pos = -1;
   for (int i = 0; i < size; i++)
   {
   if (current->ele < min_val)
   {
   min_val = current->ele;
   min_pos = i;
   }
   if (current->ele > value && (target_pos == -1 || current->ele < stack_a->ele))
   {
   target_pos = i;
   }
   current = current->next;
   }
   if (target_pos == -1)
   target_pos = min_pos;
   return target_pos;
   }
   */

/*
   int	cost_analysis(t_dll **a, t_dll **b)
   {
   t_dll	*anode;
   t_dll	*bnode;
   int		i;
   int		cost;
   int		found;

   i = *get_size(b);
   get_pos(a);
   get_pos(b);
   bnode = *get_head(b);
   init_storage(b, bnode, NULL, ft_idxnew(get_max(a),get_min(a)));
   (*get_storage(b))->ele = INT_MAX;
   found = 0;
   while (i-- )
   {
   anode = (*get_head(a));
   while (!found && anode != *get_tail(a))
   {
   if ((bnode->ele > anode->prev->ele && anode->prev == get_max_node(a, *get_size(a)))
   ||	(bnode->ele < anode->ele && bnode->ele > anode->prev->ele)
   ||	(bnode->ele < anode->ele && anode == get_min_node(a))
   )
   {
   found = 1;
   }
   else
   anode = anode->next;
   }
   if (!found)
   anode = *get_head(a); // Default to head if no better position found
   cost = ft_abs(anode->idx.x) + ft_abs(bnode->idx.x);
   if (cost < (*get_storage(b))->ele)
   {
   init_storage(b, bnode, anode, ft_idxnew(bnode->ele, anode->ele));
   (*get_storage(b))->ele = cost;
   }
   printf("bnode: %d, anode: %d, cost: %d\n", bnode->ele, anode->ele, cost);
   bnode = bnode->next;
   }
   return (0);
   }*/

/*int cost_analysis(t_dll **a, t_dll **b)
  {
  t_dll	*anode;
  t_dll	*bnode;
  int cost_b; = i;
  int cost_a; = target_pos;
  int		i;

  i = 0;
  if (!a || !*a || !b || !*b)
  return (0);
  get_pos(a);
  get_pos(b);
  bnode = *get_head(b);
  init_storage(b, bnode, NULL, ft_idxnew(0, 0));
  while (i < *get_size(b)) 
  {
  int target_pos = find_target_position(bnode->ele, *a, *get_size(a));
  anode = get_node_at_position(*a, target_pos);
  cost_b = i;
  if (cost_b > *get_size(b) / 2)
  cost_b = -(*get_size(b) - cost_b);
  cost_a = target_pos;
  if (cost_a > *get_size(a) / 2)
  cost_a = -(*get_size(a) - cost_a);
  int total_cost = ft_abs(cost_a) + ft_abs(cost_b);
  if ( ft_abs(cost_a) + ft_abs(cost_b) < (*get_storage(b))->ele)
  {
  init_storage(b, bnode, anode, ft_idxnew(bnode->ele,anode->ele)); t
  (*get_storage(b))->ele = total_cost;
  }
  bnode = bnode->next;
  i++;
  }
  return 0;
  }*/

/* for cheapest on b:
 *          lst->next/previous = pointers to cheapest this/other
 *          lst->ele =  cheapest cost
 *          lst->idx = t_idx{cheapest idx b, cheapest idx a}
 * for  cheapest on a:
 * 		lst->next/previous = get_max(a)/get_min(a)
 * 		lst->idx = t_idx{get_max(a), get_min(a)}
 * for split_stack on a:
 * 		lst->next/previous = NULL
 * 		lst->idx = t_idx{min, size - (size/3)}
 * 
 *         */

/*
   void init_storage(t_dll **lst, t_dll *next, t_dll *prev, t_idx idx)
   {
   (*get_storage(lst))->idx = idx;
   (*get_storage(lst))->ele = INT_MAX;
   (*get_storage(lst))->next = next;
   (*get_storage(lst))->prev = prev;
   }

   int move_nodes(t_dll **a, t_dll **b)
   {
   t_dll	**cheapest;
   int		aidx;
   int		bidx;
   int		moves;

   if (!a || !*a || !b || !*b)
   return (0);
   moves = 0;
   cheapest = get_storage(b);
   if (!*cheapest)
   return (moves);
   aidx = (*cheapest)->prev->idx.x;
   bidx = (*cheapest)->next->idx.x;
   while (aidx && bidx)
   {
   if (aidx > 0 && bidx > 0)
   {
   moves += rr(a, b);
   aidx--;
   bidx--;
   }
   else if (aidx < 0 && bidx < 0)
   {
   moves += rrr(a, b);
   aidx++;
   bidx++;
   }
   }
   while (aidx || bidx)
   {
   if (aidx > 0 && ra(a))
   {
   moves++;
   aidx--;
   }
   else if (aidx < 0 && rra(a))
   {
   moves++;
   aidx++;
   }
   if (bidx > 0 && rb(b))
   {
   moves++;
   bidx--;
   }
   else if (bidx < 0 && rrb(b))
   {
   moves++;
   bidx++;
   }
   }
   if (*a == (*cheapest)->prev && *b == (*cheapest)->next)
   {
   moves += pa(a, b);
   }
   return (moves);
   }
   int bubble_sort(t_dll **lst)//, dl_list **b)
   {
   t_dll	*tail;
int		size;

tail = *get_tail(lst);
size = *get_size(lst);
while((*lst) != tail && size--)
{
	if ((*lst)->ele > ((*lst)->next)->ele)
		sa(lst);
	ra(lst);
}
ra(lst);
if (!ft_dllstordered(lst))
{
	bubble_sort(lst);
}
return (1);
}
int bubble_sort_rev(t_dll **lst)//, dl_list **b)
{
	t_dll	*tail;
	int		size;

	tail = *get_tail(lst);
	size = *get_size(lst);
	while((*lst) != tail && size--)
	{
		if ((*lst)->ele < ((*lst)->next)->ele)
			sa(lst);
		ra(lst);
	}
	ra(lst);
	if (!ft_dllstordered(lst))
	{
		bubble_sort_rev(lst);
	}
	return (1);
}
*/
