/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:41:51 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 20:08:46 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_game/start_game.h"

void	clean_sprites(t_adata *a, t_sps *sps)
{
	int		i;

	i = 0;
	while (i < sps->number)
	{
		destroyimg(a, &sps->items[i].imgsp);
		i++;
	}
	free(sps->items);
}

void	*ft_freetext(char **text)
{
	size_t	i;

	i = 0;
	while (text[i])
	{
		free(text[i]);
		i++;
	}
	free(text);
	return (0);
}

void	free_all_strs(char **strs)
{
	while (*strs)
	{
		free(*strs);
		strs++;
	}
}
