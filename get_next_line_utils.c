/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:23:04 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/26 19:16:09 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

/*
**	Function returns len of string 's'.
*/

static size_t		gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

/*
**	Function returns len of string 's'
**	to character 'c'.
*/


static size_t		gnl_strclen(char *s, char c)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (*s != '\0' && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

/*
**	Finds 'c' in string 's' and returns pointer for it.
*/

char				*gnl_strchr(char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

/*
**	The function adds to 's1' - 's2'
**	up to the character 'c'.
*/

char				*strcjoin_free_s1(char *s1, char *s2, char c)
{
	t_str	res;
	size_t	i;

	res.len = gnl_strlen(s1) + gnl_strclen(s2, '\n');
	res.s = (char*)malloc(sizeof(char) * (res.len + 1));
	if (res.s == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while ((s1 + i) != NULL && s1[i] != '\0')
	{
		res.s[i] = s1[i];
		i++;
	}
	while (s2 != NULL && *s2 != '\0' && *s2 != c)
	{
		res.s[i] = *s2;
		s2++;
		i++;
	}
	res.s[i] = '\0';
	free(s1);
	return (res.s);
}
