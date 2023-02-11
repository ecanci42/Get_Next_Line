/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:02:14 by ecanci            #+#    #+#             */
/*   Updated: 2023/01/18 18:02:18 by ecanci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ---------- GNL ------------ */
char	ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*get_line(char *str);
char	*next_str(char *str);
char	*read_the_line(char *str, int fd);
char	*get_next_line(int fd);
#endif
