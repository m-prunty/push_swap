#ifndef STRUCT_T_LIST
#define STRUCT_T_LIST
typedef struct s_list
{
    struct s_list   *next;
    char            *str;
    int             s_len;
    int             nl;
}   t_list;

#endif
