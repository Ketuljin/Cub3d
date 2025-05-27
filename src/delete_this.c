#include <stdio.h>
#include <stdbool.h>
#include "../include/cub3d.h"

void display_map_content(t_map *map)
{
    printf("=== MAP STRUCTURE ===\n");
    printf("sizeL: %d\n", map->sizeL);
    printf("valid_content: %s\n", map->valid_content ? "true" : "false");
    printf("north: %s\n", map->north ? map->north : "NULL");
    printf("south: %s\n", map->south ? map->south : "NULL");
    printf("east: %s\n", map->east ? map->east : "NULL");
    printf("west: %s\n", map->west ? map->west : "NULL");
    printf("floor: %s\n", map->floor ? map->floor : "NULL");
    printf("floor_color: %d\n", map->floor_color);
    printf("ceiling: %s\n", map->ceiling ? map->ceiling : "NULL");
    printf("ceiling_color: %d\n", map->ceiling_color);
    printf("initial_position: %c\n", map->initial_position);
    printf("initial_posX: %d\n", map->initial_posX);
    printf("initial_posY: %d\n", map->initial_posY);
    printf("map_width: %d\n", map->map_width);
    printf("i: %d\n", map->i);

    // printf("\nMap content:\n");
    // if (map->content)
    // {
    //     for (int i = 0; map->content[i]; i++)
    //     {
    //         printf("%s\n", map->content[i]);
    //     }
    // }
    // else
    // {
    //     printf("NULL\n");
    // }
    printf("=====================\n\n");
}

void display_ray_content(t_ray *ray)
{
    printf("=== RAY STRUCTURE ===\n");
    printf("camera_x: %f\n", ray->camera_x);
    printf("dir_x: %f\n", ray->dir_x);
    printf("dir_y: %f\n", ray->dir_y);
    printf("map_x: %d\n", ray->map_x);
    printf("map_y: %d\n", ray->map_y);
    printf("step_x: %d\n", ray->step_x);
    printf("step_y: %d\n", ray->step_y);
    printf("sidedist_x: %f\n", ray->sidedist_x);
    printf("sidedist_y: %f\n", ray->sidedist_y);
    printf("deltadist_x: %f\n", ray->deltadist_x);
    printf("deltadist_y: %f\n", ray->deltadist_y);
    printf("wall_dist: %f\n", ray->wall_dist);
    printf("wall_x: %f\n", ray->wall_x);
    printf("side: %d\n", ray->side);
    printf("line_height: %d\n", ray->line_height);
    printf("draw_start: %d\n", ray->draw_start);
    printf("draw_end: %d\n", ray->draw_end);
    printf("=====================\n\n");
}

void display_player_content(t_player *player)
{
    printf("=== PLAYER STRUCTURE ===\n");
    printf("dir: %c\n", player->dir);
    printf("pos_x: %f\n", player->pos_x);
    printf("pos_y: %f\n", player->pos_y);
    printf("dir_x: %f\n", player->dir_x);
    printf("dir_y: %f\n", player->dir_y);
    printf("plane_x: %f\n", player->plane_x);
    printf("plane_y: %f\n", player->plane_y);
    printf("has_moved: %d\n", player->has_moved);
    printf("move_x: %d\n", player->move_x);
    printf("move_y: %d\n", player->move_y);
    printf("rotate: %d\n", player->rotate);
    printf("=======================\n\n");
}

void display_structures(t_map *map, t_ray *ray, t_player *player)
{
    if (map)
        display_map_content(map);
    else
        printf("Map structure is NULL\n");

    if (ray)
        display_ray_content(ray);
    else
        printf("Ray structure is NULL\n");

    if (player)
        display_player_content(player);
    else
        printf("Player structure is NULL\n");
}
