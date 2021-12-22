/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:11:40 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 13:11:58 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	set_color(int height)
{
	int	new_color;

	height *= 5;
	if (height <= -511)
		new_color = 0x0000FF;
	else if (height <= -256)
		new_color = 0x0000FF + get_g((height + 511) << 8);
	else if (height < 0)
		new_color = 0x00FFFF + get_r((height + 255) << 16);
	else if (height <= 255)
		new_color = 0xFFFF00 + get_b(get_opposite(height));
	else if (height < 510)
		new_color = 0xFF0000 + get_g(get_opposite(height - 255) << 8);
	else
		new_color = 0xFF0000;
	return (new_color);
}

static int	render_line_high(t_img *img, t_point *p0, t_point *p1)
{
	t_line	use;

	use.mod = 0;
	use.dy = p1->y - p0->y;
	use.dx = p1->x - p0->x;
	use.xi = 1;
	if (use.dx < 0)
	{
		use.xi = -1;
		use.dx = -use.dx;
	}
	use.d = (2 * use.dx) - use.dy;
	while (p0->y < p1->y)
	{
		img_pixel_put(img, p0->x, p0->y, set_color(p0->height));
		if (use.d > 0)
		{
			p0->x += use.xi;
			use.d -= (2 * use.dy);
		}
		use.d += (2 * use.dx);
		use.mod = (p1->height - p0->height + use.mod) % (p1->y - p0->y);
		p0->height += (p1->height - p0->height + use.mod) / (p1->y - (p0->y++));
	}
	return (0);
}

static int	render_line_low(t_img *img, t_point *p0, t_point *p1)
{
	t_line	use;

	use.mod = 0;
	use.dx = p1->x - p0->x;
	use.dy = p1->y - p0->y;
	use.yi = 1;
	if (use.dy < 0)
	{
		use.yi = -1;
		use.dy = -use.dy;
	}
	use.d = (2 * use.dy) - use.dx;
	while (p0->x < p1->x)
	{
		img_pixel_put(img, p0->x, p0->y, set_color(p0->height));
		if (use.d > 0)
		{
			p0->y += use.yi;
			use.d -= (2 * use.dx);
		}
		use.d += (2 * use.dy);
		use.mod = (p1->height - p0->height + use.mod) % (p1->x - p0->x);
		p0->height += (p1->height - p0->height + use.mod) / (p1->x - (p0->x++));
	}
	return (0);
}

int	render_line(t_img *img, t_point p0, t_point p1)
{
	img_pixel_put(img, p0.x, p0.y, set_color(p0.height));
	img_pixel_put(img, p1.x, p1.y, set_color(p1.height));
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			render_line_low(img, &p1, &p0);
		else
			render_line_low(img, &p0, &p1);
	}
	else
	{
		if (p0.y > p1.y)
			render_line_high(img, &p1, &p0);
		else
			render_line_high(img, &p0, &p1);
	}
	return (0);
}
