/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 02:42:41 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/11 12:26:25 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"libft.h"
#include<fcntl.h>
//#include<stdio.h>

size_t	ft_putstr_fd(char *str, int fd)
{
	if (str)
	{
		while (*str)
			ft_putchar_fd(*str++, fd);
	}
	return (ft_strlen(str));
}
/*
int main()
{
    int fd = open("test.txt", O_RDWR | O_CREAT);
    printf("%d\n", fd);
    if (fd == -1)
        printf("Error!");
    else
    {
		char *str = "I'm writing... ";
        ft_putstr_fd(str, fd);
        close(fd);
    }
    return (0);
}
*/