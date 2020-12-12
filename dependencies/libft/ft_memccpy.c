#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n-- > 0)
	{
		*pdst = *psrc;
		if (*(psrc++) == (unsigned char)c)
			return (pdst + 1);
		pdst++;
	}
	return (NULL);
}
