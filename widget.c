/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:25:52 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 20:33:27 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "widget.h"
#include "libft.h"
#include "rect.h"

t_widget	*widget_create(t_rect *rect, char *name, void (*action)(void *params))
{
	t_widget	*widget;

	if (!(widget = malloc(sizeof(t_widget))))
		return (NULL);
	widget->name = name;
	widget->rect = rect;
	widget->action = action;
	return (widget);
}

t_tree	*tree_create(t_rect *rect)
{
	t_tree		*tree;

	if (!(tree = malloc(sizeof(t_tree))))
		return (NULL);
	ft_bzero(tree, sizeof(t_tree));
	tree->rect = rect;
	return (tree);
}

t_widget	*tree_walk(int x, int y, t_tree *tree)
{
	t_widget	*widget;

	if (!tree)
		return (NULL);
	if (!is_inside(x, y, tree->rect))
		return (NULL);
	if ((widget = tree_walk(x, y, tree->top_left)))
		return (widget);
	if ((widget = tree_walk(x, y, tree->top_right)))
		return (widget);
	if ((widget = tree_walk(x, y, tree->bottom_left)))
		return (widget);
	if ((widget = tree_walk(x, y, tree->bottom_right)))
		return (widget);
	return (tree->button);
}

bool	tree_fill_children(t_tree *tree)
{
	size_t	center_x;
	size_t	center_y;
	t_rect	*child[4];

	center_x = (tree->rect->width + tree->rect->x - tree->rect->x) / 2;
	center_y = (tree->rect->heigth + tree->rect->y - tree->rect->y) / 2;
	child[0] = new_rect(tree->rect->x, tree->rect->y,
		center_x - tree->rect->x, center_y - tree->rect->y);
	child[1] = new_rect(center_x, tree->rect->y,
		tree->rect->x + tree->rect->width - center_x, center_y - tree->rect->y);
	child[2] = new_rect(tree->rect->x, center_y, center_x - tree->rect->x,
		tree->rect->y + tree->rect->heigth - center_y);
	child[3] = new_rect(center_x, center_y, tree->rect->x + tree->rect->width
		- center_x, tree->rect->y + tree->rect->heigth - center_y);
	if (!tree->top_left && !(tree->top_left = tree_create(child[0])))
			return (NULL);
	if (!tree->top_right && !(tree->top_right = tree_create(child[1])))
			return (NULL);
	if (!tree->bottom_left && !(tree->bottom_left = tree_create(child[2])))
			return (NULL);
	if (!tree->bottom_right && !(tree->bottom_right = tree_create(child[3])))
			return (NULL);
	return (TRUE);
}

bool	tree_add(t_tree *tree, t_widget *widget)
{
	if (widget->rect->heigth <= 4 ||
		(is_inside(tree->rect->x, tree->rect->y, widget->rect) &&
		is_inside(tree->rect->x + tree->rect->width,
		tree->rect->y + tree->rect->heigth, widget->rect)))
	{
		tree->button = widget;
		return (true);
	}
	if (!tree_fill_children(tree))
		return (NULL);
	if (is_rect_inside(tree->top_left->rect, widget->rect))
		if (!tree_add(tree->top_left, widget))
			return (false);
	if (is_rect_inside(tree->top_right->rect, widget->rect))
		if (!tree_add(tree->top_right, widget))
			return (false);
	if (is_rect_inside(tree->bottom_left->rect, widget->rect))
		if (!tree_add(tree->bottom_left, widget))
			return (false);
	if (is_rect_inside(tree->bottom_right->rect, widget->rect))
		if (!tree_add(tree->bottom_right, widget))
			return (false);
	return (true);
}

