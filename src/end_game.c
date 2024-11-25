/*
** EPITECH PROJECT, 2024
** end
** File description:
** end
*/
#include "../include/my.h"

void other_other_end_game(game_t *game)
{
    if (game->n == 89) {
        sfView_setCenter(game->view, (sfVector2f){640, 360});
        game->n++;
    }
    if (game->n == 88) {
        sfView_setCenter(game->view, (sfVector2f){640, 360 + 20});
        game->n++;
    }
    if (game->n == 87) {
        game->player->rect = (sfIntRect){0, 650, 54, 54};
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
        game->n++;
    }
}

void other_end_game(game_t *game)
{
    if (game->n == 94) {
        sfView_setCenter(game->view, (sfVector2f){640, 360 + 10});
        game->n++;
    }
    if (game->n == 93) {
        sfView_setCenter(game->view, (sfVector2f){640, 360});
        game->n++;
    }
    if (game->n == 92) {
        sfView_setCenter(game->view, (sfVector2f){640, 360 - 10});
        game->n++;
    }
    if (game->n == 91) {
        sfView_setCenter(game->view, (sfVector2f){640, 360});
        game->n++;
    }
    if (game->n == 90) {
        sfView_setCenter(game->view, (sfVector2f){640, 360 - 20});
        game->n++;
    }
}

void next_next_end_game(game_t *game)
{
    if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
        if (game->n == 95) {
            load_map_disp(game, "assets/end.png");
            sfSprite_setScale(game->map_disp, (sfVector2f){1, 0.90});
            game->n++;
        }
        other_end_game(game);
        other_other_end_game(game);
        sfClock_restart(game->player->clock_anim);
    }
}

void next_end_game(game_t *game)
{
    if (game->player->pos.y < 400 && game->n == 85) {
        game->player->pos.y += 0.01;
        if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
            anim_p(game->player, 650);
            sfClock_restart(game->player->clock_anim);
        }
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    } else if (game->n == 85) {
        game->n = 86;
        game->player->rect.left = 40;
    }
    if (game->n == 86) {
        if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
            anim_end(game->player, game);
            sfClock_restart(game->player->clock_anim);
        }
    }
}

void end_game(game_t *game)
{
    if (game->n == 84) {
        game->can_move = 0;
        load_map_disp(game, "assets/end.jpg");
        sfSprite_setScale(game->map_disp, (sfVector2f){1, 0.90});
        game->player->pos = (sfVector2f){580, 320};
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        sfView_setCenter(game->view, (sfVector2f){640, 360});
        sfRenderWindow_setView(game->window, game->view);
        sfMusic_stop(game->music);
        game->music = sfMusic_createFromFile("assets/musiques/End.ogg");
        sfMusic_setLoop(game->music, sfTrue);
        sfMusic_play(game->music);
        game->n = 85;
    }
    next_end_game(game);
    next_next_end_game(game);
    sfRenderWindow_setView(game->window, game->view);
    sfRenderWindow_drawSprite(game->window, game->map_disp, NULL);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    return;
}
