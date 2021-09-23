/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:46:26 by kricky            #+#    #+#             */
/*   Updated: 2021/09/21 10:10:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

static int	ft_issign(int c)
{
	return ((char)c == '-' || (char)c == '+');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_iswhitespace(int c)
{
	return ((char)c == '\t' || (char)c == '\v' || (char)c == '\f'
		|| (char)c == '\r' || (char)c == '\n' || (char)c == ' ');
}

static	int	ft_checkoverflow(int res, int term, int sign)
{
	long long int	result;

	result = res;
	result = (result * 10) + term;
	result = result * sign;
	if (result > +2147483647)
		return (-1);
	else if (result < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] != '\0' && ft_iswhitespace(str[i]))
		i++;
	if (str[i] != '\0' && ft_issign(str[i]))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (ft_checkoverflow(res, (str[i] - '0'), sign) != 1)
			return (ft_checkoverflow(res, (str[i] - '0'), sign));
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
