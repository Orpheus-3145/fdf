/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 02:27:56 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/11 12:24:51 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"libft.h"
//#include<fcntl.h>
//#include<stdio.h>

size_t	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
	return (1);
}

// int main()
// {
//     int fd = open("test.txt", O_RDWR | O_CREAT);
//     printf("%d\n", fd);
//     if (fd == -1)
//         printf("Error!");
//     else
//     {
//         ft_putchar_fd('a', fd);
//         close(fd);
//     }
//     return (0);
// }