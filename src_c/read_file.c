/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:08:28 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/19 23:52:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	cnt_lines(char *file)
{
	char	*tmp;
	int		fd;
	int		i;
	int		count;

	fd = open(file, O_RDONLY);
	i = 1;
	count = 0;
	while (i == 1)
	{
		i = get_next_line(fd, &tmp);
		free(tmp);
		count++;
	}
	close(fd);
	if (i == -1)
		count = 0;
	return (count);
}

char	**read_file(char *file, t_field *field)
{
	char	**line;
	int		fd;
	int		i;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 1;
	count = 0;
	line = (char **)malloc(cnt_lines(file) * sizeof(*line));
	if (line == 0)
		return (0);
	while (i == 1)
		i = get_next_line(fd, &line[count++]);
	close(fd);
	if (i == -1)
		field->flag = -1;
	field->row = count;
	return (line);
}
