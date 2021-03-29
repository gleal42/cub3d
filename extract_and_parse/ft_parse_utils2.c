/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:13:39 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 20:12:03 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_cubfile(char *file)
{
	int i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'b')
		return (0);
	if (file[i--] != 'u')
		return (0);
	if (file[i--] != 'c')
		return (0);
	if (file[i] != '.')
		return (0);
	return (1);
}

void	ft_free_to_str(char ***strs, int prev)
{
	if (prev < 0)
	{
		free(*strs);
		return ;
	}
	while (prev >= 0)
	{
		free(strs[0][prev]);
		strs[0][prev] = 0;
		prev--;
	}
	free(*strs);
}

void	free_texture(char **texture)
{
	if (*texture)
	{
		free(*texture);
		*texture = 0;
	}
}

void	free_all_texts(t_parse *parse)
{
	free_texture(&parse->no_text);
	free_texture(&parse->so_text);
	free_texture(&parse->we_text);
	free_texture(&parse->ea_text);
	free_texture(&parse->sprite_text);
}

void	ft_init_textures(t_parse *parse)
{
	parse->no_text = 0;
	parse->so_text = 0;
	parse->we_text = 0;
	parse->ea_text = 0;
	parse->sprite_text = 0;
}
