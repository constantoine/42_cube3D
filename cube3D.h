/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:16:35 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 15:20:00 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include "colors.h"

typedef struct	s_game
{
	void *mlx_ptr;
	void *mlx_window;
}				t_game;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

void	my_mlx_pixel_put(t_image *img, int x, int y, t_color color);

#endif
