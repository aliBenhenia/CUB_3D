/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:56 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/08 14:20:11 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MAP_H
# define RENDER_MAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include "./parsing/libpars.h"
# define PI2 6.2831853072
# define NORTH 0
# define EAST 1
# define WEAST 2
# define SOUTH 3
# define WIDTH 1080
# define HEIGHT 720
# define TILE_SIZE 30
# define FOV 60.0
# define MOVE_SPEED 5
# define ROTATION_SPEED 1.5
# define NUM_RAYS  WIDTH
# define RIGHT_ARROW  124
# define LEFT_ARROW  123
# define KEY_A 0
# define KEY_S 1
# define KEY_W 13
# define KEY_D 2
# define KEY_ESC 53

typedef struct player
{
	double	x;
	double	y;
	double	turn_direction;
	int		walk_direction;
	bool	is_lr;
	double	rotation_angle;
}	t_player;

typedef struct help
{
	bool	found_horz_wall_hit;
	double	wall_hit_x;
	double	wall_hit_y;
	bool	found_vertical_wall_hit;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	double	y_intercept;
	double	x_intercept;
	double	y_step;
}	t_help;

typedef struct ray
{
	double	ray_angle;
	double	wall_hit_x_;
	double	wall_hit_y_;
	double	distance;
	bool	was_hit_vertical;
	bool	is_ray_facing_up;
	bool	is_ray_facing_down;
	bool	is_ray_facing_left;
	bool	is_ray_facing_right;
	int		wall_height;
	t_help	_help;
}	t_ray;

typedef struct s_img
{
	void		*mlx_img;
	uint32_t	*addr;
	int			width;
	int			height;
}	t_img;

typedef struct data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map_height;
	int			map_width;
	void		*wimg;
	uint32_t	*wframe;
	t_cub		*pars;
	t_player	_player;
	t_ray		my_ray[NUM_RAYS];
	t_img		textures[4];
}	t_data;

void		cast_rays(t_data *info);
void		clean_data(t_data *info);
int			destroy(t_data *info);
void		clean_images_window(t_data *info, int failed_texture);
uint32_t	get_color_from_texture(t_ray *ray, t_img *texture, int wall_y);
int			get_height(char **map);
int			getwidth(char **map);
void		handle_horizantal(t_data *info, int ray_index);
void		handle_vert(t_data *info, int ray_index);
bool		has_wall_in_path(t_data *info, double x_to_move, double y_to_move);
void		helper_func(t_data *info, double h, double v, int ray_index);
void		init_info_rays(t_ray *ray, double rayAngle);
void		init_player_data(t_player *player, char **map);
bool		is_inside_map(t_data *info, double next_x, double next_y);
bool		is_player(char c);
bool		is_wall(t_data *info, double x, double y);
int			move(int keycode, t_data *info);
double		norm_angl(double rayangle);
int			release(int key, t_data *info);
int			render_(t_data *info);
bool		render_map(t_data *info, t_cub *pars_data);

#endif
