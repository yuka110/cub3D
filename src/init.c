/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:54:49 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/19 17:46:58 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
//all of them needs to be tested with libft
int	cnt_line(char *cubfile)
{
	int		fd;
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
		ft_error("file couldn't open");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cnt++;
		free (line);
	}
	free (line);
	close(fd);
	return (cnt);
}

char	**fill_tmp(char **tmp, char *cubfile, int i)
{
	int		fd;
	char	*line;
//maybe keep it open?
	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
	{
		ft_freearrs(tmp);
		ft_error("file couldn't open");
	}
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
			ft_error("malloc failed");
		}
		free (line);
		i++;
	}
	free (line);
	close(fd);
	return (tmp);
}

char	**ft_tmpmap(char *cubfile)
{
	char	**tmp;
	int		cnt;

	cnt = cnt_line(cubfile);
	if (cnt <= 0)
		ft_error("empty file");
	tmp = ft_calloc(cnt + 1, sizeof(char *));
	if (!tmp)
		ft_error("malloc failed");
	return (fill_tmp(tmp, cubfile, 0));
}

void	ft_printmap(char **tmp)
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

	tmp = ft_tmpmap(cubfile);
	ft_printmap(tmp);
	if (ft_checkmap(tmp, 0, 0))
	{
		ft_printf("map is invalid\n");
		ft_freearrs(tmp);
		exit (1);
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

