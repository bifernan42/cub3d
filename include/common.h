/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:29:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 16:29:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PADDING 2
# define PLAYER_FOV 0.66f
# define PLAYER_MOV_STEP 0.1f
# define PLAYER_ROT_STEP 0.15f
# define DEFAULT_WIDTH 1366
# define DEFAULT_HEIGHT 768
# define SMLX_ROSE_PINE_BASE 0x191724
# define SMLX_ROSE_PINE_SURFACE 0x1f1d2e
# define SMLX_ROSE_PINE_OVERLAY 0x26233a
# define SMLX_ROSE_PINE_MUTED 0x6e6a86
# define SMLX_ROSE_PINE_SUBTLE 0x908caa
# define SMLX_ROSE_PINE_WHITE 0xe0def4
# define SMLX_ROSE_PINE_RED 0xeb6f92
# define SMLX_ROSE_PINE_YELLOW 0xf6c177
# define SMLX_ROSE_PINE_ROSE 0xebbcba
# define SMLX_ROSE_PINE_PINE 0x31748f
# define SMLX_ROSE_PINE_FOAM 0x9ccfd8
# define SMLX_ROSE_PINE_IRIS 0xc4a7e7
# define SMLX_ROSE_PINE_HLLOW 0x21202e
# define SMLX_ROSE_PINE_HLMED 0x403d52
# define SMLX_ROSE_PINE_HLHIG 0x524f67
# define SMLX_SOLID_WHITE 0xFFFFFF
# define SMLX_SOLID_GRAY 0xCCCCCC
# define SMLX_SOLID_BLACK 0x000000
# define SMLX_SOLID_RED 0xFF0000
# define SMLX_SOLID_GREEN 0x00FF00
# define SMLX_SOLID_BLUE 0x0000FF
# define SMLX_SOLID_YELLOW 0xFFFF00
# define SMLX_SOLID_CYAN 0x00FFFF
# define SMLX_SOLID_MAGENTA 0xFF00FF
# define SMLX_SOLID_ORANGE 0xFF9900
# define SMLX_SOLID_PURPLE 0x9900FF
# define NOTFOUND 0xFFFFFFFFFFFFFFFF

typedef struct s_list				t_list;
typedef struct s_container_cfg		t_container_cfg;
typedef struct s_container			t_container;
typedef struct s_raycaster			t_raycaster;
typedef struct s_camera				t_camera;
typedef struct s_map				t_map;
typedef struct s_node				t_node;
typedef struct s_entry				t_entry;
typedef struct s_hashmap			t_hashmap;
typedef struct s_bitset				t_bitset;
typedef struct s_smlx_bresenham		t_mlx_bresenham;
typedef struct s_smlx_instance		t_smlx_instance;
typedef struct s_smlx_event			t_smlx_event;
typedef struct s_smlx_frame_buffer	t_smlx_frame_buffer;
typedef struct s_smlx_texture		t_smlx_texture;
typedef struct s_vec2				t_vec2;
typedef void						*t_smlx_handle;
typedef bool						(*t_predicate)(int32_t ch);

struct								s_node
{
	struct s_node					*next;
	struct s_node					*prev;
	uintptr_t						data;
};

struct								s_list
{
	t_node							*head;
	t_node							*tail;
	uint64_t						size;
};

struct								s_entry
{
	char							*key;
	uintptr_t						value;
};

struct								s_hashmap
{
	uint64_t						size;
	uint64_t						capacity;
	t_entry							*body;
};

struct								s_smlx_texture
{
	t_smlx_handle					*img;
	int32_t							id;
	int32_t							bpp;
	int32_t							size;
	int32_t							endiant;
	int32_t							height;
	int32_t							width;
	uint8_t							*data;
};

struct								s_smlx_bresenham
{
	int32_t							dx;
	int32_t							dy;
	int32_t							sx;
	int32_t							sy;
	int32_t							err;
	int32_t							e2;
};

typedef struct s_vec2i
{
	int32_t							x;
	int32_t							y;
}									t_vec2i;

