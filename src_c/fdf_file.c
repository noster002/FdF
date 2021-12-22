/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:13:34 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/19 23:44:26 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*fdf_file(char *file)
{
	int	chr;

	chr = 0;
	if (ft_strlen(file) < 5)
		return (0);
	while (file[chr + 4] != 0)
		chr++;
	if (file[chr] == '.' && \
		file[chr + 1] == 'f' && \
		file[chr + 2] == 'd' && \
		file[chr + 3] == 'f')
		return (file);
	return (0);
}
