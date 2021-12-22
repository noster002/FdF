/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:17:24 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 13:12:46 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	*free_frame1(t_field *field)
{
	free(field);
	field = 0;
	return (field);
}

static void	*free_frame2(t_field *field, char **lines)
{
	free_arr(lines, field->row);
	return (free_frame1(field));
}

static void	*free_frame3(t_field *field, char **lines, char ***elements)
{
	free_arr_double(elements, ft_arrdoublelen(elements), ft_arrlen(*elements));
	return (free_frame2(field, lines));
}

t_field	*frame(char *file)
{
	t_field	*field;
	char	**lines;
	char	***elements;

	if (file == NULL)
		return (0);
	field = (t_field *)malloc(sizeof(*field));
	field->flag = 0;
	lines = read_file(file, field);
	if (lines == 0)
		return (free_frame1(field));
	if (field->flag == -1)
		return (free_frame2(field, lines));
	elements = split_lines(lines, field);
	if (elements == 0)
		return (free_frame2(field, lines));
	if (field->flag == -1)
		return (free_frame3(field, lines, elements));
	set_field(field);
	set_height(field, elements);
	free_arr(lines, field->row);
	free_arr_double(elements, field->row, field->col);
	return (field);
}
