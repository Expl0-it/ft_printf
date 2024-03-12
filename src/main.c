/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:49:08 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 14:02:15 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int num1 = ft_printf("[%-10c]", 'a');
	ft_printf("\n");
	int num2 = ft_printf("[%-*c]", 10, 'a');
	ft_printf("\n");
	int num3 = ft_printf("[%3c]", 'a');
	ft_printf("\n");
	printf("%d, %d, %d \n", num1, num2, num3);

	num1 = printf("[%-10c]", 'a');
	printf("\n");
	num2 = ft_printf("[%-*c]", 10, 'a');
	printf("\n");
	num3 = printf("[%3c]", 'a');
	printf("\n");
	printf("%d, %d, %d \n", num1, num2, num3);
}
