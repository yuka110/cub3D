/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsecub.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:54:49 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/09 13:22:17 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	cnt_line(int fd, char *cubfile)
{
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
		ft_error("file couldn't open", NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cnt++;
		free (line);
	}
	free (line);
	close (fd);
	return (cnt);
}

char	**fill_tmp(char **tmp, int fd, int i, char *cubfile)
{
	char	*line;

	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
		ft_error("file couldn't open", NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp[i] = ft_strdup(line);
		if (!tmp[i])
		{
			ft_freearrs(tmp);
			free (line);
			ft_error("malloc failed", NULL);
		}
		free (line);
		i++;
	}
	free (line);
	close (fd);
	return (tmp);
}

char	**ft_parsecub(char *cubfile)
{
	char	**tmp;
	int		cnt;
	int		fd;

	fd = 0;
	cnt = cnt_line(fd, cubfile);
	if (cnt <= 0)
		ft_error("empty file", NULL);
	tmp = ft_calloc(cnt + 1, sizeof(char *));
	if (!tmp)
		ft_error("malloc failed", NULL);
	tmp = fill_tmp(tmp, fd, 0, cubfile);
	return (tmp);
}
