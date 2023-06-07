/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:29 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/10 15:55:45 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_in_str(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!to_find && str)
		return (0);
	while (i < (int)ft_strlen(to_find))
	{
		if (to_find[i] && to_find[i] == str[0])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strr_in_str(char str, char *to_find)
{
	int	i;

	i = 0;
	if (!to_find)
		return (0);
	while (i < (int)ft_strlen(to_find))
	{
		if (to_find[i] == str)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strldup(const char *s, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	char	*str;

	end = 0;
	str = (char *)s1;
	if (set[0] == '\0' || str[0] == '\0')
		return (ft_strldup(str, ft_strlen(str)));
	if (!s1)
		return (NULL);
	while (str && ft_str_in_str(str, (char *)set) == 1)
		str++;
	if (str[0] == '\0')
		return (ft_strldup(str, 1));
	while (ft_strr_in_str(str[ft_strlen(str) - end - 1], (char *)set) == 1)
		end++;
	end = ft_strlen(str) - end;
	str = (char *)ft_strldup(str, end);
	if (!str)
		return (NULL);
	return (str);
}
