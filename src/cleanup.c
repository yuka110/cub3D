/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 17:25:02 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/09 17:56:25 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

//free 2d int arrays
void	ft_freeintarrs(int **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

//free 2d char arrays
void	ft_freearrs(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

//free map struct & show error msg
void	ft_error(char *msg, t_map *map)
{
	if (map)
	{
		ft_freeintarrs(map->map2d);
			free(map->floor);
			free(map->ceiling);
			free(map->n_tex);
			free(map->s_tex);
			free(map->s_tex);
			free(map->s_tex);
		free(map);
	}
	ft_printf("Error: %s\n", msg);
	exit(1);
}

//used at the end of program & exit 0
void	ft_cleanup(t_data *data)
{
	ft_freeintarrs(data->map->map2d);
	free(data->map->ceiling);
	free(data->map->floor);
	free(data->map->s_tex);
	free(data->map->n_tex);
	free(data->map->w_tex);
	free(data->map->e_tex);
	free(data->map);
	free(data);
	exit(0);
}
