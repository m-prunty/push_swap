#include "libft.h"
#include "push_swap.h"
#include <stdio.h>


int get_median_idx(dl_list **lst)
{
    int median ; 

    median = *get_size(lst) / 2 ;
    median += *get_size(lst) % 2 ;
    return  (median ) ;
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
    int len;
    int i;
    //dl_list  *node_H;
    //dl_list  *node_T;

    i = 0;
    //node_H = get_head(lst);
    //node_T = &(*lst)->prev;
    median = get_median_idx(lst); 
    len = *get_size(lst);
    //ft_printf("%i", median);
    if( len <= 1){
        (*get_head(lst))->idx = 0;
        return (0);
    } 
    while (i <= median-1)
    {
        //node_H = *get_head(lst);
        //ft_printf("%i",i);
        //if (i > median)
        (dllstgoto(get_head(lst), i))->idx = i;
        (dllstgoto(get_head(lst), median + i))->idx = ((median+i) -len ) ;
        /*/
          if (! (len % 2))
          (dllstgoto(get_head(lst), median + i))->idx = -((median-1) -i)  ;
          else
          (dllstgoto(get_head(lst), median + i))->idx = -((median-1) -i)  ;
        /*/
        //else
        //(dllstgoto(get_head(lst),  median + i))->idx = -1 * ( 1+ median - i);
        //node_H = *get_head(lst);
        i++;
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
int is_head_srt(dl_list *node)
{
    return (node->i == get_min(&node) && node->prev-> i == get_max(&node));
}

int cost_analysis(dl_list **a, dl_list **b)
{
    dl_list *anode;
    dl_list *bnode;
    int i;
    int j;
    int cost;
    dl_list **cheapest;

    i = *get_size(b) ;

    get_cost(a);
    get_cost(b);
    bnode = *get_head(b) ;
    cheapest = get_cheapest(b);
    (*cheapest)->next = NULL; 
    (*cheapest)->prev = NULL; 
    (*cheapest)->idx = MAX_INT; 
    (*cheapest)->i = MAX_INT; 
    while (i--)
    {
        anode = *get_head(a);
        j  = get_median_idx(a);//*get_size(a)  ;
        while (!(bnode->i < anode->i && bnode->i > anode->prev->i) && j-- )
        {
            if (bnode->i >  anode->i && !is_head_srt(anode) && bnode->i)
                anode = (anode)->next;
            if (bnode->i <  anode->i)
                anode = (anode)->prev;
        }
        cost =  (ft_abs((anode)->idx) + ft_abs((bnode)->idx));
        if (!(*cheapest)->prev || cost < get_cheapest_cost(b))
        {
            (*cheapest)->idx = (bnode)->idx;
            (*cheapest)->i = (anode)->idx;
            (*cheapest)->next = bnode;
            (*cheapest)->prev = anode;
        }
        bnode = (bnode)->next;
    }
    return (0);
};


int move_nodes(dl_list **a, dl_list **b)
{
    dl_list **cheapest;
    int aidx;
    int bidx;

    cheapest = get_cheapest(b);
    aidx = (*cheapest)->i;
    bidx = (*cheapest)->idx;
    while (aidx && bidx){
        if (aidx > 0 && bidx > 0){
            rr(a,b);
            aidx--;
            bidx--;
        }
        else if (aidx < 0 && bidx < 0)
        {
            rrr(a,b);
            aidx++;
            bidx++;
        }
    }
    while  (aidx || bidx){
        if (aidx > 0){
            ra(a);
            aidx--;
        }
        else if (aidx < 0){
            rra(a);
            aidx++;
        }
        if (bidx > 0){
            rb(b);
            bidx--;
        }
        else if (bidx < 0){
            rrb(b);
            bidx++;
        }
    }
    if (*a == (*cheapest)->prev && *b == (*cheapest)->next)
    {
        pa(a,b);
    }
    //ft_dllstupdate(a);
    //ft_dllstupdate(b);
    return (0);
}

int turk_sort(dl_list **a, dl_list **b)
{
    //  int i;
    //ft_dllstrd(a, 1);
    split_stack(a, b);
    while(*get_size(b))
    {

        cost_analysis(a,b);
        //  ft_dllstrd(a, 1);
        //  ft_dllstrd(b, 1);
        move_nodes(a,b);
        ft_dllstupdate(a);
        ft_dllstupdate(b);
        //ft_printf("\n\n");
        //(void)(a);
        //(void)(b);
    }
    if (!(ft_dllstordered(a)))
        return (error_code(6));
    if ((*get_head(a))->i != get_min(a))
    {
        get_cost(a);
        (*get_cheapest(a))->i = ft_dllstfind(a, get_min(a), *get_size(a))->idx;
        while (--(*get_cheapest(a))->i > 0)
            ra(a);
        while (++(*get_cheapest(a))->i < 0)
            rra(a);
    }
    if (!(ft_dllstsorted(a)))
        return (error_code(6));
    return 1;

}
