/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:17:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 13:17:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "common.h"
# include "slib.h"
# include "smlx.h"
# include "smlx_keysym.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

// container
t_container		*container_create(char *file_name);
t_container		*container_destroy(t_container *self);

/******************************************************************************/
/*                                CONFIG                                      */
/******************************************************************************/

t_container_cfg	*container_cfg_create(char *file_buffer);
bool			container_cfg_parse(t_container_cfg *cfg);
t_container_cfg	*container_cfg_destroy(t_container_cfg *self);
bool			config_line_is_texture_line(char *line);
bool			config_line_is_color_line(char *line);
bool			config_line_is_map_line(char *line);
bool			config_sanitize_texture_line(char *line);
bool			config_sanitize_color_line(char *color_line);
bool			config_sanitize_map_line(char *line);
void			config_parse_texture_line(t_container_cfg *cfg, char *line);
void			config_parse_color_line(t_container_cfg *cfg, char *line);
void			config_parse_map_line(t_container_cfg *cfg, char *line);

/******************************************************************************/
/*                                 MAP                                        */
/******************************************************************************/

t_map			*map_create(t_container_cfg *cfg);
bool			map_sanitize(t_map *map);
t_map			*map_destroy(t_map *map);
void			map_print(t_map *map);

/******************************************************************************/
/*                                 CAM                                        */
/******************************************************************************/

t_camera		*camera_create(t_map *map, t_container_cfg *cfg);
void			log_camera_state(t_camera *cam);
void			camera_move(t_camera *cam, float_t amount);
void			camera_rota(t_camera *cam, float_t amount);
void			camera_mouse(t_camera *cam, float_t amount);
void			camera_update(t_camera *camera);
t_camera		*camera_destroy(t_camera *cam);

/******************************************************************************/
/*                              RAYCASTER                                     */
/******************************************************************************/

t_raycaster		*raycaster_create(t_smlx_instance *smlx, t_camera *camera,
					t_map *map, t_container_cfg *cfg);
void			raycaster_draw(t_raycaster *ray, t_camera *camera, t_map *map);
void			log_raycaster(const t_raycaster *ray);
void			raycaster_find_dist_perp_ray(t_raycaster *ray);
void			raycaster_find_low_and_high_pix_in_strip(t_raycaster *ray);
void			raycaster_pick_texture_from_orientation(t_raycaster *ray);
void			raycaster_calculate_value_of_wall_x(t_raycaster *ray);
void			raycaster_find_x_coord_text(t_raycaster *ray);
void			raycaster_draw_texture(t_raycaster *ray);
t_raycaster		*raycaster_destroy(t_raycaster *raycaster);

/******************************************************************************/
/*                                CUB3D                                       */
/******************************************************************************/

void			cub3d_start(t_container *const self);
int32_t			cub3d_render(void *param);
int32_t			on_keypressed(int32_t keycode, void *param);
int32_t			on_keyreleased(int32_t keycode, void *param);
int32_t			on_mouse_move(int32_t x, int32_t y, void *param);
int32_t			on_program_quit(void *param);
int32_t			on_program_start(t_container *const self,
					t_smlx_instance *const smlx);

/******************************************************************************/
/*                                UTILS                                       */
/******************************************************************************/

void			*dealloc_array(char **ptr);
char			*file_open_read_to_end_alloc(char *file_name);
bool			file_is_correct_extension(char *file_name);
int32_t			string_to_rgb(const char *const line);

/******************************************************************************/
/*                                ERRORS                                      */
/******************************************************************************/

void			report_error_and_die_endl(char *msg);
void			report_error_cleanup_and_die_endl(t_container *cub3d,
					char *msg);
void			cub3d_assert(bool cond, char *label);

#endif
