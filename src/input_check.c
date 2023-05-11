/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:43:06 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/04 16:40:57 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	nbrstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+' && s2[j] != '+')
		i++;
	else if (s2[j] == '+')
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	arg_has_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv && argv[i])
	{
		j = 1;
		while (argv && argv[j])
		{
			if (j != i && nbrstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_check(char **argv)
{
	int	i;
	int	zeros_count;

	i = 0;
	zeros_count = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11 || !arg_is_number(argv[i]))
			return (0);
		zeros_count += arg_is_zero(argv[i]);
		i++;
	}
	if (zeros_count > 1)
		return (0);
	if (arg_has_duplicates(argv))
		return (0);
	return (1);
}
