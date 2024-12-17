/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:09:39 by tordner           #+#    #+#             */
/*   Updated: 2024/12/14 17:12:21 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

FAIRE CHECK MAP RECTANGLE AVANT DE RENTRER CHECK LEFT TOP RIGHT BOT

int check_left_right_walls(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[0][j] != '\n')
        j++;
    while (data->map[i])
    {
        if (data->map[i][0] != '1')
            return (1);
        i++;
    }
    i = 0;
    while (data->map[i][j] != '\n')
    {
        if (data->map[0][j] != '1')
            return (1);
        i++;
    }
}

int check_top_bot_walls(t_data *data)
{
    int i;
    int j;

    j = 0;
    while (data->map[i])
        i++;
    while (data->map[0][j] != '\n')
    {
        if (data->map[0][j] != '1')
            return (1);
        j++;
    }
    j = 0;
    while (data->map[i][j] != '\n')
    {
        if (data->map[0][j] != '1')
            return (1);
        j++;
    }
}

int check_special_characters_map(t_data *data)
{
    if (data->count_exit < 1 || data->count_entrance < 1
    || data->count_collectible < 1)
    {
        write(1, "Error: missing core ", 20);
        write(1, "gameplay element (exit/entrance/collectible)\n)", 45); 
        return (1);
    }
    if (data->count_exit > 1 || data->count_entrance > 1)
        return (write(1, "Error: too many exits or entrances\n", 35), 1);
    return (0);
}

int check_characters_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[i])
    {
        while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
        {
            if (data->map[i][j] != '0' && data->map[i][j] != '1'
            && data->map[i][j] != 'C' && data->map[i][j] != 'E'
            && data->map[i][j] != 'P')
                return (write(1, "Error: invalid map\n", 19), 1);
            if (data->map[i][j] == 'E')
                data->count_exit++;
            if (data->map[i][j] == 'P')
                data->count_entrance++;
            if (data->map[i][j] == 'C')
                data->count_collectible++;
            j++;
        }
        i++;
        j = 0;
    }
    return (0);
}

int check_map(t_data *data)
{
    if (check_characters_map(data) == 1
    || check_special_characters_map(data) == 1)
        return (1);
    return (0);
}
