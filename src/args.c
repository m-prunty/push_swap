/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:40:47 by mprunty           #+#    #+#             */
/*   Updated: 2025/02/03 06:48:20 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_strlcpy_mult(char **dest, char **src, int count, size_t n)
{
	char	*tmp;

	while (count--)
	{
		tmp = (char *)(malloc(13 * sizeof(char )));
		ft_strlcpy((tmp), (*src), n);
		*dest = tmp;
		dest++;
		src++;
	}
	return ;
}

void	fill_intv(int ac, int i, char **charv, long *intv)
{
	if (!i || !*charv)
		return (free(*charv));
	*intv = (ft_atol(*charv));
	if (i-- && ++(charv) && ++(intv))
		return (fill_intv(ac, i, charv, intv));
	return (free(*(--(charv))));
}

char	**check_args(int *ac, char **av)
{
	char	**charv;
	int		i;

	i = 0;
	if (*ac == 2)
	{
		charv = ft_split(av[1], ' ');
		while (charv[i++])
			;
		*ac = i ;
	}
	else
	{
		charv = (char **)(malloc((*ac) * sizeof(char *)));
		ft_strlcpy_mult(charv, ++av, (*ac) - 1, 13);
	}
	i = 0;
	while (*(charv + i) && ft_isnumi(*(charv + i)) && i++ < *ac - 1)
		;
	if (i < *ac - 1)
		return (NULL);
	return (charv);
}
