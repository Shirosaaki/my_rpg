/*
** EPITECH PROJECT, 2024
** dead
** File description:
** dead
*/
#include "../include/my.h"


static void action(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
        if (game->select == 1)
            sfRenderWindow_close(game->window);
        if (game->select == 0) {
            game->is_paused = 0;
            game->n = 0;
            sfMusic_stop(game->music);
            game->music = sfMusic_createFromFile("assets/musiques/menu.ogg");
            sfMusic_play(game->music);
            sfMusic_setLoop(game->music, sfTrue);
            resize_event(game);
            load_map_disp(game, "assets/menu.jpg");
            game->select = 0;
            game->player->life = 100;
        }
    }
}

void handle_input2(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        game->select++;
        if (game->select == 2)
            game->select = 0;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        game->select--;
        if (game->select == -1)
            game->select = 1;
    }
    action(game, event);
}

void move_sprite2(game_t *game, sfSprite *sprite)
{
    if (game->select == 0)
        sfSprite_setPosition(sprite, (sfVector2f){425, 395});
    if (game->select == 1)
        sfSprite_setPosition(sprite, (sfVector2f){715, 395});
}

void cursor(game_t *game)
{
    sfSprite *sprite2;
    sfTexture *texture2;

    texture2 = create_texture(&sprite2, "assets/selected.png");
    set_sprite_properties(game, sprite2);
    move_sprite2(game, sprite2);
    sfRenderWindow_drawSprite(game->window, sprite2, NULL);
    sfTexture_destroy(texture2);
    sfSprite_destroy(sprite2);
    if (game->disp_inventory == 1)
        display_inventory(game->player->inventory, game);
    if (game->is_paused == 1) {
        texture2 = create_texture(&sprite2, "assets/selected.png");
        set_sprite_properties(game, sprite2);
        move_sprite2(game, sprite2);
        sfRenderWindow_drawSprite(game->window, sprite2, NULL);
        sfTexture_destroy(texture2);
        sfSprite_destroy(sprite2);
    }
}

void dead(game_t *game)
{
    if (game->n == 999) {
        load_map_disp(game, "assets/death.png");
        sfSprite_setPosition(game->map_disp, (sfVector2f){180, 95});
        sfSprite_setScale(game->map_disp, (sfVector2f){5.9, 5.9});
        game->player->pos = (sfVector2f){0, 0};
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        sfView_setCenter(game->view, (sfVector2f){640, 360});
        sfRenderWindow_setView(game->window, game->view);
        game->n++;
    }
    sfSprite_setScale(game->player->sprite, (sfVector2f){1, 1});
    sfView_setCenter(game->view, (sfVector2f){640, 360});
    sfRenderWindow_drawSprite(game->window, game->map_disp, NULL);
    sfRenderWindow_setView(game->window, game->view);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    cursor(game);
    return;
}
