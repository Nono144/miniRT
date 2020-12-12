#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ps1 && *ps1 == *ps2 && --n)
	{
		ps1++;
		ps2++;
	}
	return (*ps1 - *ps2);
}
