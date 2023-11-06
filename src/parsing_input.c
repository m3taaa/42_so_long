#include "../header/so_long.h"

int     check_type_file(char *file)
{
        char *end_file;
        int     x;
        end_file = ft_substr(file, (ft_strlen(file)-4), 4);
        x = ft_strncmp(end_file, ".ber", ft_strlen(end_file));
        if (x != 0)
                return (-1);
        return (0);
}

int check_file(char *path_file)
{
        int fd;
        int check_file_extension;

        fd = open(path_file, O_RDONLY);
        if (fd == -1)
        {
                ft_printf("find not file\n");
                return (fd);
        }
        check_file_extension = check_type_file(path_file);
        if (check_file_extension == -1)
        {
                ft_printf("not good extension\n");
                return (-1);
        }
        return (fd);
}
