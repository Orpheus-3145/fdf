/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:45:38 by anonymous     #+#    #+#                 */
/*   Updated: 2022/11/02 18:02:33 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include<unistd.h>
/*
static void	del(void *obj)
{
	free(obj);
}

static void	*f(void *n_ptr)
{
	char	*c_ptr;
	size_t index;

	c_ptr = (char *) n_ptr;
	index = 0;
	while (c_ptr[index])
	{
		c_ptr[index] += 1;
		index++;
	}
	return ((void *) c_ptr);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_obj;
	void	*new_content;

	if (! f || ! del || ! lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_obj = ft_lstnew(new_content);
		if (! new_obj)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&new_lst, new_obj);
			lst = lst->next;
		}	
	}
	return (new_lst);
}
/*
int main()
{
	char *v1 = "abcd", *v2 = "efgh", *v3 = "ijklm", *v4 = "nopq";
	t_list *first, *second, *third, *fourth;
	first = ft_lstnew(ft_strdup(v1));
	second = ft_lstnew(ft_strdup(v2));
	third = ft_lstnew(ft_strdup(v3));
	fourth = ft_lstnew(ft_strdup(v4));
	first->next = second;
	second->next = third;
	third->next = fourth;
	t_list *tmp;// = first;
	ft_print_result(first);
	tmp = ft_lstmap(first, f, del);
	ft_print_result(tmp);
	return (0);
}
*/
