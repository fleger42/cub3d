/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:00:21 by user42            #+#    #+#             */
/*   Updated: 2020/06/12 17:05:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <math.h>
# include "get_next_line.h"

typedef struct		s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
}					t_color;

typedef struct		s_map
{
	int			valid;
	int			x_res;
	int			y_res;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_sprite;
	t_color		path_f;
	t_color		path_c;
	char		**description;
	double		x_player;
	double		y_player;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	char		player_direction;
	double		*perp_buffer;
	int			nbr_sprite;
	int			verif_path_c;
	int			verif_path_f;
	int			n;

}					t_map;

typedef struct		s_player
{
	int left;
	int right;
	int key_w;
	int key_a;
	int key_s;
	int key_d;
	int escape;
}					t_player;

typedef struct		s_sprite
{
	double x;
	double y;
}					t_sprite;

typedef struct		s_drawing
{
	int			lineheight;
	int			drawend;
	int			drawstart;
	double		intensity;
	long double	step;
	long double	texpos;
	int			texy;
}					t_drawing;

typedef struct		s_raycast
{
	double		camerax;
	double		wallx;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			texx;
}					t_raycast;

typedef struct		s_spritecast
{
	int			stripe;
	double		spritex;
	double		spritey;
	double		transformx;
	double		transformy;
	double		invdet;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			texx;
	int			texy;
	int			d;
}					t_spritecast;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_win;
	int				y_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				sprite_width;
	int				sprite_height;
	int				sprite_bits_per_pixel;
	int				sprite_line_length;
	int				sprite_endian;
	void			*sprite_ptr;
	char			*sprite_addr;
	void			*text1_ptr;
	int				text1_width;
	int				text1_height;
	char			*text1_addr;
	int				text1_bpp;
	int				text1_ll;
	int				text1_endian;
	void			*text2_ptr;
	int				text2_width;
	int				text2_height;
	char			*text2_addr;
	int				text2_bpp;
	int				text2_ll;
	int				text2_endian;
	void			*text3_ptr;
	int				text3_width;
	int				text3_height;
	char			*text3_addr;
	int				text3_bpp;
	int				text3_ll;
	int				text3_endian;
	void			*text4_ptr;
	int				text4_width;
	int				text4_height;
	char			*text4_addr;
	int				text4_bpp;
	int				text4_ll;
	int				text4_endian;
	int				side;
	int				posx_wall;
	int				posy_wall;
	double			raydirx;
	double			raydiry;
	double			wall_layerposx;
	double			wall_layerposy;
	int				sizex;
	int				sizey;
	int				*sprite_order;
	double			*sprite_distance;
	t_map			*map;
	t_player		*player;
	t_sprite		**sprite;
	t_drawing		*drawing;
	t_raycast		*ray;
	t_spritecast	*spr;
}					t_win;

t_win				ft_create_win(char *title, t_map *map, char *str);
t_win				*ft_malloc_win(char *title, t_map *map, char *str);
void				ft_destroy_win(t_win to_destroy);
void				ft_free_win(t_win *to_free, int nbr);
char				*ft_strdup(const char *s1);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					get_next_line(int fd, char **line);
int					verif_chaine(char *str);
char				*readline(char *str, int fd);
t_map				ft_parsing(t_map info);
void				ft_aff(int n);
void				ft_putnbr(int n);
t_map				ft_create_map();
t_map				*ft_malloc_map();
void				ft_free_map(t_map *to_free);
int					ft_isdigit(char c);
int					ft_count_digit(char *str);
void				ft_parsing_description(t_map *info, int n, char **line);
double				ray_casting(t_win *win, int x);
int					check_tile(int i, int j, int size_case, t_win *win);
void				draw_wall_calculation(double perpwalldist, int i,
t_win *win, int texx);
void				display(t_win *win, t_map *map, int arg);
void				ft_reboot(t_win *win);
void				my_mlx_put_pxl_to_img(int x, int y, t_color color,
t_win *draw);
t_color				create_t_color(unsigned char p_b, unsigned char p_g,
unsigned char p_r, unsigned char p_a);
t_player			*ft_malloc_player();
t_sprite			ft_create_sprite();
t_sprite			*ft_malloc_sprite();
int					get_texture_width(t_win *win);
int					get_texture_height(t_win *win);
t_color				get_texture(t_win *win, int texx, int texy, double
intensity);
void				ft_free_player(t_player *to_free);
void				ft_str_one(char *str);
void				ft_verif_end_start(char *str);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_verif_zero_two(char **str, int x, int y);
void				ft_free_sprite(t_sprite **to_free, int nbr);
void				ft_save_bmp(t_win *win);
int					ft_write_in_file_img(int n, t_win *win);
int					get_color(t_win *win, int x, int y);
int					ft_write_in_file_header(int n, int nbr, t_win *win);
void				binary_shift(unsigned char *str, int value);
void				ft_error(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_add_line(char ***line, t_map *info, char ***temp, int j);
void				ft_verif_valid(t_map *info, int j, int i);
void				ft_fill_player_direction(char *line, t_map *info);
void				ft_set_player(t_map *map);
int					verif_line(char *str, t_map *info);
char				**realloc_description(char **description, char *str);
char				*char_walk(char *str);
void				verif_map(t_map info);
t_color				color_c(char *str, t_map *info);
t_color				color_f(char *str, t_map *info);
void				ft_sprite_casting(t_win *win, int nbr_sprite);
void				ft_create_sprite_tab(int nbr_sprite, t_win *win);
void				ft_sort_sprite(int nbr_sprite, t_win *win);
void				ft_get_pos_sprite(t_win *win, t_sprite **sprite);
int					ft_key_input(t_win *win);
int					ft_count_sprite(t_win *win);
int					key_release(int key, t_win *win);
int					key_press(int key, t_win *win);
int					ft_exit(t_win *win);
void				ft_key_s(t_win *win);
void				ft_key_w(t_win *win);
void				ft_key_a(t_win *win);
void				ft_key_d(t_win *win);
void				ft_key_right(t_win *win);
void				ft_key_left(t_win *win);
void				ft_sprite_color(t_win *win, int y);
void				ft_sprite_texy(t_win *win, int y);
void				ft_sprite_texx(t_win *win);
void				ft_sprite_calculation(t_win *win, int i);
void				ft_sprite_calculation2(t_win *win);
void				ft_load_texture(t_win *win);
void				ft_sprite_dist(t_win *win, int nbr_sprite);
t_map				param_r(t_map pars, char *str);
void				ft_get_addr(t_win *win);
void				ft_load_img(t_win *win);
#endif
