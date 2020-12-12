#ifndef CLEAN_H
# define CLEAN_H

# include "scene_types.h"

void	ft_release_textures(t_scene scene, t_bonus bonus);
void	ft_clean_memory(t_scene scene);
void	ft_clean_cameras(t_camera **camera);
void	ft_clean_lights(t_light **ligth);
void	ft_clean_spheres(t_scene scene, t_sphere **sphere);
void	ft_clean_planes(t_scene scene, t_plane **plane);
void	ft_clean_squares(t_scene scene, t_square **square);
void	ft_clean_triangles(t_scene scene, t_triangle **triangle);
void	ft_clean_cylinders(t_cylinder **cylinder);

#endif
