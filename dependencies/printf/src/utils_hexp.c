#include "printf.h"

void					ft_print_hex(char *hex, long long int num, char uplow)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!(num & (LONG_MASK >> i)) && (i < 64))
		i += 4;
	if (i >= 64)
	{
		hex[j] = '0';
		j++;
	}
	while (i < 64)
	{
		hex[j] = (num & (LONG_MASK >> i)) >> (60 - i);
		if (hex[j] > 9)
			hex[j] = hex[j] + uplow - 33;
		else
			hex[j] = hex[j] + '0';
		i += 4;
		j++;
	}
	hex[j] = '\0';
}
