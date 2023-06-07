/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:11:35 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/11 15:13:28 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_is_special(int n)
{
	char	*str;

	str = NULL;
	if (n == 0)
	{
		str = ft_strdup("0");
		if (!str)
			return (NULL);
	}
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (!str)
			return (NULL);
	}
	return (str);
}

static char	*ft_is_positif(int n, char *str, int i)
{
	while (i >= 0)
	{
		if (n >= 10)
		{
			str[i] = (n % 10) + 48;
			n /= 10;
		}
		else if (n < 10 && n >= 0)
			str[i] = n + 48;
		i--;
	}
	return (str);
}

static char	*ft_is_negatif(int n, char *str, int i)
{
	while (i > 0)
	{
		if (n >= 10)
		{
			str[i] = (n % 10) + 48;
			n /= 10;
		}
		else if (n < 10 && n >= 0)
			str[i] = n + 48;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_len(n);
	if (n == 0 || n == -2147483648)
	{
		str = ft_is_special(n);
		return (str);
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		str = ft_is_negatif(-n, str, i);
	}
	else
		str = ft_is_positif(n, str, i);
	return (str);
}

//Fonction qui transforme un int en char *