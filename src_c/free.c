/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:04:37 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 12:24:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_arr(char **arr, int elements)
{
	while (elements)
		free(arr[--elements]);
	free(arr);
}

void	free_arr_double(char ***arr_double, int elements1, int elements2)
{
	while (elements1)
		free_arr(arr_double[--elements1], elements2);
	free(arr_double);
}

void	free_field(t_field *field)
{
	int	i;

	i = 0;
	while (i < field->row)
		free(field->point[i++]);
	free(field->point);
	free(field);
}

int	free_main1(t_data *data)
{
	free(data->mlx_ptr);
	return (mlx_error);
}

int	free_main2(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (file_error);
}
