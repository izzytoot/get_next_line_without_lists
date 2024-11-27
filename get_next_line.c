/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:15:45 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/27 18:37:36 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*contained_chars;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		contained_chars = NULL;
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, contained_chars, buffer);
	if (buffer)
	{	
		free(buffer);
		buffer = NULL;
	}
	if (!line)
		return (NULL);
	contained_chars = set_line(line);
	return (line);
}

char	*fill_line_buffer(int fd, char *contained_chars, char *buffer)
{
	int		c_read;
	char	*temp;

	c_read = 1;
	while (1)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == -1)
		{
    		if (contained_chars)
				free(contained_chars);
			return (free(buffer), NULL);
		}
		else if (c_read == 0)
			break ;
		buffer[c_read] = 0;
		if (!contained_chars)
			contained_chars = ft_strdup("");
		temp = contained_chars;
		contained_chars = ft_strjoin(temp, buffer);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (contained_chars);
}

char	*set_line(char *line_buffer)
{
	char	*contained_chars;
	int		i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	contained_chars = ft_substr(line_buffer, i + 1,
			(ft_strlen(line_buffer) - i));
	if (contained_chars == 0)
			contained_chars = NULL;
	line_buffer[i + 1] = '\0';
	return (contained_chars);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == (char)c)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (char)c)
		return ((char *)&buffer[i]);
	return (NULL);
}
