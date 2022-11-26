#include "minishell.h"

t_map	*ft_getmap(t_map *lst, int key)
{
	while (lst != NULL)
	{
		if (lst->key == key)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_map	*ft_mapnew(char *content, e_type type)
{
        t_map  *lstnew;

        lstnew = (t_map *) ft_calloc(1, sizeof(*lstnew));
        if (!lstnew)
                return (NULL);
        lstnew->content = content;
		lstnew->type = type;
        lstnew->next = NULL;
        return (lstnew);
}

t_map  *ft_maplast(t_map *lst)
{
        if (!lst)
                return (NULL);
        while (lst)
        {
                if (!lst->next)
                        return (lst);
                lst = lst->next;
        }
        return (lst);
}

void    ft_addmap(t_map **alst, t_map *new)
{
        t_map  *tmp;

        if (!new)
                return ;
        if (!*alst)
        {
                *alst = new;
				(*alst)->key = 0;
                return ;
        }
        tmp = ft_maplast(*alst);
        tmp->next = new;
		tmp->next->key = tmp->key + 1;
}

void    ft_mapdelone(t_map *lst, void (*del)(void*))
{
        if (!del || !lst)
                return ;
	if (lst->content)
        	del(lst->content);
        free(lst);
}

void    ft_mapclear(t_map **lst, void (*del)(void *))
{
        t_map  *tmp;
		
		if (!*lst)
			return ;
        while (*lst)
        {
                tmp = (*lst)->next;
                ft_mapdelone(*lst, del);
                *lst = tmp;
        }
        *lst = NULL;
}

int     ft_mapsize(t_map *lst)
{
        int     count;

        count = 0;
        while (lst != NULL)
        {
                lst = lst->next;
                count++;
        }
        return (count);
}

