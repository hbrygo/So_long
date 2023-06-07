/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:29:10 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/05 13:34:26 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < len && s1[i])
	{
		if (s1[i] == s2[0] && s1[i])
		{
			j = 0;
			while (s1[i + j] == s2[j] && (s2[j] && i + j < len))
				j++;
			if (j == ft_strlen(s2))
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}
