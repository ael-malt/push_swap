/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:43 by ael-malt          #+#    #+#             */
/*   Updated: 2023/04/28 12:22:24 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	(void) argc;
// 	printf("ft_isalpha: %d\n", ft_isalpha(argv[1][0]));
// 	printf("isalpha: %d\n", isalpha(argv[1][0]));
// 	return 0;
// }
