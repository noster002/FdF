/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:39:53 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 13:12:14 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	render_frame(t_img *img, t_field *field)
{
	int	i;
	int	j;

	j = 0;
	while (j < field->row)
	{
		i = 0;
		while (i < field->col)
		{
			if (i != (field->col - 1))
				render_line(img, field->point[j][i], field->point[j][i + 1]);
			if (j != (field->row - 1))
				render_line(img, field->point[j][i], field->point[j + 1][i]);
			++i;
		}
		++j;
	}
	return (0);
}
