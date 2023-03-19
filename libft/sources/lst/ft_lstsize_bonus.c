/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 02:09:55 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/11 14:14:25 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	if (lst)
		cnt = 1;
	else
		return (0);
	while (lst->next)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
/*
int main()
{
	int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
	int *p1 = &v1, *p2 = &v2, *p3 = &v3, *p4 = &v4;
	t_list *first, *second, *third, *fourth;
	//first = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	fourth = (t_list *) malloc(sizeof(t_list));
	//first->content = p1;
	//first->next = second;
	second->content = p2;   
	second->next = third;
	third->content = p3;
	third->next = fourth;
	fourth->content = p4;
	fourth->next = NULL;
	printf("elements: %d", ft_lstsize(first));
	return(0);
}
*/