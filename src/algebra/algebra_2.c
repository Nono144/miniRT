#include "minirt.h"

double			ft_abs(double num)
{
	double n;

	n = num;
	if (num < 0)
		n = (-1 * num);
	return (n);
}

double			ft_mod_vector(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void			ft_normalize_vector(t_vector *v)
{
	double mod;

	mod = ft_mod_vector(*v);
	v->x = v->x / mod;
	v->y = v->y / mod;
	v->z = v->z / mod;
}

t_vector		ft_mtx_vct_prod(t_matrix m, t_vector v)
{
	t_vector p;

	p.x = v.x * m.vx.x + v.y * m.vy.x + v.z * m.vz.x;
	p.y = v.x * m.vx.y + v.y * m.vy.y + v.z * m.vz.y;
	p.z = v.x * m.vx.z + v.y * m.vy.z + v.z * m.vz.z;
	return (p);
}


double			ft_det(t_matrix m)
{
	double	det;

	det = (m.vx.x * m.vy.y * m.vz.z + m.vy.x * m.vz.y * m.vx.z
			+ m.vx.y * m.vy.z * m.vz.x) - (m.vx.z * m.vy.y * m.vz.x
			+ m.vy.x * m.vx.y * m.vz.z + m.vz.y * m.vy.z * m.vx.x);
	return (det);
}
