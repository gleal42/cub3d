/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:16:11 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 20:09:23 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_error_pt2(int errornbr)
{
	if (errornbr == BADSPRITE)
		printf("can't open sprite textures");
	if (errornbr == MULTIFLOOR)
		printf("multiple floor colors");
	if (errornbr == BADFLOOR)
		printf("invalid floor colors");
	if (errornbr == MULTICEIL)
		printf("multiple ceiling colors");
	if (errornbr == BADCEIL)
		printf("invalid ceiling colors");
	if (errornbr == INVALIDMAP)
		printf("invalid map");
	if (errornbr == INVALIDCHAR)
		printf("invalid character in cub text");
	if (errornbr == MISSINGPARAMS)
		printf("missing at least one parameter");
	return (0);
}

int		ft_error_pt1(int errornbr)
{
	if (errornbr == MULTIRES)
		printf("multiple resolutions");
	if (errornbr == BADSCREEN)
		printf("invalid screensize!");
	if (errornbr == MULTINO)
		printf("multiple north textures");
	if (errornbr == BADNO)
		printf("can't open north textures");
	if (errornbr == MULTISO)
		printf("multiple south textures");
	if (errornbr == BADSO)
		printf("can't open south textures");
	if (errornbr == MULTIWE)
		printf("multiple west textures");
	if (errornbr == BADWE)
		printf("can't open west textures");
	if (errornbr == MULTIEA)
		printf("multiple east textures");
	if (errornbr == BADEA)
		printf("can't open east textures");
	if (errornbr == MULTISPRITE)
		printf("multiple sprite textures");
	return (0);
}

int		ft_error(int errornbr)
{
	ft_error_pt1(errornbr);
	ft_error_pt2(errornbr);
	return (0);
}
