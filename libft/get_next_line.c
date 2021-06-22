#include "libft.h"

int	break_exists(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*save_updt(char *save, char *buffer)
{
	char	*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}

char	*line_updt(char **line, char *save, int r)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[4200];
	char		buffer[BUFFER_SIZE + 1];
	int			r;

	r = 1;
	while (r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (-1);
		buffer[r] = '\0';
		save[fd] = save_updt(save[fd], buffer);
		if (break_exists(buffer))
			break ;
	}
	if (r == 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	save[fd] = line_updt(line, save[fd], r);
	if (r == 0 && !save[fd])
		return (0);
	return (1);
}
