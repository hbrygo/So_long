/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:12:09 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/10 15:55:07 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != charset)
			i++;
	}
	return (count);
}

static char	*ft_word(char *str, char charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	len_word = i;
	i = 0;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_put_word(char *str, char c, int i, char **string)
{
	string[i] = ft_word(str, c);
	if (!string[i])
	{
		while (i >= 0)
		{
			free(string[i]);
			i--;
		}
		return (NULL);
	}
	return (string[i]);
}

static int	ft_set_word(char **strings, char *str, int i, char c)
{
	strings[i] = ft_put_word(str, c, i, strings);
	if (!strings[i])
	{
		free(strings);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (NULL);
	while (*str != '\0')
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			if (ft_set_word(strings, str, i, c) == 0)
				return (NULL);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	strings[i] = 0;
	return (strings);
}
