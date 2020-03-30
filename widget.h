/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:22:05 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 17:18:44 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_H
# define WIDGET_H

# include <stddef.h>
# include "rect.h"

typedef struct	s_widget
{
	t_rect	rect;
	void	(*action)(void *params);
}				t_widget;

typedef struct s_tree
{
	t_rect			rect;
    t_widget		button;
    struct s_tree	*top_left;
    struct s_tree	*top_right;
    struct s_tree	*bottom_left;
    struct s_tree	*bottom_right;
} t_tree;

t_widget    *tree_walk(int x, int y, t_tree *tree);

#endif
