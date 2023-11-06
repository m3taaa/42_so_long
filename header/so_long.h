#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_and_more/libft_and_more.h"
#include <fcntl.h>

int		check_type_file(char *file);
int 	check_file(char *path_file);
int     check_content_file(int fd);

#endif
