#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function that formats and prints output.
 * @format: The format string specifying the output format.
 * ...
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int printed_chars = 0, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	va_start(list, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE - 1) /* Leave space for null terminator*/
			{
				buffer[buff_ind] = '\0';
				write(1, buffer, buff_ind);
				printed_chars += buff_ind;
				buff_ind = 0;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			/* Handle format specifier */
			/* ... */

			/* Update printed_chars accordingly */
			/* ... */
		}
	}

	buffer[buff_ind] = '\0'; /*Null-terminate the buffer*/
	write(1, buffer, buff_ind);
	printed_chars += buff_ind;

	va_end(list);

	return (printed_chars);
}

/* Rest of the code remains the same */
