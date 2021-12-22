/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:16:13 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/19 23:39:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (file_error);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (mlx_error);
	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "fdf");
	if (data.win_ptr == NULL)
		return (free_main1(&data));
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, img_width, img_height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
									&data.img.line_len, &data.img.endian);
	data.field = frame(fdf_file(argv[1]));
	if (data.field == NULL)
		return (free_main2(&data));
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, keypress, keypressmask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_field(data.field);
	return (0);
}
