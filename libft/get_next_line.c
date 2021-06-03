#include "libft.h"

int     break_exists(char *buffer)
{
    int i = 0;

    while (buffer[i])
    {
        if (buffer[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char   *save_updt(char *save, char *buffer)
{
    char *tmp;

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


// we'll need to store everything up to the line break (\n) inside *line
// and store anything that comes after the line break (\n) inside the static char save
// this way, if the get_next_line function is called repeatedly, like in a while loop,
// we'll make sure that nothing will be lost 
char    *line_updt(char **line, char *save, int r)
{
    int i = 0;
    int len;
    char *tmp;

    len = ft_strlen(save);
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
    if (i < len)
    {
        *line = ft_substr(save, 0, i);
        tmp = ft_substr(save, i + 1, len);
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


// read stores a string of buffer_size lenght ("a chunk") in buffer[]
// r will be the nb of bytes read with buffer_size, 0 if EOF was met, or -1 if error
// for each time read is applied, we'll store the "chunk" inside of save
// then, we'll check if there's a line break (\n) in the chunk
// if there is, we'll stop reading the file and transfer the save[] to *line[]
// if there's not, we'll continue reading and saving the file
int get_next_line(int fd, char **line)
{
    static char *save[4200];
    char buffer[BUFFER_SIZE + 1];
    int r;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (-1);

    // this loop will only stop if EOF is met (r = 0)
    // or there's a line break (\n) inside the chunk that has been read
    while ((r = read(fd, buffer, BUFFER_SIZE)))
    {
        if (r == -1)
            return (-1);
        buffer[r] = '\0';
        save[fd] = save_updt(save[fd], buffer);
        if (break_exists(buffer))
            break ;
    }

    // update line for empty files
    // EOF met without anything read
    if (r == 0 && !save[fd])
    {
        *line = ft_strdup("");
        return (0);
    }

    // printf("\n");
    // printf("r: %d\n", r);
    // printf("save: %s\n", save[fd]);

    // update save and line
    save[fd] = line_updt(line, save[fd], r);

    // printf("save: %s\n", save[fd]);
    // printf("line: %s\n", *line);

    // condition for EOF met
    // there was not a line break (\n) inside the file, but text was read
    if (r == 0 && !save[fd])
        return (0);

    return (1);
}

// int main(void)
// {
//     int fd;
//     char **line;

//     fd = open("ex.txt", O_RDONLY);

//     while (get_next_line(fd, line) > 0)
//         printf("%s", *line);
//     printf("%s\n", *line);

//     return (0);
// }