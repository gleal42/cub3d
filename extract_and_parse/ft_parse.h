/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:41:45 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 22:05:10 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

enum	e_errors
{
	MALLOCERROR,
	MULTIRES,
	BADSCREEN,
	MULTINO,
	BADNO,
	MULTISO,
	BADSO,
	MULTIWE,
	BADWE,
	MULTIEA,
	BADEA,
	MULTISPRITE,
	BADSPRITE,
	MULTIFLOOR,
	BADFLOOR,
	MULTICEIL,
	BADCEIL,
	INVALIDMAP,
	INVALIDCHAR,
	MISSINGPARAMS
};

int		check_resolution(char **text, t_parse *parse, int *i, int *count);
int		check_textures(char **text, t_parse *parse, int *i, int *count);
int		check_rgbs(char **text, t_parse *parse, int *i, int *count);
int		check_valid_chars(char **text, int *i);
int		is_map(char *str);
void	*ft_realloctabs(char *str, int tab_nbr, t_parse *parse);
void	*ft_freetext(char **strs);
void	ft_start_tmap(t_parse *parse);
int		ft_countchr(char *str, char c);
void	cub_extract(t_parse *parse, int fd);
int		ft_parse_cub(char **text, t_parse *parse);
int		ft_isspace(char c);
int		ft_error(int errornbr);
int		ft_parsenorthtext(char *str, t_parse *parse);
int		ft_parsesouthtext(char *str, t_parse *parse);
int		ft_parsewesttext(char *str, t_parse *parse);
int		ft_parseeasttext(char *str, t_parse *parse);
int		ft_parsespritetext(char *str, t_parse *parse);
int		checkmultiplayer(char *str, t_parse *parse);
int		check_valid_map(char **strs, t_parse *parse);
int		ft_copy_map(char **map_start, t_parse *parse);
int		start_game(t_adata *a);
void	screenshot(char *cubname);

#endif
