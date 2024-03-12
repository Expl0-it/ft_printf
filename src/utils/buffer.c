/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:43:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 13:52:36 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

void	flush_buf(t_data *data)
{
	data->len += write(STDOUT_FILENO, data->buf, data->buf_index);
	ft_bzero(data->buf, BUF_SIZE);
	data->buf_index = 0;
}

void	write_to_buf(t_data *data, char c)
{
	if (data->buf_index == BUF_SIZE)
		flush_buf(data);
	data->buf[data->buf_index] = c;
	data->buf_index++;
}

void	put_padding(char c, int count, t_data *data)
{
	if (0 >= count)
		return ;
	while (count)
	{
		write_to_buf(data, c);
		count--;
	}
}
