#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*first_node;

	if (lst)
	{
		if (!(first_node = ft_lstnew(f(lst->content))))
			return (NULL);
		aux = first_node;
		lst = lst->next;
		while (lst)
		{
			if (!(aux->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&first_node, del);
				return (NULL);
			}
			aux = aux->next;
			lst = lst->next;
		}
		return (first_node);
	}
	return (NULL);
}
