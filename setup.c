/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:56:04 by tordner           #+#    #+#             */
/*   Updated: 2024/12/13 17:24:40 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    start_window(t_data *data)
{
    
}

void    mlx_setup(t_data *data)
{
    // data->mlx = mlx_init();
    // data->win = mlx_new_window(data->mlx, 1080, 1920, "so_long");
}

int map_setup(t_data *data, char *file)
{
    int     fd;
    char    buf[2048];
    int     size;
    
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (write(1, "Error: invalid file\n", 20), 1);
    size = read(fd, buf, sizeof(buf));
    close(fd);
    buf[size] = '\0';
    data->dup_map = ft_split(buf, '\n');
    data->map = ft_split(buf, '\n');
    int i = 0;
    return (0);
}

int data_setup(t_data *data, char *file)
{
    data = malloc(sizeof(t_data));
    data->count_exit = 0;
    data->count_entrance = 0;
    data->count_collectible = 0;
    if (!data)
        return (1);
    if (map_setup(data, file))
        return (1);
    mlx_setup(data);
    if (check_map(data))
        return (1);
    return (0);
}