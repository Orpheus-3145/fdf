/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 23:53:44 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/20 19:03:11 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>
//#include<stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_obj;

	new_obj = (t_list *) malloc(sizeof(t_list));
	if (new_obj == NULL)
		return (NULL);
	if (! content)
		new_obj->content = NULL;
	else
		new_obj->content = content;
	new_obj->next = NULL;
	return (new_obj);
}
/*
int main()
{
    char c = 'a';
    char *ptr = NULL;//&c;
    t_list *tst = ft_lstnew(ptr);
    printf("%c\n", *((char *)(tst->content)));
}
*/