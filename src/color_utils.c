#include "minirt.h"

t_obj_color	ft_disruption(t_light *light, t_obj_color obj)
{
	(void)light;
	obj.light = ft_parallel_light(light, obj);
	return (obj);
}
