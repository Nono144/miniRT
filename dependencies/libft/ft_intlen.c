#include "libft.h"

size_t	ft_intlen(int *s)
{
	size_t cont;

	cont = 0;
	if (!s)
		return (0);
	while (s[cont] != -1)
	{
		cont++;
	}
	return (cont);
}
