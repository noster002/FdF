/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:04:37 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/16 12:28:51 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_bool	same_ele_per_line(char **ele, int *nbr_ele_prev)
{
	int	nbr_ele;
	int	tmp;

	nbr_ele = 0;
	tmp = *nbr_ele_prev;
	while (ele[nbr_ele] != 0)
		nbr_ele++;
	*nbr_ele_prev = nbr_ele;
	if (tmp == 0 || tmp == nbr_ele)
		return (true);
	return (false);
}

char	***split_lines(char **lines, t_field *field)
{
	char	***ele;
	int		cnt_lns;
	int		cnt_ele;

	cnt_lns = 0;
	cnt_ele = 0;
	ele = (char ***)malloc(field->row * sizeof(*ele));
	if (ele == 0)
		return (0);
	while (cnt_lns < field->row)
	{
		ele[cnt_lns] = ft_split(lines[cnt_lns], ' ');
		if (!same_ele_per_line(ele[cnt_lns], &cnt_ele))
		{
			field->flag = -1;
			free_arr(ele[cnt_lns], cnt_ele);
			ele[cnt_lns] = 0;
			break ;
		}
		cnt_lns++;
	}
	field->col = cnt_ele;
	return (ele);
}
