
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>
/*/
char **split(char*)
{

}
*/
int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 
int	ft_atoi_base(const char *nptr, int base)
{
	int	n;
	int	res;
	int	neg;

	n = ft_strlen(nptr)+ 1;
	res = 0;
	neg = 1;
	while (ft_isblank(*nptr))
		nptr ++;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			neg *= -1;
		nptr++;
		n--;
	}
	while (ft_isdigit(*nptr))
	{
		if (ft_isdigit(*nptr))
			res = res * base  + (val(*nptr));
		nptr++;
	}
	return (res * neg);
}
int main () {
	int i;

	i = 100;

	printf("%i", ft_atoi_base(i, 2));

/*/
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char **token;
   
   // get the first token 
   token = strtok(str, s);
   
   // walk through other tokens 
   while( tokeni++ != NULL ) {
      printf( "%s" , token );
    
      //token = strtok(NULL, s);
   }
   
/*/
   return(0);
}

