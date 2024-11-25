/*
** EPITECH PROJECT, 2024
** load
** File description:
** load
*/
#include "../include/my.h"

void load_map(game_t *game, char *path, sfVector2f pos, sfVector2f size)
{
    int fd = open(path, O_RDONLY);
    char *buffer = malloc(sizeof(char) * size.y * size.x + size.x);
    int i = 0;

    read(fd, buffer, size.y * size.x + size.x - 1);
    i = size.y * size.x + size.x;
    buffer[i] = '\0';
    game->map = my_str_to_word_array(buffer, '\n');
    game->px = pos.x;
    game->py = pos.y;
    sfSprite_setPosition(game->player->sprite,
        (sfVector2f){pos.x - 64, pos.y + 32});
    sfSprite_setOrigin(game->player->sprite, (sfVector2f){-32, -32});
    game->player->pos = (sfVector2f){pos.x * 780 / 160,
        pos.y * 780 / 160 - 32};
    close(fd);
    free(buffer);
}

void load_map_disp(game_t *game, char *path)
{
    game->map_disp_texture = sfTexture_createFromFile(path, NULL);
    game->map_disp = sfSprite_create();
    sfSprite_setTexture(game->map_disp, game->map_disp_texture, sfTrue);
    sfSprite_setScale(game->map_disp, (sfVector2f){2, 2});
}
