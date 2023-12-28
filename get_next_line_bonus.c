/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:35:22 by oel-moue          #+#    #+#             */
/*   Updated: 2023/12/28 03:35:27 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_fd(int fd, char *stock)
{
	char	*buffer;
	ssize_t	d;

	d = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!ft_strchr(stock, '\n') && d != 0)
	{
		d = read(fd, buffer, BUFFER_SIZE);
		if (d == -1)
			return (free(buffer), free(stock), NULL);
		buffer[d] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (stock == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stock);
}

char	*ft_get_line(char *stock)
{
	char	*temp;
	int		i;
	int		j;

	if (stock == NULL || stock[0] == '\0')
		return (NULL);
	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	temp = malloc(i + 1);
	if (temp == NULL)
		return (free(stock),NULL);
	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		temp[j++] = stock[i++];
	if (stock[i] == '\n')
		temp[j] = stock[i];
	j++;
	temp[j] = '\0';
	return (temp);
}

char	*rest(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (stock == NULL)
		return ( NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\0')
	{
		free(stock);
		return (NULL);
	}
	str = malloc(ft_strlen(stock) - i + 1);
	if (!str)
		return (free(stock), NULL);
	i++;
	j = 0;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	*stock[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	stock[fd] = read_fd(fd, stock[fd]);
	line = ft_get_line(stock[fd]);
	stock[fd] = rest(stock[fd]);
	return (line);
}

// int	main(void)
//  {
//  	int f,f1,f2;
//  	f = open("ab.txt", O_RDONLY | O_CREAT, 0644);
//     f1 = open("ab1.txt", O_RDONLY | O_CREAT, 0644);
//     f2 = open("ab2.txt", O_RDONLY | O_CREAT, 0644);

//     char *p = get_next_line_bonus(f);
//     char *p1 = get_next_line_bonus(f1);

//     printf("%s",p);
//     free(p);
//     printf("%s",p1);
//     free(p1);
// }
