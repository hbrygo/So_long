/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:23:24 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/07 10:53:17 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_struct
{
	int		x;
	int		y;
	int		collectible;
	int		enemy;
	int		exit;
	int		error;
	int		count;
	int		height;
	int		map_height;
	int		width;
	int		map_width;
	int		input;
	char	**tab;
}				t_struct;

typedef struct s_window
{
	void		*green;
	void		*white;
	void		*wall;
	void		*player_front;
	void		*player_front_2;
	void		*player_back;
	void		*player_back_2;
	void		*player_right;
	void		*player_right_2;
	void		*player_left;
	void		*player_left_2;
	void		*enemy;
	void		*item;
	void		*exit_open;
	void		*exit_close;
	void		*window;
	void		*mlx;
	t_struct	*struct_1;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
}				t_window;

int		key_press(int keycode, t_window *image);
void	ft_set_image(t_window *image, t_struct *data);
int		ft_strlen(char *str);
void	*ft_error(t_window *image);
void	*ft_map_to_tab(char *map, t_struct *data, t_window *image);
int		ft_check(t_struct *data);
void	set_spawn(t_window *image, t_struct *data);
int		ft_exit(t_window *image);
char	*ft_itoa(int n);

#endif