#include "get_next_line.h"
#include <stdio.h>

static char	*readline(char *str)
{
	int	i;
	char	*ret;

	i = 0;
	if (!(ft_strlen(str))){
		return (NULL);}
	while (str[i] && str[i] != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static	char	*free_join(char	*s1, char *s2)
{
	char	*tmp;
	char	*ret;

	tmp = s1;
	ret = ft_strjoin(s1, s2);
	(tmp) ? free(tmp) : 0;
	return (ret);
}



static	int	reader(int fd, char **str)
{
	int	c;
	char	*rd;

	rd = ft_strnew(BUFF_SIZE);
	c = read(fd, rd, BUFF_SIZE);
	rd[c] = '\0';
	*str = free_join(*str, rd);
	(rd) ? free(rd) : 0;
	return (c);
}

static	char	*move(char *s)
{
	char	*old;
	char	*ret;

	old = s;
	ret = ft_strdup(ft_strchr(s, '\n') + 1);
	(old) ? free(old) : 0;
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	char		*check;
	int		c;

	check = NULL;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!str)
		str = ft_strnew(1);
	check = ft_strchr(str, '\n');
	while (check == NULL)
	{
		c = reader(fd, &str);
		if (c == 0)
		{
			if (!ft_strlen(str))
				return (0);
			str = free_join(str, "\n"); // the last char in the buff must be a new line
			check = ft_strchr(str, '\n');
		}
		else if (c == -1)
			return (-1);
		else
			check = ft_strchr(str, '\n');
	}
	*line = readline(str);
	str = move(str);
	return (1);
}
