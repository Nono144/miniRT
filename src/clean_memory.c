#include "minirt.h"

void	ft_clean_squares(t_scene scene, t_square **square)
{
	int	i;

	(void)scene;
	i = 0;
	while (square[i])
	{
		free(square[i]);
		square[i] = NULL;
		i++;
	}
	free(square[i]);
	square[i] = NULL;
	free(square);
	square = NULL;
}

void	ft_clean_triangles(t_scene scene, t_triangle **triangle)
{
	int	i;

	(void)scene;
	i = 0;
	while (triangle[i])
	{
		free(triangle[i]);
		triangle[i] = NULL;
		i++;
	}
	free(triangle[i]);
	triangle[i] = NULL;
	free(triangle);
	triangle = NULL;
}

void	ft_clean_cylinders(t_cylinder **cylinder)
{
	int i;

	i = 0;
	while (cylinder[i])
	{
		free(cylinder[i]);
		cylinder[i] = NULL;
		i++;
	}
	free(cylinder[i]);
	cylinder[i] = NULL;
	free(cylinder);
	cylinder = NULL;
}

void	ft_clean_memory(t_scene scene)
{
	ft_clean_cameras(scene.camera);
	ft_clean_lights(scene.light);
	ft_clean_spheres(scene, scene.sphere);
	ft_clean_planes(scene, scene.plane);
	ft_clean_squares(scene, scene.square);
	ft_clean_triangles(scene, scene.triangle);
	ft_clean_cylinders(scene.cylinder);
}
