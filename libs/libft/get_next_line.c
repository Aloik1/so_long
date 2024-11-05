/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:08:35 by ikondrat          #+#    #+#             */
/*   Updated: 2024/11/05 15:38:35 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_free(char *str)
{
	if (str)
	{
		free (str);
		str = NULL;
	}
	return (NULL);
}

char	*check_last_line(char *out)
{
	if (!out)
		return (NULL);
	if (ft_strlen(out) == 0)
	{
		free(out);
		return (NULL);
	}
	return (out);
}

char	*small_line(char **line)
{
	size_t	i;
	char	*left;
	char	*out;

	if (!(*line))
		return (NULL);
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
	{
		out = ft_substr(*line, 0, i + 1);
		if (!out)
			return (ft_free(*line));
		left = ft_strdup(*line + i + 1);
		if (!left)
			return (ft_free(*line));
		free(*line);
		*line = left;
		return (out);
	}
	out = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (check_last_line(out));
}

char	*big_line(int fd, char *buffer, char **line, ssize_t to_read)
{
	char		*aux;

	while (to_read > 0)
	{
		buffer[to_read] = '\0';
		if (!*line)
			*line = ft_strdup("");
		if (!*line)
			return (ft_free(*line));
		aux = ft_strjoin(*line, buffer);
		free (*line);
		*line = aux;
		if (ft_strchr(*line, '\n'))
			break ;
		to_read = read(fd, buffer, BUFFER_SIZE);
	}
	ft_free(buffer);
	return (small_line(line));
}

char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			to_read;
	static char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	to_read = read(fd, buffer, BUFFER_SIZE);
	if (to_read == -1)
	{
		ft_free(buffer);
		ft_free(line);
		line = NULL;
		return (NULL);
	}
	buffer[to_read] = '\0';
	return (big_line(fd, buffer, &line, to_read));
}
