/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:46:14 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 13:49:57 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		data_init(t_data *data, const char *format)
{
	data->s = format;
	data->len = 0;
	data->buf = (char *)ft_calloc(BUF_SIZE, sizeof(char));
	if (NULL == data->buf)
		return (-1);
	data->buf_index = 0;
	return (0);
}



int		loop_string(t_data	*data)
{
	while (*data->s)
	{
		if (*data->s == '%' && *(++data->s))
		{
			if (parse_format(data))
				return (-1);
			render_format(data);
		}
		else
			write_to_buf(data, *data->s);
		++(data->s);
	}
	flush_buf(data);
	va_end(data->ap);
	free(data->buf);
	return (0);
}
