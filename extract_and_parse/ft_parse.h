/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:41:45 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 20:05:35 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

enum	e_errors
{
	NOT_CUB_ERROR,
	INVALID_FILE,
	PARSING_ERROR,
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
void	*ft_realloctabs(char *str, int tab_nbr);
void	*ft_freetext(char **strs);
void	ft_start_tmap(t_parse *parse);
int		ft_countchr(char *str, char c);
int		cub_extract(t_parse *parse, int fd);
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
void	ft_free_to_str(char ***strs, int prev);
void	ft_init_textures(t_parse *parse);
void	free_all_texts(t_parse *parse);

#endif
