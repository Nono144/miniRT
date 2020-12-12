#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t cont;

	cont = 0;
	if (!s)
		return (0);
	while (*s++ && s)
	{
		cont++;
	}
	return (cont);
}
