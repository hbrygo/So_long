/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:41:47 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/08 11:09:40 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(t_window *image)
{
	ft_printf("Error\n");
	ft_exit(image);
	return (0);
}

static void	ft_destroy_image(t_window *image)
{
	if (image->player_left)
		mlx_destroy_image(image->mlx, image->player_left);
	if (image->player_left_2)
		mlx_destroy_image(image->mlx, image->player_left_2);
	if (image->wall)
		mlx_destroy_image(image->mlx, image->wall);
	if (image->exit_close)
		mlx_destroy_image(image->mlx, image->exit_close);
	if (image->exit_open)
		mlx_destroy_image(image->mlx, image->exit_open);
	if (image->green)
		mlx_destroy_image(image->mlx, image->green);
	if (image->white)
		mlx_destroy_image(image->mlx, image->white);
	if (image->item)
		mlx_destroy_image(image->mlx, image->item);
	if (image->enemy)
		mlx_destroy_image(image->mlx, image->enemy);
}

int	ft_exit(t_window *image)
{
	int	i;

	i = -1;
	while (image->struct_1->tab && ++i < image->struct_1->x)
		free(image->struct_1->tab[i]);
	free(image->struct_1->tab);
	if (image->player_back)
		mlx_destroy_image(image->mlx, image->player_back);
	if (image->player_back_2)
		mlx_destroy_image(image->mlx, image->player_back_2);
	if (image->player_front)
		mlx_destroy_image(image->mlx, image->player_front);
	if (image->player_front_2)
		mlx_destroy_image(image->mlx, image->player_front_2);
	if (image->player_right)
		mlx_destroy_image(image->mlx, image->player_right);
	if (image->player_right_2)
		mlx_destroy_image(image->mlx, image->player_right_2);
	if (image->window)
		mlx_destroy_window(image->mlx, image->window);
	ft_destroy_image(image);
	exit(0);
}
