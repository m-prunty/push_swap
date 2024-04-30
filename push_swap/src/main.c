#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
int	algo(dl_list **a, dl_list **b)
{
	//ft_printf("%i",get_max(a));
	//print_list(a, 1);
	bubble_sort(a);
	//merge_sort(a, b);
	//ft_putstr_fd("sa\npb\npb\npb\nsa\npa\npa\npa\n", 1);
	//ft_putendl_fd("rra", 0);
	b++;
	a++;
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

int merge_sort(dl_list **a, dl_list **b)
{
	int max = get_max(a);
	int med = max / 2;
	
	while ((*a)->idx != -1)
	{
		print_list(a,1);
		print_list(b,1);
		if ((*a)->i < med)
		{
			pb(a, b);
		}
		else if ((*a)->i > ((*a)->next)->i)
			sa(a);
		else
			ra(a);
		//if ((*))
		if ((*b)->i > ((*b)->next)->i)
			sb(b);
		if ((*b)->idx != -1)
			rb(b);
	}
	return 1;
}

int	bubble_sort_rev(dl_list **lst)
{
	dl_list **head;
	
	head = lst;
	while ((*head)->prev->idx != -1)
	{
		
		if ((*head)->prev->i > (*head)->i)
			sa(head);
	
	//	print_list(lst, 1);
		rra(head);
//		print_list(head, 1);
	}
	rra(head);
	return (1);
}

int bubble_sort(dl_list **lst)//, dl_list **b)
{
	//int i;
	//dl_list **head;
	
	//head = lst;
	//i = *get_size(lst) -1;
	while((*lst)->idx != -1)
	{
		
		if ((*lst)->i > ((*lst)->next)->i)
			sa(lst);
	//	print_list(lst, 1);
		//if (ft_dllstsorted(lst))
		//{
//		ft_putendl_fd("rra", 1);
		//	return (1);
		//	}
		ra(lst);
//		print_list(lst, 1);
	}
//	if (!ft_dllstsorted(lst))
//		bubble_sort_rev(lst);
	ra(lst);
	if (!ft_dllstsorted(lst))
	{
		//ft_printf("\n%s\n","next_bubb");
		bubble_sort(lst);
	}
	
//	print_list(lst, 1);
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
	//dl_list	*head;
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
int clear_all(dl_list **a, dl_list **b, int **ilst)
{
	ft_dealloc(a);
	ft_dealloc(b);
	while (*ilst)
		free(ilst++);
	return (1);
}
/*/
#include <unistd.h>
#include <fcntl.h>
static void init_redirect(int *file_desc, int *copy_out)
{
  *file_desc = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0666);
  *copy_out = dup(fileno(stdout));
  dup2(*file_desc, fileno(stdout));
}
static void reset_output(int *copy_out)
{
 dup2(*copy_out, fileno(stdout));
 close(*copy_out);
}

/*/
void ft_memcpy_mult(char **dest, char **src, int count, size_t n)
{
	
	while(count--)
		ft_memcpy((*dest)++, (*src)++,n);
	return;
}


int ft_isnum(char *str)
{
    int i;

    if (!(*str))
        return 1;
    i = ft_isdigit((int)*str);
    if (i) 
        return(ft_isnum((++(str))) * i);
    return (0);
}

int	**check_args(int *ac, char **av)
{
	char	**charv;
	int		**intv;
	int		i;
	
	i = 0;
	if (*ac == 2)
	{
		charv = ft_split(av[1], ' ');
		while (charv[i++]);
		*ac = i + 1;
	}
	else
	{
    	charv = (char **)(malloc(sizeof(char *) * *(ac) ));
		ft_memcpy_mult(charv, ++av, *ac, 13);
	}
	intv =(int **)(malloc(sizeof(int *)* *ac));
	while(i--)
	{
		if (ft_isnum(charv[i]))
			*intv[*ac - i - 1] =  ft_atoi(charv[i]);//intv[i]//, sizeof(int));
		else
			error_code(0);
	}
	return (intv);
}

int	main(int ac, char **av)
{
    dl_list *a[3];
    dl_list *b[3];
    int     **ilst;
/*/
	int		file_desc;
	int		copy_out;
	
/*/
//	init_redirect(&file_desc, &copy_out);
    if (ac < 2)
		return (0);
    ilst = check_args(&ac, av);
	init_lst(a);
    init_lst(b);
	if (fill_stack(a, ilst, ac))
	{
		if (ft_dllstsorted(a))
			return (clear_all(a,b,ilst));
		else
			algo(a,b);
	}
	free(*av);
//	reset_output(&copy_out);
	return (clear_all(a,b,ilst));
}
