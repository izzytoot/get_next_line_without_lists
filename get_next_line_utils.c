/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:15:58 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/28 12:01:53 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*string;

	len = ft_strlen(s);
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_substr(char *line_buffer, int start, int len)
{
	char	*string;
	int		s_len;
	int		i;
	int		j;

	if (!line_buffer)
		return (NULL);
	s_len = ft_strlen(line_buffer);
	if (start > s_len)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = start;
	j = 0;
	while (i < s_len && j < len)
		string[j++] = line_buffer[i++];
	string[j] = '\0';
	return (string);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}
