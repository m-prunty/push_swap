#include "libft.h"
#include "push_swap.h"

void fill_stack(dl_list **lst, char **av, int *ilst, int ac) 
{
	ac--;
	(av)++;
	while(ac--)
	{
		*ilst = ft_atoi(*av);
		ft_dllstadd_back(lst,  ft_dllstnew(*ilst));
		(av)++;
		(ilst)++;
	}
}

dl_list **get_tail(dl_list **lst)
{
	return (&lst[1]->prev);
}

dl_list **get_head(dl_list **lst)
{
	return (&lst[1]->next);
}

int	*get_size(dl_list **lst)
{
	return (&lst[1]->idx);
}
void	rm_dllst(dl_list **lst)
{
	if (lst[0]->idx < 0)
		*(get_tail(lst)) = (lst[0]->prev);
	else if (lst[0]->idx > 0)
		*(get_head(lst)) = (lst[0]->next);
	ft_dllstupdate(lst);
	*lst = lst[1]->next;
	return;
}

void	ft_dealloc(dl_list **lst)
{
	dl_list  *tmp;
	int i;
	i = ((lst[1]->idx) );
	if (!i)
       		free(*lst);
	while(i--)
	{
		tmp = (*lst)->next;
        	free(*lst);
        	*lst = tmp;
	}
	free(lst[1]);
	return ;

}
void	push(dl_list **src, dl_list **dest)
{
	dl_list *tmp;

	tmp = *src;
	rm_dllst(src);
	*(get_size(src)) -= 1;
	ft_dllstadd_front(dest,tmp);
	return;
}

void	swap(dl_list **lst)
{
	dl_list *two;
	dl_list *three;
	
	two = *lst;
	rm_dllst(lst);
	three = ((*get_head(lst))->next);
	three->prev = two;
	two->next = three;
	two->prev = *(get_head(lst));
	((*get_head(lst))->next) = two;	
}

void	rotate(dl_list **lst, int dir)
{
	dl_list *head;
	if (dir > 0)
	{
		head  = (*(get_head(lst)));
		(*(get_tail(lst)))->idx = 0;
		*(get_tail(lst)) = head;//*(get_head(lst)) 
		*(get_head(lst)) = head->next;//*(get_head(lst)) 
	}
	else if(dir < 0)
	{
		head  = (*(get_tail(lst)));
		(*(get_head(lst)))->idx = 0;
		*(get_head(lst)) = (*(get_tail(lst)));//head;//*(get_head(lst)) 
		*(get_tail(lst)) = head->next;//*(get_head(lst)) 
	}
	ft_dllstupdate(lst);
	*lst = *(get_head(lst));
}
int	main(int ac, char **av)
{
	dl_list	*a[2];
	dl_list	*b[2];
	int 	*ilst;

	if (ac <= 3)
		return 0;
	init_lst(a);
	init_lst(b);
	ilst = (int *)(malloc(sizeof(int ) * ac ));
	
	fill_stack(a, av, ilst, ac);
	
/*/
	print_list(a, 1);
        ft_dllstadd_front(a,  ft_dllstnew(6));
        ft_dllstadd_front(a,  ft_dllstnew(7));
        ft_dllstadd_front(a,  ft_dllstnew(8));
/*/
	print_list(a, 1);
	swap(a);
	print_list(a, 1);
	rotate(a, 1);
	print_list(a, 1);

	push(a,b); 
	push(a,b); 
	push(a,b); 
	push(b,a); 
	push(a,b); 
	print_list(b, 1);
	print_list(a, 1);
	//print_list(b, 1);
	ft_dealloc(a);
	ft_dealloc(b);
	free(ilst);
        return 1;
}

