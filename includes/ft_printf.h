/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:07:32 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 13:46:42 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "../libft/libft.h"

// NOTE: Bit shift - 4096 bytes
#define BUF_SIZE (1<<12)
#define FLAGS ("-+ #0")
#define TYPES ("cspdiuxX%")

typedef enum
{
	BASE_10 = 10,
	BASE_16 = 16,
}		e_base;

typedef struct s_flags
{
	bool	minus;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;

	int		width;
	int		precision;

	char	type;
	e_base	base;
	bool	uppercase;
}			t_flags;

typedef struct s_data
{
	const char	*s;

	va_list		ap;
	
	int			len;

	char		*buf;
	int			buf_index;

	t_flags		flags;
}			t_data;

/*
* @brief Format and print data to stdout
*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*
*/
int		ft_printf(const char *format, ...);

int		data_init(t_data *data, const char *format);

int		loop_string(t_data	*data);

void	check_base(t_data *data);

int		parse_format(t_data *data);

void	write_to_buf(t_data *data, char c);

void	flush_buf(t_data *data);

void	render_format(t_data *data);

void	put_padding(char c, int count, t_data *data);

void	render_char(t_data *data, int c);

#endif
