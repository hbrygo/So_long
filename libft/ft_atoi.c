/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:27:21 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/27 19:06:42 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	result;
	long int	last;
	int			sign;

	result = 0;
	last = 0;
	sign = 1;
	str += skip((char *)str);
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (last > result && sign > 0)
			return (-1);
		else if (last > result && sign < 0)
			return (0);
		str++;
		last = result;
	}
	return (result * sign);
}

//Fonction qui convertit un int en char en faisant - 48
#include <stdio.h>
#include <string.h>

int main(void)
{
	long long i = LONG_MAX;

	printf("%d\n", ft_atoi((const char *)i));
	printf("%d\n", atoi(""));
}