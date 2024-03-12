/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:03 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 21:52:30 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// NOTE: flags in str: ('-' justify left) && (width) && precision

// TODO: start here
static int		set_str_padding(t_data *data, char *s)
{
	int		length;

	length = ft_strlen(s);
	if (0 < data->flags.width)
	{
		if (0 <= data->flags.precision)
		{
			if (length < data->flags.precision)
				;
			else if (length > data->flags.precision)
				;
		}
		else
		{

		}
	}
}

void	render_string(t_data *data, char *s)
{
	if (NULL == s)
		s = "(null)";
	if (data->flags.minus)
	{
		if (0 <= data->flags.precision)
			buf_put_string(s, data->flags.precision, data);
		else
			buf_put_string(s, ft_strlen(s), data);
	}
}
