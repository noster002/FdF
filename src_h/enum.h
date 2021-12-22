/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:16:05 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/15 16:15:19 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_frame
{
	win_width = 960,
	win_height = 960,
	img_width = 960,
	img_height = 960
}	t_frame;

typedef enum e_bool
{
	true = 1,
	false = 0
}	t_bool;

typedef enum e_error
{
	mlx_error = 1,
	file_error = 2
}	t_error;

typedef enum e_keysym
{
	escape = 0xff1b
}	t_keysym;

typedef enum e_event
{
	keypress = 2,
	keypressmask = (1L<<0)
}	t_event;

#endif