/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:39:57 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/19 20:01:10 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_l(char *str)
{
	char	*new_line;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*get_newline(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	new_str = NULL;
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	len = ft_strlene(str);
	if (str[i] == '\n' && str[i + 1] != '\0')
	{
		new_str = malloc(sizeof(char) * (len - i));
		if (new_str == NULL)
			return (NULL);
		j = 0;
		while (str[++i] != '\0')
			new_str[j++] = str[i];
		new_str[j] = '\0';
	}
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*stockline;
	ssize_t		stockread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		stockread = read(fd, buffer, BUFFER_SIZE);
		if (stockread < 0)
			return (free(buffer), free(str), str = NULL, NULL);
		if (stockread == 0)
			break ;
		buffer[stockread] = '\0';
		str = ft_strjoine(str, buffer);
		if (ft_strchre(str, '\n') != NULL)
			break ;
	}
	stockline = get_l(str);
	str = get_newline(str);
	return (free(buffer), stockline);
}
