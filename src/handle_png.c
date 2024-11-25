/*
** EPITECH PROJECT, 2024
** create_png
** File description:
** create_png
*/
#include "../include/my.h"

void quest(game_t *game)
{
    sfMusic_setVolume(game->music, 10);
    game->quete = sfMusic_createFromFile("assets/musiques/quete.ogg");
    sfMusic_play(game->quete);
    game->disp_dialog = 0;
    game->can_move = 1;
    game->display_quest = 1;
    game->clock = sfClock_create();
}

png_t *create_png(char *path, sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
    png_t *png = malloc(sizeof(png_t));

    png->texture = sfTexture_createFromFile(path, NULL);
    png->sprite = sfSprite_create();
    png->pos = pos;
    png->rect = rect;
    png->dialog = NULL;
    sfSprite_setScale(png->sprite, scale);
    sfSprite_setTexture(png->sprite, png->texture, sfTrue);
    sfSprite_setPosition(png->sprite, png->pos);
    return png;
}

int get_distance(png_t *png, game_t *game)
{
    int x = sfSprite_getPosition(png->sprite).x -
        sfSprite_getPosition(game->player->sprite).x;
    int y = sfSprite_getPosition(png->sprite).y -
        sfSprite_getPosition(game->player->sprite).y;

    return sqrt(pow(x, 2) + pow(y, 2));
}

void next_interact_with_png(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace && game->disp_dialog == 1)
            quest(game);
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace && game->disp_dialog == 7)
            return quest(game);
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace && game->disp_dialog <= 6
        && game->disp_dialog >= 3 && game->png[1]->dialog->next != NULL) {
            game->png[1]->dialog = game->png[1]->dialog->next;
            game->disp_dialog += 1;
    }
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace && game->disp_dialog <= 6
        && game->disp_dialog >= 3 && game->png[1]->dialog->next == NULL) {
            game->disp_dialog = 0;
            game->can_move = 1;
    }
}

int interact_with_png(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyE &&
        get_distance(game->png[0], game) <= 127 && game->n == 2) {
        if (game->png[0]->dialog != NULL) {
            game->disp_dialog = 1;
            game->can_move = 0;
        }
        return 1;
    }
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyE &&
        get_distance(game->png[1], game) <= 50 && game->n == 1) {
        if (game->png[1]->dialog != NULL) {
            game->disp_dialog = 3;
            game->can_move = 0;
        }
        return 1;
    }
    next_interact_with_png(game);
    return 0;
}
