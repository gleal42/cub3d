/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:07:24 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 20:06:06 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./start_game.h"

static void		set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

static void		init_header(t_adata *a, t_bmp *bmp)
{
	int	i;

	i = 0;
	while (i < 14)
		bmp->fileheader[i++] = 0;
	bmp->fileheader[0] = 'B';
	bmp->fileheader[1] = 'M';
	bmp->fileheader[10] = 54;
	i = 0;
	while (i < 40)
		bmp->infoheader[i++] = 0;
	bmp->infoheader[0] = 40;
	bmp->infoheader[12] = 1;
	bmp->infoheader[14] = 24;
	i = 0;
	while (i < 3)
		bmp->pad[i++] = 0;
	set_header(&bmp->fileheader[2], bmp->filesize);
	set_header(&bmp->infoheader[4], a->win.win_w);
	set_header(&bmp->infoheader[8], a->win.win_h);
	write(bmp->fd, bmp->fileheader, 14);
	write(bmp->fd, bmp->infoheader, 40);
}

static void		draw_bmp(t_adata *a, t_bmp *bmp)
{
	int				i;
	int				j;
	unsigned char	buffer[3];

	j = (a->win.win_h - 1);
	while (j >= 0)
	{
		i = 0;
		while (i <= a->win.win_w - 1)
		{
			buffer[0] = (unsigned char)(a->img_3d.addr[((int)j *
			(int)(a->win.win_w) + (int)i)]);
			buffer[1] = (unsigned char)(a->img_3d.addr[((int)j *
			(int)(a->win.win_w) + (int)i)] >> 8);
			buffer[2] = (unsigned char)(a->img_3d.addr[((int)j *
			(int)(a->win.win_w) + (int)i)] >> 16);
			write(bmp->fd, buffer, 3);
			i++;
		}
		j--;
	}
}

void			convert_bmp(t_adata *a)
{
	t_bmp	bmp;

	bmp.filesize = 54 + 3 * (a->win.win_w) * (a->win.win_h);
	bmp.img = malloc((sizeof(char) * 3 * (a->win.win_w) * (a->win.win_h)));
	ft_memset(bmp.img, 0, 3 * (a->win.win_w) * (a->win.win_h));
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	init_header(a, &bmp);
	draw_bmp(a, &bmp);
	free(bmp.img);
	close(bmp.fd);
}

void			screenshot(char *cubname)
{
	int			fd;
	t_adata		a;

	ft_start_tmap(&a.parse);
	fd = open(cubname, O_RDONLY);
	cub_extract(&a.parse, fd);
	if (a.parse.error)
	{
		printf("there was an error while extracting");
		return ;
	}
	if (!ft_parse_cub(a.parse.text, &a.parse))
		return ;
	ft_init_all(&a);
	ftinit_img_3d(&a);
	ft_update_player(&a);
	update_sprites(&a);
	draw_floorrgb(&a);
	draw_ceilingrgb(&a);
	draw3d(&a);
	draw_map(&a);
	convert_bmp(&a);
	destroyimg(&a, &a.img_3d);
}
