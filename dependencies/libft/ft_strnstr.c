#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	while (haystack[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (i + j) < (int)len)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
		i++;
	}
	if (!needle[0])
		return ((char *)haystack);
	return (NULL);
}
