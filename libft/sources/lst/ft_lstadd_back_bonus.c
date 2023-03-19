/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 02:24:13 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/20 19:00:05 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>
#include<stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_obj;

	if (! lst)
		return ;
	if (*lst)
	{
		last_obj = ft_lstlast(*lst);
		if (last_obj)
			last_obj->next = new;
	}
	else
		*lst = new;
}
/*
int main()
{
	char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd';
	char *p1 = &v1, *p2 = &v2, *p3 = &v3, *p4 = &v4;
	t_list *first, *second, *third, *fourth;
	t_list **ptr_lst;
	first = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	fourth = (t_list *) malloc(sizeof(t_list));
	ptr_lst = (t_list **) malloc(sizeof(t_list *));
	first->content = p1;
	first->next = second;
	second->content = p2;   
	second->next = third;
	third->content = p3;
	third->next = NULL;
	fourth->content = p4;
	fourth->next = NULL;
	ptr_lst = &first;
	t_list *last_one = ft_lstlast(*ptr_lst);
	printf("ultimo - pre aggiunta: %c\n", *((char *)(last_one->content)));
	ft_lstadd_back(ptr_lst, fourth);
	last_one = ft_lstlast(*ptr_lst);
	printf("ultimo - post aggiunta: %c\n", *((char *)(last_one->content)));
	return(0);
}
*/
