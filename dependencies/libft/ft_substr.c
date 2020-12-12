#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	j;

	j = 0;
	if (!s)
		return (0);
	if (!(ret = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (j < len && s[start])
			ret[j++] = s[start++];
	}
	ret[j] = '\0';
	return (ret);
}
