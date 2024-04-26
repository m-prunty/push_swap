#include "libft.h"
#include "push_swap.h"

int	algo(dl_list **a, dl_list **b)
{
	ft_printf("%i",get_max(a));
	print_list(a, 1);
	bubble_sort(a);
	b++;
	/*/
	pb(a,b);
	print_list(a, 1);
	print_list(b, 1);
	pb(a,b);
	print_list(a, 1);
	print_list(b, 1);
	pb(a,b);
	print_list(a, 1);
	print_list(b, 1);
	rb(b);
	print_list(a, 1);
	print_list(b, 1);
	pa(a,b);
	print_list(a, 1);
	print_list(b, 1);
	/*/
	return 1;
}

int bubble_sort(dl_list **lst)//, dl_list **b)
{
//	int max = get_max(lst);
//	int min = get_min(lst);
	int i = *get_size(lst);
	while(i--)
	{
		
		if ((*lst)->i > ((*lst)->next)->i)
			sa(lst);
		print_list(lst, 1);
		ra(lst);
		print_list(lst, 1);
	}
	if (!ft_dllstsorted(lst))
	{
		bubble_sort(lst);
	}
	
	print_list(lst, 1);
	return (1);
}

int get_min(dl_list **lst)
{
	int min;
	int i;

	min = 0;
	i = *get_size(lst);
	while (i--)
	{
		if (min > (*lst)->i)
			min = (*lst)->i;
		*lst = (*lst)->next;
	}
	return (min);
}
int get_max(dl_list **lst)
{
	int max;
	int i;

	max = 0;
	i = *get_size(lst);
	while (i--)
	{
		if (max < (*lst)->i)
			max = (*lst)->i;
		*lst = (*lst)->next;
	}
	return (max);
}

dl_list	**dllstgoto(dl_list **lst, int pos);
int	dllstget_dist(dl_list **lst, dl_list *node, int dir)
{
	int i;

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
int clear_all(dl_list **a, dl_list **b, int *ilst)
{
	ft_dealloc(a);
	ft_dealloc(b);
	free(ilst);
	return (1);
}

int	main(int ac, char **av)
{
    dl_list *a[2];
    dl_list *b[2];
    int     *ilst;

    if (ac <= 3)
        return (0);
    init_lst(a);
    init_lst(b);
    ilst = (int *)(malloc(sizeof(int ) * ac ));
	if (fill_stack(a, av, ilst, ac))
	{
		if (ft_dllstsorted(a))
			return (clear_all(a,b,ilst));
		else
			algo(a,b);
	}
	return (clear_all(a,b,ilst));
}
