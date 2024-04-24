/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:46:14 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 14:44:33 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	check_base(t_data *data)
{
	if (NULL != ft_strchr("diu", data->flags.type))
		data->utils.base = BASE_10;
	else if (NULL != ft_strchr("xXp", data->flags.type))
	{
		data->utils.base = BASE_16;
		if ('X' == data->flags.type)
			data->utils.uppercase = true;
	}
}

static void	parse_flags(t_data *data)
{
	char	flag;

	while (NULL != ft_strchr("-+ #0", *data->s))
	{
		flag = *data->s;
		if ('-' == flag)
			data->flags.minus = true;
		if ('+' == flag)
			data->flags.plus = true;
		if (' ' == flag)
			data->flags.space = true;
		if ('#' == flag)
			data->flags.hash = true;
		if ('0' == flag)
			data->flags.zero = true;
		++(data->s);
	}
}

static void	get_value(t_data *data, int *value)
{
	if ('*' == *data->s)
	{
		*value = va_arg(data->ap, int);
		++data->s;
		return ;
	}
	*value = ft_atoi(data->s);
	while (ft_isdigit(*(data->s)))
		++(data->s);
}

int	parse_format(t_data *data)
{
	ft_bzero(&data->flags, sizeof(t_flags));
	ft_bzero(&data->utils, sizeof(t_utils));
	data->flags.precision = -1;
	parse_flags(data);
	get_value(data, &data->flags.width);
	if ('.' == *data->s && *(++data->s))
		get_value(data, &data->flags.precision);
	if (NULL == ft_strchr("cspdiuxX%", *data->s))
		return (-1);
	else
	{
		data->flags.type = *data->s;
		check_base(data);
	}
	return (0);
}
