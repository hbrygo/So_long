/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:30:13 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/07 13:53:13 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(t_window *image)
{
	printf("Error\n");
	ft_exit(image);
	return (0);
}

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

static int	ft_len_line(char *map)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	while (str != 0)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	i++;
	return (i);
}

void	*ft_map_to_tab(char *map, t_struct *data, t_window *image)
{
	int		fd;
	int		i;

	i = 0;
	data->tab = malloc(sizeof(char *) * ft_len_line(map));
	if (!data->tab)
		ft_exit(image);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	data->tab[0] = get_next_line(fd);
	data->y = ft_strlen(data->tab[0]);
	while (data->tab[i] != 0)
	{
		if (ft_verif_wrong_char(data->tab[i]) == 0)
			ft_error(image);
		data->tab[++i] = get_next_line(fd);
	}
	data->x = i;
	close(fd);
	if (ft_check(data) == 0)
		return (ft_error(image));
	return (data);
}

int	ft_exit(t_window *image)
{
	int	i;

	i = -1;
	while (image->struct_1->tab && ++i < image->struct_1->x)
		free(image->struct_1->tab[i]);
	free(image->struct_1->tab);
	mlx_destroy_image(image->mlx, image->player_back);
	mlx_destroy_image(image->mlx, image->player_back_2);
	mlx_destroy_image(image->mlx, image->player_front);
	mlx_destroy_image(image->mlx, image->player_front_2);
	mlx_destroy_image(image->mlx, image->player_right);
	mlx_destroy_image(image->mlx, image->player_right_2);
	mlx_destroy_image(image->mlx, image->player_left);
	mlx_destroy_image(image->mlx, image->player_left_2);
	mlx_destroy_image(image->mlx, image->wall);
	mlx_destroy_image(image->mlx, image->exit_close);
	mlx_destroy_image(image->mlx, image->exit_open);
	mlx_destroy_image(image->mlx, image->green);
	mlx_destroy_image(image->mlx, image->white);
	mlx_destroy_image(image->mlx, image->item);
	mlx_destroy_image(image->mlx, image->enemy);
	if (image->window)
		mlx_destroy_window(image->mlx, image->window);
	exit(0);
}
