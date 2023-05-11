/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:23:17 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/04 17:14:05 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long long int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}

// int	main(int argc, char *argv[])
// {
// 	(void) argc;
// 	printf("ft_atoi: %d\n", ft_atoi(argv[1]));
// 	printf("atoi: %d\n", atoi(argv[1]));
// 	return (0);
// }
