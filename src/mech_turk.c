#include "libft.h"
#include "push_swap.h"
#include <stdio.h>


dl_list **get_median(dl_list **lst)
{
    int median ; 
    dl_list  **node;

    node = get_head(lst);
    median = *get_size(lst) / 2 ;
    median += *get_size(lst) % 2 ;
    //ft_printf("%i", median);
    *lst = *node;
    //ft_dllstupdate(lst);
    return (dllstgoto(node, median-1)) ;
    //return (0);
}
int split_stack(dl_list **a, dl_list **b)
{
    while (*get_size(a) > 3)
        pb(a,b);
    return (0);
}

int cost_analysis(dl_list **lst)
{
    get_median(lst);


    return (0);
}

int turk_sort(dl_list **a, dl_list **b)
{
    ft_dllstrd(a, 1);
    split_stack(a, b);
    ft_dllstrd(a, 1);
    ft_dllstrd(b, 1);
    cost_analysis(a);
    cost_analysis(b);
    ft_dllstrd(a, 1);
    ft_dllstrd(b, 1);
    ft_printf("\n\n");
    //(void)(a);
    //(void)(b);
    return 0;
}
