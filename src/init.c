/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:54:49 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/16 18:00:45 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
//all of them needs to be tested with libft
int	ft_cntline(char *cubfile)
{
	int		fd;
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: file couldn't open\n");
		exit(1);
	}
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

char	**ft_filltmp(char **tmp, char *cubfile, int i)
{
	int		fd;
	char	*line;
//maybe keep it open?
	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: file couldn't open\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp[i] = ft_strdup(line);
		if (!tmp[i])
		{
			ft_frearrs(tmp);
			free (line);
			ft_printf("Error: malloc failed\n");
			exit (1);
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

	cnt = ft_cntline(cubfile);
	if (cnt <= 0)
	{
		ft_printf("Error: empty file\n");
		exit (1);
	}
	tmp = ft_calloc(cnt, sizeof(char **));
	if (!tmp)
	{
		ft_printf("Error: malloc failed\n");
		exit (1);
	}
	return (ft_fillmap(tmp, cubfile, 0));
}

int	ft_checkmap(char **tmp, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k])
		{
			if (tmp[i][k] == ' ')
				k++;
			if (!ft_strncmp(tmp[i] + k, "NO ", 3) || !ft_strncmp(tmp[i] + k, "SO ", 3)
				|| !ft_strncmp(tmp[i] + k, "WE ", 3) || !ft_strncmp(tmp[i] + k, "EA ", 3))
				ft_checktexture(tmp[i] + k + 3);
			else if (!ft_strncmp(tmp[i] + k, "F ", 2) || !ft_strncmp(tmp[i] + k, "C ", 2))
				ft_checkcolor(tmp[i] + k + 2);
			else if (tmp[i] + k == '1')
				ft_checknbr();
			i++;
		}
	}
	return ();
}


t_map	*ft_init(char *cubfile)
{
	t_map	*map;
	char	**tmp;

	map = ft_calloc(1 * sizeof(t_map));
	if (!map)
	{
		ft_printf("Error: malloc failed\n");
		exit (1);
	}
	tmp = ft_filltmp(cubfile);
	if (ft_checkmap(tmp, 0, 0))
		//error;
	
	//if fd is invalid
	//getnextline purse one line and look for idemifier
	//if identifier -> put the value on the side
	// if empty, skip the line
	// else count the row and column (longest line) for the map
	// malloc 2d array
	//


	
}

