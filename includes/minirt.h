#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <float.h>
# include <time.h>
# include "mlx.h"
# include "libft.h"
# include "printf.h"
# include "get_next_line.h"
# include "algebra.h"
# include "axis.h"
# include "camera.h"
# include "error.h"
# include "geometry.h"
# include "geometry_types.h"
# include "load.h"
# include "load_utils.h"
# include "pipeline.h"
# include "scene_types.h"
# include "shadows.h"
# include "color.h"
# include "bmp.h"
# include "bmp_types.h"
# include "clean.h"
# include "keys.h"
# include "minirt_bonus.h"

void	ft_minirt(t_scene s);
void	ft_scene_to_screen(t_scene *scene);
int		ft_exit(t_window *window);

void	ft_handle_axis_translation(int key, t_scene *s);
void	ft_change_camera(int key, t_scene *s);
int		ft_handle_keyboard(int key, t_scene *s);
int		ft_handle_mouse(int press, int u, int v, t_scene *s);

#endif
