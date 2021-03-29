/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_textures2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:06:51 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 18:06:55 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsespritetext(char *str, t_parse *parse)
{
	int i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	parse->sprite_text = ft_strdup(&str[i]);
	if (!parse->sprite_text)
		return (0);
	if (open(parse->sprite_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parseeasttext(char *str, t_parse *parse)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	parse->ea_text = ft_strdup(&str[i]);
	if (!parse->ea_text)
		return (0);
	if (open(parse->ea_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parsewesttext(char *str, t_parse *parse)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	parse->we_text = ft_strdup(&str[i]);
	if (!parse->we_text)
		return (0);
	if (open(parse->we_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parsesouthtext(char *str, t_parse *parse)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	parse->so_text = ft_strdup(&str[i]);
	if (!parse->so_text)
		return (0);
	if (open(parse->so_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parsenorthtext(char *str, t_parse *parse)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	parse->no_text = ft_strdup(&str[i]);
	if (!parse->no_text)
		return (0);
	if (open(parse->no_text, O_RDONLY) < 0)
		return (0);
	return (1);
}
