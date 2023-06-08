/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:39:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/08 11:04:36 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_start(char *s)
{
	char	*dest;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len])
		len++;
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_end(char *s1)
{
	int		i;
	int		j;
	char	*ret;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
		return (ft_free(s1));
	i++;
	ret = malloc(sizeof(char) * (ft_strlen(s1 + i) + 1));
	if (!ret)
		return (ft_free(s1));
	while (s1[i + j])
	{
		ret[j] = s1[i + j];
		j++;
	}
	ret[j] = '\0';
	free(s1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stack = 0;
	int			i;
	char		*ret;
	char		buff[BUFFER_SIZE + 1];

	while (ft_is_new_line(stack) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (ft_set_stack(&stack));
		if (i == 0)
			break ;
		buff[i] = '\0';
		stack = ft_join(stack, &ret, buff);
		if (!stack)
			return (NULL);
	}
	ret = ft_start(stack);
	if (!ret)
		return (ft_set_stack(&stack));
	stack = ft_end(stack);
	if (stack && stack[0] == '\0')
		ft_set_stack(&stack);
	return (ret);
}
