/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:29:43 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/18 17:20:06 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	a;
	size_t	i;

	if (!str)
		return (NULL);
	a = (char) c;
	i = ft_strlen(str);
	while (i + 1 != 0)
	{
		if (str[i] == a)
			return ((char *)str + i);
		--i;
	}
	return (NULL);
}
