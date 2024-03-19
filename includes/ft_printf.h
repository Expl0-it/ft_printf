/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:07:32 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/19 14:15:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "../libft/libft.h"

// NOTE: Bit shift - 4096 bytes (1<<12)
# define BUF_SIZE 4096

typedef enum e_base
{
	BASE_10 = 10,
	BASE_16 = 16,
}		t_base;

// NOTE: Hold multiple values at the same adress in memory
typedef union union_long
{
	unsigned long	unsigned_l;
	long			signed_l;
}			t_union_long;

/*
 * - - left justify
 * 
 * + - force sign before numer
 * 
 * ' ' - if no sign (positive numer) then space before value
 * 
 *		Used with o, x or X specifiers the value is preceeded with
 *		0, 0x or 0X respectively
 *		for values different than zero.
 *	# -	Used with a, A, e, E, f, F, g or G it forces the
 *		written output to contain
 *		a decimal point even if no more digits follow.
 *		By default, if no digits follow, no decimal point is written.
 *  
 *  0 - Left-pads the number with zeroes (0) instead
 *  of spaces when padding is specified
 *
 *  Width -	Minimum number of characters to be printed.  On '*' the width
 *  is not specified
 *  in the format string, but as an additional integer value argument
 *  preceding the formated argument
 *
 *  Precision - For integer specifiers (d, i, o, u, x, X): precision specifies
 *  the minimum number
 *  of digits to be written. If the value to be written is shorter
 *  than this number, the result
 *  is padded with leading zeros. The value is not truncated
 *  even if the result is longer.
 *  A precision of 0 means that no character is written for the value 0.
 *  For a, A, e, E, f and F specifiers: this is the number of
 *  digits to be printed after
 *  the decimal point (by default, this is 6).
 *  For g and G specifiers: This is the maximum number
 *  of significant digits to be printed.
 *  For s: this is the maximum number of characters to be printed.
 *  By default all characters are printed until the ending
 *  null character is encountered.
 *  If the period is specified without an explicit value for
 *  precision, 0 is assumed.
 *  On '*' the precision is not specified in the format string,
 *  but as an additional integer value
 *  argument preceding the argument that has to be formatted. 
 */
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
	t_base	base;
	bool	uppercase;
	int		padding;
	int		padding_zeros;
	bool	is_signed;
	bool	is_negative;
	char	*tmp;
	int		tmp_len;
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

void	render_str(t_data *data, char *s);

void	render_format(t_data *data);

void	buf_put_chars(char c, int count, t_data *data);

void	render_char(t_data *data, int c);

void	buf_put_string(char *s, int length, t_data *data);

void	render_number(t_data *data, t_union_long number);

char	*ft_ltoa_base(unsigned long number, unsigned int base, \
				bool upperase, char type);

void	set_num_padding_zeros(t_data *data);

void	set_num_padding_spaces(t_data *data);

#endif
