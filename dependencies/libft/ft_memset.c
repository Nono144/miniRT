#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *pb;

	pb = (unsigned char*)b;
	while (len-- > 0)
		*(pb++) = (unsigned char)c;
	return (b);
}
