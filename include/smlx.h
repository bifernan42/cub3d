/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:42:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/09 20:42:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMLX_H
# define SMLX_H

# include "../mlx/mlx.h"
# include "common.h"
# include "slib.h"
# include "smlx_keysym.h"
# include "sys/time.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

void			smlx_tick_rate(t_smlx_instance *self);
int64_t			smlx_timestamp(void);
void			smlx_chrono_starts(t_smlx_instance *self);
void			smlx_chrono_ends(t_smlx_instance *self);
int64_t			smlx_chrono_delta(t_smlx_instance *self);
void			smlx_set_target_fps(t_smlx_instance *self, int64_t target_fps);

t_smlx_instance	*smlx_instance_create(int32_t width, int32_t height,
					char *title);
bool			smlx_instance_resize(t_smlx_instance *self, int32_t width,
					int32_t height, char *title);
bool			smlx_instance_display(t_smlx_instance *self);
t_smlx_instance	*smlx_instance_destroy(t_smlx_instance *self);

void			smlx_draw_line(t_smlx_instance *self, t_vec2i start,
					t_vec2i end, uint32_t color);
void			smlx_draw_pixel(t_smlx_instance *self, t_vec2i pos,
					uint32_t color);
void			smlx_draw_clear(t_smlx_instance *self, uint32_t color);
void			smlx_draw_grid(t_smlx_instance *self, int32_t w_lines,
					int32_t h_lines, uint32_t color);
void			smlx_draw_grid_propo(t_smlx_instance *self, int32_t w_lines,
					int32_t h_lines, uint32_t color);
void			smlx_draw_vertical(t_smlx_instance *self, int32_t x,
					t_vec2i start_end, uint32_t color);
void			smlx_fetch_new_image(t_smlx_instance *self);

t_smlx_texture	*smlx_texture_create(t_smlx_instance *self,
					char *path_to_texture, int32_t id);
uint32_t		smlx_get_texture_color_at(t_smlx_texture *self, float_t u,
					float_t v);
uint32_t		smlx_get_texture_color(t_smlx_texture *self, t_vec2 start,
					t_vec2 curr, t_vec2 end);
t_smlx_texture	*smlx_texture_destroy(t_smlx_instance *self,
					t_smlx_texture *texture);
#endif
