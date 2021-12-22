/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:08:05 by nosterme          #+#    #+#             */
/*   Updated: 2021/11/29 14:07:44 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	add_shade(double distance, int color)
{
	return (color - (color * distance));
}

int	get_opposite(int color)
{
	return (~color);
}
