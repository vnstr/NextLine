/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:55:18 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/26 19:09:07 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

/*
**	Free buff,  if needed.
*/

static int		buff_free(char **buff)
{
	if (*buff != NULL)
	{
		free(*buff);
	}
	*buff = NULL;
	return (0);
}

/*
**	Create buff,  if needed.
*/

static char		*buff_create(char *buff)
{
	if (buff == NULL)
	{
		buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return (NULL);
		buff[0] = '\0';
	}
	return (buff);
}


/*
**	Make a copy of the buffer
**	without characters up to 'c'.
*/

static char		*buff_c_cut(char *buff, char c)
{
	char		*res;
	uint64_t	i;
	uint64_t	j;

	res = NULL;
	res = buff_create(res);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != c)
		i++;
	if (buff[i] == '\0')
	{
		res[0] = buff[i];
		return (res);
	}
	i++;
	j = 0;
	while (buff[i] != '\0')
	{
		res[j++] = buff[i++];
	}
	res[j] = '\0';
	free(buff);
	return (res);
}

/*
**	Make a copy of the buffer
**	without characters up to 'c'.
*/

int				take_str(char **line, char **buff)
{
	*line = strcjoin_free_s1(*line, *buff, '\n');
	if (*line == NULL)
		return (-1);
	if (gnl_strchr(*buff, '\n'))
	{
		*buff = buff_c_cut(*buff, '\n');
		if (*buff == NULL)
			return (-1);
		return (1);
	}
	return (0);
}

/*
**	This function read the file with defined buffer size (default 4096).
**	Reading file is minimized. And function save buffer until the file end.
**	Supports multiple files.
*/

int				get_next_line(int fd, char **line)
{
	static char		*buff[1024];
	int32_t			read_count;
	int32_t			tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	*line = strcjoin_free_s1(NULL, "\0", '\0');
	if ((buff[fd] = buff_create(buff[fd])) == NULL)
		return (buff_free(&(buff[fd])) - 1);
	if (buff[fd][0] != '\0')
	{
		if ((tmp = take_str(line, &(buff[fd]))) == 1)
			return (1);
	}
	while ((read_count = read(fd, buff[fd], BUFFER_SIZE)) > 0 && tmp != -1)
	{
		buff[fd][read_count] = '\0';
		if ((tmp = take_str(line, &buff[fd])) == 1)
			return (1);
	}
	if (read_count < 0 || tmp == -1)
		return (buff_free(&(buff[fd])) - 1);
	return (buff_free(&(buff[fd])));
}
