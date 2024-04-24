/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:27:54 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 14:34:15 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	precision_zero_padding(t_data *data)
{
	if (data->flags.precision >= 0)
	{
		if (data->flags.precision > data->utils.tmp_len)
		{
			data->utils.padding_zeros = data->flags.precision - \
											data->utils.tmp_len;
			return (1);
		}
	}
	return (0);
}

void	set_num_padding_zeros(t_data *data)
{
	if (precision_zero_padding(data))
		return ;
	if (data->flags.zero)
	{
		if (data->flags.minus)
			return ;
		if (data->flags.width > data->utils.tmp_len)
			data->utils.padding_zeros = data->flags.width - \
											data->utils.tmp_len;
		if ('u' == data->flags.type)
			return ;
		else if ((ft_strchr("xX", data->flags.type) && data->flags.hash
				&& data->utils.tmp[0] != '0') || data->flags.type == 'p')
			data->utils.padding_zeros -= 2;
		else if (data->utils.is_negative || (!data->utils.is_negative
				&& (data->flags.plus || data->flags.space)))
			data->utils.padding_zeros -= 1;
	}
	if (data->utils.padding_zeros < 0)
		data->utils.padding_zeros = 0;
}

void	set_num_padding_spaces(t_data *data)
{
	data->utils.padding = data->flags.width - data->utils.padding_zeros \
		- data->utils.tmp_len;
	if (ft_strchr("uxXp", data->flags.type))
	{
		if ((ft_strchr("xX", data->flags.type) && data->flags.hash
				&& data->utils.tmp[0] != '0') || data->flags.type == 'p')
			data->utils.padding -= 2;
		return ;
	}
	if (data->utils.is_negative)
	{
		data->utils.padding--;
		return ;
	}
	if (!data->utils.is_negative && (data->flags.plus || data->flags.space))
		data->utils.padding--;
}
