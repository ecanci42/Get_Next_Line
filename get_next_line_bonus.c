/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:10:39 by ecanci            #+#    #+#             */
/*   Updated: 2023/02/02 19:10:44 by ecanci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_the_line(char *str, int fd)
{
	int		buff;
	char	*s1;

	s1 = malloc(BUFFER_SIZE + 1);
	buff = 1;
	if (!s1)
		return (0);
	while (!ft_strchr(str, '\n') && buff)
	{
		buff = read(fd, s1, BUFFER_SIZE);
		if (buff == -1)
		{
			free(s1);
			return (0);
		}
		s1[buff] = '\0';
		str = ft_strjoin(str, s1);
	}
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = read_the_line(str[fd], fd);
	if (!str[fd])
		return (0);
	line = get_line(str[fd]);
	str[fd] = next_str(str[fd]);
	return (line);
}

/*
#include <stdio.h>

int	main()
{
	int fd1 = open("deneme1.txt", O_RDONLY);
	int fd2 = open("deneme2.txt", O_RDONLY);

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
}

*/