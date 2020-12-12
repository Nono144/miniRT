#include "minirt.h"

static void	ft_assets(int option)
{
	int		fd;
	char	*line;

	if (option != 1)
	{
		fd = open("assets/help.txt", O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			ft_printf("%s\n", line);
			free(line);
		}
		ft_printf("%s\n", line);
		free(line);
		if (option == 2)
			exit(EXIT_SUCCESS);
	}
}
 
static void			ft_initialize_options(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < 14)
		scene->option[i] = 0;
}

static void			ft_save_option(char *argv, t_scene *scene)
{
	if (!ft_strncmp(argv, "--save", ft_strlen(argv) + 1))
	{
		if (scene->option[0])
			ft_error_handler(DOUBLE_FLAG);
		scene->option[0] = 1;
	}
	else
		ft_error_handler(BAD_FLAG);
}

static void			ft_check_options(int argc, char **argv, t_scene *scene)
{
	int	i;

	i = 1;
	while (++i < argc)
		ft_save_option(argv[i], scene);
}
int		main(int argc, char **argv)
{
	t_scene	scene;
	char	*aux;

	ft_assets(1);
	ft_initialize_options(&scene);
	if (argc > 1 && (aux = ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
			&& (*(aux + 3)) == 0)
	{
		scene.window.mlx_ptr = mlx_init();
		ft_check_options(argc, argv, &scene);
		ft_load_scene(argv[1], &scene);
		if (scene.option[0])
			ft_scene_to_bmp(scene);
		else
			ft_minirt(scene);
	}
	else
		ft_error_handler(1);
	ft_clean_memory(scene);
	return (0);
}
