/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:53:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 19:14:14 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_replacetabs(char **temp, char **str, int len)
{
	size_t	i;
	size_t	j;

	temp[0][0] = '\0';
	i = 0;
	j = 0;
	while (i < ft_strlen(str[0]))
	{
		if (str[0][i] == '\t')
		{
			strlcat((void *)temp[0], "    ", len);
			j += 4;
		}
		else
		{
			temp[0][j] = str[0][i];
			j++;
		}
		i++;
	}
	temp[0][j] = '\0';
	free(*str);
	*str = 0;
}

void	*ft_realloctabs(char *str, int tab_nbr)
{
	int		len;
	char	*temp;

	len = ft_strlen(str) + (tab_nbr * 3);
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	ft_replacetabs(&temp, &str, len);
	return (temp);
}

int		ft_tabtospace(t_parse *parse)
{
	int		i;
	int		tab_nbr;

	i = 0;
	while (parse->text[i])
	{
		if (ft_strchr(parse->text[i], '\t'))
		{
			tab_nbr = ft_countchr(parse->text[i], '\t');
			parse->text[i] = ft_realloctabs(parse->text[i], tab_nbr);
			if (!parse->text[i])
			{
				ft_free_to_str(&parse->text, i - 1);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int		ft_new_line(t_parse *parse)
{
	char	**temp;
	int		i;

	i = 0;
	(parse->lnbr)++;
	temp = malloc(sizeof(char *) * ((parse->lnbr) + 2));
	if (!temp)
	{
		ft_freetext(parse->text);
		return (0);
	}
	while (parse->text[i])
	{
		temp[i] = parse->text[i];
		i++;
	}
	temp[parse->lnbr] = 0;
	temp[parse->lnbr + 1] = 0;
	free(parse->text);
	parse->text = temp;
	return (1);
}

int		cub_extract(t_parse *parse, int fd)
{
	while (get_next_line(fd, &(parse->text[parse->lnbr])) > 0)
	{
		if (!ft_new_line(parse))
			return (ft_error(PARSING_ERROR));
	}
	if (!ft_tabtospace(parse))
		return (ft_error(PARSING_ERROR));
	return (1);
}
