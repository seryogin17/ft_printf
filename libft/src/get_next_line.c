/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:13:44 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:13:44 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*send_to_line(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	*line = ft_strsub(str, 0, i);
	tmp = ft_strsub(str, i + 1, ft_strlen(&str[i]));
	ft_strdel(&str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int			rec;
	char		buff[BUFF_SIZE + 1];
	static char	*str[4864];
	char		*tmp;

	if (fd < 0 || fd > 4864 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && (rec = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = str[fd];
		buff[rec] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		ft_strdel(&tmp);
	}
	if (*str[fd] != '\0')
	{
		str[fd] = send_to_line(str[fd], line);
		return (1);
	}
	ft_strdel(&str[fd]);
	return (0);
}