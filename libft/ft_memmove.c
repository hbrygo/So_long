/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:11:53 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/11 15:12:27 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*str;

	i = -1;
	str = (char *)src;
	dest = dst;
	if (!dest && !src)
		return (NULL);
	if (str > dest)
	{
		while (++i < len)
			dest[i] = str[i];
	}
	else
	{
		while (len-- > 0)
			dest[len] = str[len];
	}
	return (dest);
}

//fonction qui permet de modifier un tableau comme strcpy mais
//avec une source = a la dest en utilisant l'overlap