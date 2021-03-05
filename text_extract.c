/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:53:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/05 21:59:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_replacetabs(char *temp, char *str, int len)
{	
	size_t	i;
	size_t	j;
	
	*temp = '\0';
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\t')
		{
			strlcat((void *)temp, "    ", len);
			j += 4;
		}
		else
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	free(str);
	str = temp;
}

void	*ft_realloctabs(char *str, int tab_nbr, t_map *map)
{
	int len;
	char	*temp;

	len = ft_strlen(str) + (tab_nbr * 3);
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
	{
		map->error++;
		return (0);
	}
	ft_replacetabs(temp, str, len);
	return (temp);
}

void	ft_tabtospace(t_map *map)
{
	int	i;
	int	tab_nbr;

	i = 0;
	while (map->text[i])
	{
		if (ft_strchr(map->text[i], '\t'))
		{
			tab_nbr = ft_countchr(map->text[i], '\t');
			map->text[i] = ft_realloctabs(map->text[i], tab_nbr, map);
		}
		i++;
	}
}

void	ft_new_line(t_map *map)
{
	char	**temp;
	int	i;

	i = 0;
	(map->lnbr)++;
	temp = malloc(sizeof(char *) * ((map->lnbr) + 2));
	if (!temp)
		return ;
	while (map->text[i])
	{
		temp[i] = map->text[i];
		i++;
	}
	temp[map->lnbr] = 0;
	temp[map->lnbr + 1] = 0;
	free(map->text);
	map->text = temp;
}

void	cub_extract(t_map *map, int fd)
{
	while (get_next_line(fd, &(map->text[map->lnbr])) > 0)
		ft_new_line(map);
	ft_tabtospace(map);
}
