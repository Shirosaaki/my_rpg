/*
** EPITECH PROJECT, 2024
** where tp
** File description:
** where tp
*/
#include "../include/my.h"

static void end_tp(game_t *game, int tp)
{
    if (tp == 2 && game->n == 10) {
        game->n = 11;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/ThirdCaveTerre.png");
        load_map(game, "assets/maps/map5.3", (sfVector2f){99, 185},
            (sfVector2f){198, 198});
        game->player->pos.x -= 48;
        game->player->pos.y -= 35;
    }
}

static void again_next_tp(game_t *game, int tp)
{
    if (tp == 4 && game->n == 1) {
        game->n = 9;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/FirstCaveTerre.png");
        load_map(game, "assets/maps/map5", (sfVector2f){58, 127},
            (sfVector2f){128, 128});
        game->player->pos.x -= 48;
    }
    if (tp == 1 && game->n == 9) {
        game->n = 10;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/SecondCaveTerre.png");
        load_map(game, "assets/maps/map5.2", (sfVector2f){58, 127},
            (sfVector2f){128, 128});
        game->player->pos.x -= 48;
        game->player->pos.y -= 35;
    }
    end_tp(game, tp);
}

void again_tp(game_t *game, int tp)
{
    if (tp == 4 && game->n == 6) {
        game->n = 7;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/SecondCaveEau.png");
        load_map(game, "assets/maps/map4.2", (sfVector2f){1, 50},
            (sfVector2f){128, 128});
        game->player->pos.x -= 48;
    }
    if (tp == 5 && game->n == 7) {
        game->n = 8;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/ThirdCaveEau.png");
        load_map(game, "assets/maps/map4.3", (sfVector2f){1, 82},
            (sfVector2f){198, 198});
        game->player->pos.x -= 48;
        game->player->pos.y -= 35;
    }
    again_next_tp(game, tp);
}

void next_next_tp(game_t *game, int tp)
{
    if (tp == 4 && game->n == 4) {
        game->n = 5;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/ThirdCaveLave.png");
        load_map(game, "assets/maps/map3.3", (sfVector2f){191, 96},
            (sfVector2f){192, 192});
        game->player->pos.x -= 40;
        game->player->pos.y -= 35;
    }
    if (tp == 3 && game->n == 1) {
        game->n = 6;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/FirstCaveEau.png");
        load_map(game, "assets/maps/map4", (sfVector2f){5, 65},
            (sfVector2f){128, 128});
        game->player->pos.x -= 48;
        game->player->pos.y -= 35;
    }
    again_tp(game, tp);
}

void next_tp(game_t *game, int tp)
{
    if (tp == 2 && game->n == 1) {
        game->n = 3;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/FirstCaveLave.png");
        load_map(game, "assets/maps/map3", (sfVector2f){127, 58},
            (sfVector2f){128, 128});
        game->player->pos.x -= 48;
        game->player->pos.y -= 35;
    }
    if (tp == 3 && game->n == 3) {
        game->n = 4;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/SecondCaveLave.png");
        load_map(game, "assets/maps/map3.2", (sfVector2f){126, 58},
            (sfVector2f){128, 128});
        game->player->pos.x -= 48;
        game->player->pos.y -= 35;
    }
    next_next_tp(game, tp);
}

void tp_player(game_t *game, char direction)
{
    int tp = can_tp(game);

    sfSprite_setPosition(game->player->sprite, game->player->pos);
    if (tp == 1 && game->n == 1) {
        game->n = 2;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/map2.png");
        load_map(game, "map2", (sfVector2f){6, 1}, (sfVector2f){200, 3});
        game->player->pos = (sfVector2f){50, -16};
    }
    if (tp == 0 && game->n == 2) {
        game->n = 1;
        game->previous_scene = game->n;
        load_map_disp(game, "assets/maps/map.png");
        load_map(game, "map.txt", (sfVector2f){13, 1}, (sfVector2f){320, 320});
        game->player->pos = (sfVector2f){20, -48};
    }
    next_tp(game, tp);
}

int can_tp(game_t *game)
{
    int tp = -1;

    if (game->map[game->py][game->px] >= '0' &&
        game->map[game->py][game->px] <= '9')
        tp = game->map[game->py][game->px] - '0';
    return tp;
}
