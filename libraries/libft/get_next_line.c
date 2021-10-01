/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:01:29 by igvaz-fe          #+#    #+#             */
/*   Updated: 2021/10/01 17:39:52 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

static char	*get_line(char **buffer_backup)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer_backup)
		return (NULL);
	while ((*buffer_backup)[i] != '\0' && (*buffer_backup)[i] != '\n')
		i++;
	line = ft_substr(*buffer_backup, 0, i + is_endl(*buffer_backup));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*get_backup(char **buffer_backup)
{
	char	*backup;
	int		i;

	i = 0;
	if (!buffer_backup)
		return (NULL);
	while ((*buffer_backup)[i] != '\0' && (*buffer_backup)[i] != '\n')
		i++;
	if ((*buffer_backup)[i] == '\0')
	{
		free(*buffer_backup);
		return (NULL);
	}
	backup = ft_substr(*buffer_backup, i + 1, ft_strlen(*buffer_backup) - i);
	if (!backup)
	{
		free(backup);
		return (NULL);
	}
	free(*buffer_backup);
	return (backup);
}

static int	read_file(int fd, char **buffer, char **buffer_backup, char **line)
{
	int		bytes_read;
	char	*holder;

	bytes_read = 1;
	while (is_endl(*buffer_backup) != 1 && bytes_read > 0)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		holder = *buffer_backup;
		*buffer_backup = ft_strjoin(holder, *buffer);
		free(holder);
	}
	free(*buffer);
	*line = get_line(buffer_backup);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	*buffer_backup = get_backup(buffer_backup);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_backup;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	bytes_read = read_file(fd, &buffer, &buffer_backup, &line);
	if (bytes_read == 0 && !line)
		return (NULL);
	return (line);
}
