/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:15:51 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/27 18:10:35 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *left_chars, char *buffer);
char	*set_line(char *line_buffer);
char	*ft_strchr(char *buffer, int c);
char	*ft_strdup(char *s);
int		ft_strlen(char *string);
char	*ft_substr(char *line_buffer, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif
