#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 32

int	get_next_line(int fd, char **line);

#endif
