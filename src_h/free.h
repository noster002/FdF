/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:11:16 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 12:25:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

void	free_arr(char **arr, int elements);
void	free_arr_double(char ***arr_double, int elements1, int elements2);
void	free_field(t_field *field);
int		free_main1(t_data *data);
int		free_main2(t_data *data);

#endif