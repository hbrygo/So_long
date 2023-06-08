/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:30:13 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/08 11:10:03 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_verif_wrong_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C' || str[i] == '1' || str[i] == '0' || str[i] == 'E'
			|| str[i] == 'P' || str[i] == 'M' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

static void	ft_pars(int fd, t_window *image, t_struct *data)
{
	char	*final;
	char	*temp;
	int		i;

	i = 0;
	final = NULL;
	temp = get_next_line(fd);
	if (!temp)
		ft_exit(image);
	final = ft_strjoin(final, temp);
	data->y = ft_strlen(temp);
	while (temp != 0)
	{
		i++;
		if (ft_verif_wrong_char(temp) == 0)
			ft_error(image);
		free(temp);
		temp = get_next_line(fd);
		final = ft_strjoin(final, temp);
	}
	data->tab = ft_split(final, '\n');
	free(final);
	if (!data->tab)
		ft_exit(image);
	data->x = i;
}

void	*ft_map_to_tab(char *map, t_struct *data, t_window *image)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(image);
	ft_pars(fd, image, data);
	close(fd);
	if (ft_check(data) == 0)
		return (ft_error(image));
	return (data);
}
