#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *node)
{
	t_list	*aux;

	if (alst && node)
	{
		if (!*alst)
			*alst = node;
		else
		{
			aux = ft_lstlast(*alst);
			aux->next = node;
		}
	}
}
