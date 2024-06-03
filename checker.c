#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"
#include <string.h>

//#define RAND_MAX	INT_MAX

static unsigned long int next = 1;

int ft_rand(void)  /* RAND_MAX assumed to be 32767. */
{
    next = next * 1103515245 + 12345;
    return (unsigned)(next/65536) % RAND_MAX;// 32768;
}

void ft_srand(unsigned seed)
{
    next = seed;
}

int *ft_prand(int count, int maxbit)//, int **intv)
{
	int i=0;
    int elementlen;// = rand() %13;
    int len;
	char *binstr;
	int *intv;

    srand(maxbit % count);
	intv = (int *)malloc(count * sizeof(int));
	while(count--)
	{	
		len = 0;
		elementlen = rand() % maxbit;
		binstr = (char *)malloc(elementlen + 1 * sizeof(char));
		if (rand() % 2)
        	binstr[len++] = '-';
		while (len < elementlen)
           	binstr[len++] = (char)(rand() % 2 + 48);
        binstr[len] = '\0';
        intv[i] = ft_atoi_base(binstr, 2);
		i++;	
		free(binstr);
    }
	return intv;
}
char*	ft_itoa_arr(int *intv, int count)
{
	int i;
	char *charv;
	char *tmpstr;

	charv = (char *)(malloc(count*11 * sizeof(char )));
	i = 0;
	while(count--)
	{
		tmpstr = ft_itoa(*intv);
		i += ft_strlcpy(charv+i, tmpstr , ft_strlen(tmpstr) + 1); 
		charv[i++] = ' ';	
		intv++;
		free(tmpstr);
	}
	charv[i-1] = '\0';
	return (charv) ;
}

int main(int ac, int *av)
{
	int		**intv;
	char	**charv;
	char	*tmpstr;
	int		i;
	int		count;
	char	*file;
	int		fd;

	file = "tmpfile";
	count = 20;
	i = 0;
	ft_srand(1);
	intv = (int **)malloc(count + 1 * sizeof(int *));
	*intv = ft_prand(count, 31);//, intv);
	while(i < count)
		ft_printf("%i ", (*intv)[i++]);
	ft_printf("\n");
	charv = (char **)(malloc(count * 11 * sizeof(char*)));
	tmpstr = ft_itoa_arr(*intv, count);
	
	*charv = ft_strjoin("./push_swap ", ft_strjoin(tmpstr, " > file;"));
	system(*charv );
	i = 0;
	fd = open("file", O_RDONLY);
	while (get_next_line(fd))
		i++;
	ft_printf("\n n lines = %i \n", i);
	free(tmpstr);	
	free(*intv);
	free(intv);
	free(*charv);
	free(charv);
}
