/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   main.c :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: racinedelarbre <racinedelarbre@student.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2023/03/10 14:32:17 by nchebbi   #+##+# */
/*   Updated: 2024/05/25 18:03:00 by racinedelar  ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
