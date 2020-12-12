#include "libft.h"
#include <limits.h>

static int	ft_size_num(unsigned long long int n)
{
	size_t i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(unsigned long long int n)
{
	int						size;
	unsigned long long int	aux;
	char					*num;

	aux = n;
	size = ft_size_num(aux);
	if (!(num = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	num[--size + 1] = '\0';
	if (aux <= 0)
		aux = -aux;
	while (size >= 0)
	{
		num[size--] = (aux % 10) + '0';
		aux = aux / 10;
	}
	if (num[0] == '0' && num[1])
		num[0] = '-';
	return (num);
}
