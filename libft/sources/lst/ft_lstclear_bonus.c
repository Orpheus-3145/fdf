/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 03:05:44 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/21 18:24:57 by faru          ########   odam.nl         */
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
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_to_drop;
	t_list	*to_drop;

	if (! lst || ! del || ! lst)
		return ;
	to_drop = *lst;
	while (to_drop)
	{
		next_to_drop = (to_drop)->next;
		del(to_drop->content);
		free(to_drop);
		to_drop = next_to_drop;
	}
	*lst = NULL;
}
/*
int main()
{
	char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd';
	char *p1 = &v1, *p2 = &v2, *p3 = &v3, *p4 = &v4;
	t_list *first, *second, *third, *fourth;
	t_list **vct;
	first = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	fourth = (t_list *) malloc(sizeof(t_list));
	vct = (t_list **) malloc(sizeof(t_list *));
	first->content = malloc(sizeof(char));
	first->next = (t_list *) malloc(sizeof(t_list));
	*((char *)(first->content)) = *p1;
	first->next = second;

	second->content = malloc(sizeof(char));
	second->next = (t_list *) malloc(sizeof(t_list));
	*((char *)(second->content)) = *p2;   
	second->next = third;

	third->content = malloc(sizeof(char));
	third->next = (t_list *) malloc(sizeof(t_list));
	*((char *)(third->content)) = *p3;
	third->next = fourth;

	fourth->content = malloc(sizeof(char));
	fourth->next = (t_list *) malloc(sizeof(t_list));
	*((char *)(fourth->content)) = *p4;
	fourth->next = NULL;

	vct = &second;
	ft_lstclear(vct, del);
	return(0);
}
*/
