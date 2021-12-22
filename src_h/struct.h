/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:14:27 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/17 14:54:54 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_line
{
	int	d;
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	mod;
}		t_line;

typedef struct s_point
{
	int	x;
	int	y;
	int	height;
}		t_point;

typedef struct s_field
{
	int		row;
	int		col;
	int		flag;
	t_point	**point;
}			t_field;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_field	*field;
}			t_data;

#endif