struct								s_smlx_frame_buffer
{
	t_smlx_handle					*img[3];
	int32_t							fid[3];
	int32_t							height[3];
	int32_t							width[3];
	int32_t							bpp[3];
	int32_t							size[3];
	int32_t							endian[3];
	uint8_t							*data[3];
};

struct								s_smlx_instance
{
	t_smlx_handle					*mlx;
	int32_t							height;
	int32_t							width;

	t_smlx_handle					*win;
	char							*title;

	t_smlx_handle					*img;
	int32_t							fid;
	int32_t							bpp;
	int32_t							size;
	int32_t							endian;
	uint8_t							*data;

	bool							render_ready;
	int64_t							time_last_ms;
	int64_t							time_trgt_ms;
	int64_t							time_prev_ms;
	int64_t							time_curr_ms;
	int64_t							time_delt_ms;
	int64_t							frame_counter;
	int64_t							frame_rendered;

	int32_t							frame_buffer_lvl;
	t_smlx_frame_buffer				frame_buffer;
};

typedef enum e_texture_id
{
	NORTH_TEXTURE,
	SOUTH_TEXTURE,
	EAST_TEXTURE,
	WEST_TEXTURE,
}									t_texture_id;

struct								s_vec2
{
	float							x;
	float							y;
};

struct								s_container_cfg
{
	int32_t							res_x;
	int32_t							res_y;

	char							**file_lines;

	int32_t							map_width;
	int32_t							map_height;
	char							**map_lines;

	char							*path_no_texture;
	char							*path_so_texture;
	char							*path_ea_texture;
	char							*path_we_texture;
	int32_t							info_line;
	int32_t							ceil_color;
	int32_t							floor_color;
};

struct								s_map
{
	int32_t							height;
	int32_t							width;
	int32_t							player_pos_x;
	int32_t							player_pos_y;
	char							player_dir;
	bool							enclosed;
	char							**grid;
	bool							*visited;
};

struct								s_camera
{
	t_map							*map;

	double							pos_x;
	double							pos_y;
	double							dir_x;
	double							dir_y;
	double							pln_x;
	double							pln_y;
	double							curr_time;
	double							prev_time;
	bool							move_left;
	bool							move_right;
	bool							move_up;
	bool							move_down;
	bool							rotate_left;
	bool							rotate_right;
};

struct								s_raycaster
{
	t_camera						*cam;
	t_map							*map;
	t_smlx_instance					*mlx;
	t_smlx_texture					*north;
	t_smlx_texture					*south;
	t_smlx_texture					*west;
	t_smlx_texture					*east;
	union
	{
		t_smlx_texture				*ceil_text;
		uint32_t					ceil_color;
	};
	union
	{
		t_smlx_texture				*floor_text;
		uint32_t					floor_color;
	};
	int32_t							width;
	int32_t							height;
	int32_t							x;
	int32_t							y;
	double							pos_x;
	double							pos_y;
	double							dir_x;
	double							dir_y;
	double							plane_x;
	double							plane_y;
	double							camera_x;
	double							ray_dir_x;
	double							ray_dir_y;
	int32_t							map_x;
	int32_t							map_y;
	double							side_dist_x;
	double							side_dist_y;
	double							delta_dist_x;
	double							delta_dist_y;
	double							per_wall_dist;
	int32_t							step_x;
	int32_t							step_y;
	int32_t							hit;
	int32_t							side;
	int32_t							line_height;
	int32_t							pitch;
	int32_t							draw_start;
	int32_t							draw_end;
	int32_t							text_num;
	double							wall_x;
	int32_t							text_x;
	int32_t							text_y;
	double							step;
	double							text_pos;
	uint32_t						color;
};

struct								s_container
{
	char							*file_buffer;
	t_container_cfg					*cfg;
	t_map							*map;
	t_camera						*cam;
	t_raycaster						*ray;
	t_smlx_instance					*smlx;
	t_vec2i							floor;
	t_vec2i							ceil;
	t_vec2i							middle;
};

#endif
