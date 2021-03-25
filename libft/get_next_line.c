/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:01:21 by gleal             #+#    #+#             */
/*   Updated: 2021/02/18 16:45:58 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void			ft_strdel(char **str_ptr)
{
	if (str_ptr)
	{
		free(*str_ptr);
		*str_ptr = 0;
	}
}

static int		ft_next_line_save_extra(char **extra_text, char **line, int fd)
{
	int		i;
	char	*trim;

	i = 0;
	while (extra_text[fd][i] && extra_text[fd][i] != '\n')
		i++;
	if (extra_text[fd][i] == '\n')
	{
		*line = ft_substr(extra_text[fd], 0, i);
		trim = ft_strdup(&extra_text[fd][i + 1]);
		ft_strdel(&extra_text[fd]);
		extra_text[fd] = trim;
		if (extra_text[fd][0] == '\0')
			ft_strdel(&extra_text[fd]);
	}
	else
	{
		*line = ft_strdup(extra_text[fd]);
		ft_strdel(&extra_text[fd]);
		return (0);
	}
	return (1);
}

static int		ft_loopbuffer(char **extra_text, int fd)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];
	char	*add_buffer;

	i = 1;
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		if (extra_text[fd])
		{
			add_buffer = ft_strjoin(extra_text[fd], buf);
			ft_strdel(&extra_text[fd]);
			extra_text[fd] = add_buffer;
		}
		else
			extra_text[fd] = ft_strdup(buf);
		if (ft_strchr(extra_text[fd], '\n'))
			break ;
		else
			i = read(fd, buf, BUFFER_SIZE);
	}
	return (i);
}

int				get_next_line(int fd, char **line)
{
	static char	*extra_text[10000];
	int			i;

	if (fd < 0 || fd > 10000 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!extra_text[fd])
		extra_text[fd] = ft_strnew(0);
	i = ft_loopbuffer(extra_text, fd);
	if (!i && !extra_text[fd])
		return (0);
	return (ft_next_line_save_extra(extra_text, line, fd));
}
