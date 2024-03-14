/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:30:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/14 13:30:17 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static long	convert_base(long tmp)
{
	if (10 <= tmp)
		return (tmp - 10 + 'a');
	else
		return (tmp + 0);
}

char	*ft_ltoa_base(long number, int base)
{
	int		i;
	char	*str;
	long	tmp;

	i = 0;
	tmp = number;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	str = (char *)malloc((i + 1) * sizeof(char));
	if (NULL == str)
		return (NULL);
	str[i + 1] = 0;
	while (0 <= i)
	{
		tmp = number / base;
		str[i] = convert_base(tmp);
		number /= base;
		i--;
	}
	return (str);
}
