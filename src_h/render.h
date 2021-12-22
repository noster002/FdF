/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:22:00 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/15 14:54:22 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "struct.h"

int	render(t_data *data);
int	img_pixel_put(t_img *img, int x, int y, int color);
int	render_background(t_img *img, int color);
int	render_line(t_img *img, t_point p0, t_point p1);
int	render_frame(t_img *img, t_field *field);

#endif