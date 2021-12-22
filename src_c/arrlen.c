/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:17:34 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 12:23:39 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_arrdoublelen(char ***arr)
{
	int	count;

	count = 0;
	while (arr[count] != 0)
		count++;
	return (count);
}

int	ft_arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != 0)
		count++;
	return (count);
}
