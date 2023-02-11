/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:01:16 by ecanci            #+#    #+#             */
/*   Updated: 2023/01/18 18:01:25 by ecanci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_the_line(str, fd);
	if (!str)
		return (0);
	line = get_line(str);
	str = next_str(str);
	return (line);
}

//#include <stdio.h>
/*
int main(void)
{
	int fd;
	char *line;
	char *prev_line;

	fd = open("example.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		//free(prev_line);
		prev_line = line;
	}
	printf("Sondan bir onceki satir: %s\n", prev_line);

	return 0;
}
*/


/*
int main(void)
{
	int fd;
	char *line;

	fd = open("example.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		
	}
	printf("Son satir: %s\n", line);
	close(fd);
	return 0;
}*/
/*
int main()
{
	int fd = open("example.txt", O_RDONLY);
	char *line;
	char *prev_line;

	while(line = get_next_line(fd))
		prev_line = line;
	
	printf(prev_line);
}*/
/*
int main()
{
	int fd = open("example.txt", O_RDONLY);

	char *line1 = get_next_line(fd);
	char *line2 = get_next_line(fd);
	char *line3 = get_next_line(fd);
	char *line4 = get_next_line(fd);

	printf("%s", line4);
}*/