/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 02:49:04 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/11 12:16:18 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>
/*
static void	del(void *obj)
{
	free(obj);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/*
int main()
{
	int v1 = 1, v2 = 2;
	int *p1 = &v1, *p2 = &v2;
	t_list *first, *second;
	first = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	first->content = p1;
	first->next = second;
	second->content = p2;   
	second->next = NULL;
	
	printf("pre delete: %d\n", *((int *)(first->content)));
	ft_lstdelone(first, del);
	if (first->content == NULL)
		printf("eliminato\n");
	return (0);
}
*/