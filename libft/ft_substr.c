/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:12:39 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/05 16:07:29 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	while (start < ft_strlen(s) && (s_len < len && s[start + s_len]))
		s_len++;
	str = malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && s[i + start])
		{
			str[i] = s[i + start];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
