/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:50:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/26 18:18:40 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct		s_str
{
	char			*s;
	size_t			len;
}					t_str;

int					get_next_line(int fd, char **line);
char				*strcjoin_free_s1(char *s1, char *s2, char c);
char				*gnl_strchr(char *s, char c);

#endif
