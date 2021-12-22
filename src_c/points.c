/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:21:09 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 10:27:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_height(t_field *field, char ***elements)
{
	int	y;
	int	x;
	int	element;
	int	dif_height;

	y = 0;
	dif_height = lround((img_height * 0.4) / (field->row + field->col - 2));
	while (y < field->row)
	{
		x = 0;
		while (x < field->col)
		{
			element = ft_atoi(elements[y][x]);
			field->point[y][x].height = element;
			field->point[y][x].y -= lround((element * dif_height) / 6);
			x++;
		}
		y++;
	}
}

static void	set_point(t_field *field, int y, int x)
{
	int	dif_height;
	int	dif_width;

	dif_height = lround((img_height * 0.4) / (field->row + field->col - 2));
	dif_width = lround((img_width * 0.9) / (field->row + field->col - 2));
	if (y == 0 && x == 0)
	{
		field->point[0][0].y = lround(img_height * 0.3);
		field->point[0][0].x = lround(img_width * 0.05) + \
								(field->row - 1) * dif_width;
	}
	else
	{
		field->point[y][x].y = field->point[0][0].y + (y + x) * dif_height;
		field->point[y][x].x = field->point[0][0].x + (x - y) * dif_width;
	}
}

void	set_field(t_field *field)
{
	int	row;
	int	col;

	row = 0;
	field->point = (t_point **)malloc(field->row * sizeof(t_point *));
	while (row < field->row)
	{
		col = 0;
		field->point[row] = (t_point *)malloc(field->col * sizeof(t_point));
		while (col < field->col)
		{
			set_point(field, row, col);
			col++;
		}
		row++;
	}
}
