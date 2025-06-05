#include <stdio.h>
#include <stdbool.h>
#include "../include/cub3d.h"

void	print_game_state(t_game *game)
{
	printf("win_width: %d\n", game->win_width);
	printf("=== Map Info ===\n");
	printf("sizeL: %d\n", game->mapinfo.sizeL);
	printf("Valid Content: %s\n", game->mapinfo.valid_content ? "true" : "false");
	printf("North: %s\n", game->mapinfo.north);
	printf("South: %s\n", game->mapinfo.south);
	printf("East: %s\n", game->mapinfo.east);
	printf("West: %s\n", game->mapinfo.west);
	printf("Floor: %s\n", game->mapinfo.floor);
	printf("Floor Color: #%lx\n", game->mapinfo.floor_color);
	printf("Ceiling: %s\n", game->mapinfo.ceiling);
	printf("Ceiling Color: #%lx\n", game->mapinfo.ceiling_color);
	printf("Initial Position: %c at (%d, %d)\n", game->mapinfo.initial_position, game->mapinfo.initial_posX, game->mapinfo.initial_posY);
	printf("Map Width: %d, i: %d\n", game->mapinfo.map_width, game->mapinfo.i);

	if (game->mapinfo.content)
	{
		printf("Map Content:\n");
		for (int i = 0; game->mapinfo.content[i]; i++)
			printf("%s\n", game->mapinfo.content[i]);
	}

	printf("\n=== Player Info ===\n");
	printf("Direction: %c\n", game->player.dir);
	printf("Position: (%.2f, %.2f)\n", game->player.pos_x, game->player.pos_y);
	printf("Direction Vector: (%.2f, %.2f)\n", game->player.dir_x, game->player.dir_y);
	printf("Plane Vector: (%.2f, %.2f)\n", game->player.plane_x, game->player.plane_y);
	printf("Has Moved: %d, Move X: %d, Move Y: %d, Rotate: %d\n",
		game->player.has_moved, game->player.move_x, game->player.move_y, game->player.rotate);

	printf("\n=== Ray Info ===\n");
	printf("Camera X: %.2f\n", game->ray.camera_x);
	printf("Ray Dir: (%.2f, %.2f)\n", game->ray.dir_x, game->ray.dir_y);
	printf("Map Pos: (%d, %d)\n", game->ray.map_x, game->ray.map_y);
	printf("Step: (%d, %d)\n", game->ray.step_x, game->ray.step_y);
	printf("Side Dist: (%.2f, %.2f)\n", game->ray.sidedist_x, game->ray.sidedist_y);
	printf("Delta Dist: (%.2f, %.2f)\n", game->ray.deltadist_x, game->ray.deltadist_y);
	printf("Wall Dist: %.2f, Wall X: %.2f\n", game->ray.wall_dist, game->ray.wall_x);
	printf("Side: %d, Line Height: %d, Draw Start: %d, Draw End: %d\n",
		game->ray.side, game->ray.line_height, game->ray.draw_start, game->ray.draw_end);
}
