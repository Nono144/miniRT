#include "minirt.h"

void	ft_check_system_resolution(t_scene *scene)
{
	int	w;
	int	h;

	mlx_get_screen_size(scene->window.mlx_ptr, &w, &h);
	if (scene->x > w)
		scene->x = w;
	if (scene->y > h)
		scene->y = h;
}

