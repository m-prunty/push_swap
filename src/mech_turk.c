#include "libft.h"
#include "push_swap.h"
#include <stdio.h>


int get_median_idx(dl_list **lst)
{
    int median ; 

    median = *get_size(lst) / 2 ;
    median += *get_size(lst) % 2 ;
    return  (median - 1) ;
    //return (0);
}
int split_stack(dl_list **a, dl_list **b)
{
    while (*get_size(a) > 3)
        pb(a,b);
    solve_ltthree(a);
    return (0);
}

int get_cost(dl_list **lst)
{
    int median; 
    int i;
    dl_list  *node_H;
    //dl_list  **node_T;

    i = -1;
    //node_H = get_head(lst);
    //node_T = &(*lst)->prev;
    median = get_median_idx(lst); 
    //ft_printf("%i", median);
    while (++i <= median)
    {
        node_H = *get_head(lst);
        //ft_printf("%i",i);
        (*dllstgoto(&node_H, i))->idx = i;
        node_H = *get_head(lst);
        (*dllstgoto(&node_H, median + i))->idx = -1 * (1+ median - i);

        //(*dllstgoto(lst, i+(median-1)))->idx = *get_size(lst)+1- (median + i);
    }
   /* 
        ((*node_H)->idx) =  i; 
        *node_H = (*node_H)->next;
        ((*node_T)->idx) =  i; 
        *node_T = (*node_T)->prev;
    }
*/
    //ft_dllstupdate(lst);
    //*lst = *get_head(lst);
    
 
    return (0);
}

int cost_analysis(dl_list **a, dl_list **b)
{
    dl_list *anode;
    dl_list *bnode;
    int i;
    int j;
    
    i = *get_size(b) ;
    
    get_cost(a);
    get_cost(b);
    bnode = *get_head(b) ;
    while (i--)
    {
        anode = *get_head(a);
        j  = *get_size(a)  ;
        if ((bnode->i) > (anode->i))
            while (--j && ((bnode->i) > (anode)->next->i))
                anode = anode->next;
        else 
            while (--j && ((bnode->i) < (anode->i)))
                anode = anode->prev;
        ft_printf("%i %i %i\n", bnode->idx + anode->idx, bnode->idx , anode->idx);
        bnode = bnode->next;
    }
    return (0);
};

int turk_sort(dl_list **a, dl_list **b)
{
  //  int i;
    ft_dllstrd(a, 1);
    split_stack(a, b);
    /*/
    while(*get_size(b))
    {
    /*/
        cost_analysis(a,b);
        ft_dllstrd(a, 1);
        ft_dllstrd(b, 1);
        ft_printf("\n\n");
        //(void)(a);
        //(void)(b);
    /*/
    }
    /*/
    return 0;
    
}
