/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:21:00 by tordner           #+#    #+#             */
/*   Updated: 2024/12/13 17:20:32 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# define W 1920
# define H 1080

typedef struct s_data
{
    int     count_entrance;
    int     count_exit;
    int     count_collectible;
	void    *mlx;
    void    *win;
    char    **map;
    char    **dup_map;
}	t_data;

int		errors(int ac, char **av);
int     data_setup(t_data *data, char *file);
int     check_map(t_data *data);
char	**ft_split(char const *s, char c);
char    *ft_strdup(const char *src);


#endif