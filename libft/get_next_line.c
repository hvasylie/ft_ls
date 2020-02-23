/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:03:16 by hvasylie          #+#    #+#             */
/*   Updated: 2019/10/19 22:57:50 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_line(char **line, char **str, int fd)
{
	int		lenght;
	char	*tmp;

	lenght = 0;
	while (str[fd][lenght] != '\0' && str[fd][lenght] != '\n')
		lenght++;
	if (str[fd][lenght] == '\n')
	{
		*line = ft_strsub(str[fd], 0, lenght);
		tmp = ft_strdup(str[fd] + lenght + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			size_fd;
	static char	*str[FD_MAX];
	char		*tmp;

	if (fd < 0 || read(fd, buf, 0) < 0 || \
	!line || fd > FD_MAX || BUFF_SIZE <= 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	while ((size_fd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size_fd] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (str[fd][0] == '\0')
		return (0);
	return (new_line(line, str, fd));
}
