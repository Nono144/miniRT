#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		it;

	if (!dst)
		return (0);
	it = 0;
	len = ft_strlen(src);
	while (src[it] != '\0' && it < (int)(dstsize - 1))
	{
		dst[it] = src[it];
		it++;
	}
	if (dstsize)
		dst[it] = '\0';
	return (len);
}
