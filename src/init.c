/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:54:49 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/20 18:51:51 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

char	**ft_tmpcub(char *cubfile)
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

void	ft_printarr(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		ft_printf(tmp[i]);
		i++;
	}
	ft_printf("\n");
}

t_map	*ft_init(char *cubfile)
{
	t_map	*map;
	char	**tmp;

	tmp = ft_tmpcub(cubfile);
	ft_printarr(tmp);
	if (ft_checkmap(tmp, 0, 0))
	{
		ft_freearrs(tmp);
		ft_error("map is invalid", NULL);
	}
	map = ft_initmap(tmp);

	ft_freearrs(tmp);
	return (map);
	//if fd is invalid
	//getnextline purse one line and look for idemifier
	//if identifier -> put the value on the side
	// if empty, skip the line
	// else count the row and column (longest line) for the map
	// malloc 2d array
	//


	
}

