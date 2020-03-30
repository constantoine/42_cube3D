/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:14:32 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 16:32:19 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "stddef.h"
# include "colors.h"
# include "cube3D.h"
# include <mlx.h>
# include <stdbool.h>

typedef struct	s_rect
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	heigth;
}				t_rect;

void	put_rect(t_game *game, t_rect *rect, t_color color);
t_rect	new_rect(int x, int y, int width, int heigth);
bool	is_inside(int x, int y, t_rect *rect);
bool	is_inside_rectangle(int x, int y, t_rect *rect);

#endif
