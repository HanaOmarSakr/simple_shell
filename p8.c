#include "main.h"
/**
 * w_number - Prints a string
 * @is_negative: Lists of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int w_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & _ZERO) && !(flags & _MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & _PLUS)
		extra_ch = '+';
	else if (flags & _SPACE)
		extra_ch = ' ';

	return (w_num(ind, buffer, flags, width, precision,
		len, padd, extra_ch));
}

/**
 * w_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @len: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int w_num(int ind, char buffer[],
	int flags, int width, int precision,
	int len, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (!precision && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && !width)
		return (0);
	if (!precision && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & _MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & _MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & _MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}

/**
 * w_uns - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int w_uns(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		padd = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & _ZERO) && !(flags & _MINUS))
		padd = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & _MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * w_ptr - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int w_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & _MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & _MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & _MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
