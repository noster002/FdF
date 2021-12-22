/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:32:51 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/19 23:41:03 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H
# include "struct.h"
# include "free.h"

char	*fdf_file(char *input);
t_field	*frame(char *file);
char	**read_file(char *file, t_field *field);
char	***split_lines(char **lines, t_field *field);
void	set_field(t_field *field);
void	set_height(t_field *field, char ***elements);
int		ft_arrdoublelen(char ***arr);
int		ft_arrlen(char **arr);

#endif