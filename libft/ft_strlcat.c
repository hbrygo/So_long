/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:12:21 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/04 19:22:49 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	j = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (!dst && size == 0)
		return (lensrc);
	if (size < lendst)
		return (size + lensrc);
	while (dst[i] && i < size)
		i++;
	while (src[j] && ((i + j) < (size - 1) && size != 0))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (lendst + lensrc);
}
