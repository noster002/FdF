/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:15 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/17 14:50:41 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
	return (0);
}

int	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < img_height)
	{
		j = 0;
		while (j < img_width)
			img_pixel_put(img, j++, i, color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, 0x0);
	render_frame(&data->img, data->field);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img);
	return (0);
}
