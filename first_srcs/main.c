#include "life.h"

static int	is_pos_digit(char *argv)
{
	int i = 0;

	while (argv[i] != '\0')
	{
		if (isdigit(argv[i]) == 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 3 && is_pos_digit(argv[2]) == TRUE)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		if (read_file(argv[1], data) == ERROR)
			return (0);
		game_of_life(data, atoi(argv[2]));
		ft_free2d(data->map);
		ft_free2d(data->temp);
		free (data);
	}
	else
		printf("Usage: ./life maps/initial_state iterations\n");
	return (0);
}
