/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:45:28 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/21 18:25:08 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>
/*
static void	f(void *n_ptr)
{
	int	*i_ptr;

	i_ptr = (int *) n_ptr;
	*i_ptr += 10;
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (! lst || ! f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int main()
{
	int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
	int *p1 = &v1, *p2 = &v2, *p3 = &v3, *p4 = &v4;
	t_list *first, *second, *third, *fourth;
	t_list **vct;
	first = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	fourth = (t_list *) malloc(sizeof(t_list));
	vct = (t_list **) malloc(sizeof(t_list *));
	first->content = p1;
	first->next = second;
	second->content = p2;   
	second->next = third;
	third->content = p3;
	third->next = fourth;
	fourth->content = p4;
	fourth->next = NULL;
	t_list *tmp = (t_list *) malloc(sizeof(t_list));
	tmp = first;
	while (tmp->next)
	{
		printf("pre: %d\n", *((int *)(tmp->content)));
		tmp = tmp->next;
	}
	ft_lstiter(first, f);
	while(first->next)
	{
		printf("post: %d\n", *((char *)(first->content)));
		first = first->next;
	}
	return(0);
}
*/