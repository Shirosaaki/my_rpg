/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/
#include "../include/my.h"

void resize_event(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfFloatRect visibleArea = {0, 0, size.x, size.y};
    float zoom1 = 0.35f * 1280 / size.x;
    float zoom2 = 0.35f * 720 / size.y;

    sfView_reset(game->view, visibleArea);
    if (game->n != 0)
        sfView_zoom(game->view, (zoom1) + (zoom2));
    else
        sfView_setCenter(game->view, (sfVector2f){640, 360});
    sfRenderWindow_setView(game->window, game->view);
}

void next_next_event_gestion_menu(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyReturn) {
        if (game->select == 0) {
            game->n = 1;
            game->previous_scene = game->n;
            sfMusic_stop(game->music);
            game->music = sfMusic_createFromFile("assets/musiques/map.ogg");
            sfMusic_setLoop(game->music, sfTrue);
            sfMusic_play(game->music);
            load_map_disp(game, "assets/maps/map.png");
            load_map(game, "map.txt", (sfVector2f){160, 160},
                (sfVector2f){320, 320});
            game->px = 165;
            resize_event(game);
        }
        if (game->select == 3)
            sfRenderWindow_close(game->window);
    }
}

void next_event_gestion_menu(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyDown) {
        game->select++;
        if (game->select == 4)
            game->select = 0;
    }
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyUp) {
        game->select--;
        if (game->select == -1)
            game->select = 3;
    }
    next_next_event_gestion_menu(game);
}

void next_player_event_gestion(game_t *game)
{
    next_next_player_event_gestion(game);
    if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
        10000000)
        sfMusic_setVolume(game->music, 100);
}
