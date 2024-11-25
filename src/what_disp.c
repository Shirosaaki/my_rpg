/*
** EPITECH PROJECT, 2024
** disp
** File description:
** disp
*/
#include "../include/my.h"

void destroy_title(sfTexture *texture, sfSprite *sprite)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

sfSprite *where_disp_hamer(game_t *game, sfSprite *sprite)
{
    if (game->select == 0)
        sfSprite_setPosition(sprite, (sfVector2f){500, 275});
    if (game->select == 1)
        sfSprite_setPosition(sprite, (sfVector2f){500, 350});
    if (game->select == 2)
        sfSprite_setPosition(sprite, (sfVector2f){500, 425});
    if (game->select == 3)
        sfSprite_setPosition(sprite, (sfVector2f){500, 500});
    return sprite;
}

void disp_title_screen(sfRenderWindow *window, game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("assets/menu.jpg",
        NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture2 = sfTexture_createFromFile("assets/hamer.png",
        NULL);
    sfSprite *sprite2 = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.75, 0.75});
    sfSprite_setPosition(sprite, (sfVector2f){-35, 0});
    sfSprite_setScale(sprite2, (sfVector2f){0.125, 0.125});
    sprite2 = where_disp_hamer(game, sprite2);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite2, NULL);
    destroy_title(texture, sprite);
    destroy_title(texture2, sprite2);
}

void draw_map(sfRenderWindow *window, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path,
        NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){2, 2});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void what_disp(game_t *game)
{
    if (game->n >= 84 && game->n < 999)
        return end_game(game);
    if (game->n >= 999)
        return dead(game);
    if (game->n == 0)
        disp_title_screen(game->window, game);
    if (game->n == 1) {
        sfView_setCenter(game->view,
            (sfVector2f){sfSprite_getPosition(game->player->sprite).x + 27,
            sfSprite_getPosition(game->player->sprite).y + 27});
        sfRenderWindow_drawSprite(game->window, game->map_disp, NULL);
        sfRenderWindow_setView(game->window, game->view);
        sfRenderWindow_drawSprite(game->window, game->png[1]->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
		if (game->n == 11 && game->ennemy[0]->is_alive == true) 
			sfRenderWindow_drawSprite(game->window, game->ennemy[0]->sprite, NULL);
		if (game->n == 8 && game->ennemy[1]->is_alive == true)
			sfRenderWindow_drawSprite(game->window, game->ennemy[1]->sprite, NULL);
		if (game->n == 5 && game->ennemy[2]->is_alive == true)
			sfRenderWindow_drawSprite(game->window, game->ennemy[2]->sprite, NULL);
        if (game->disp_inventory == 1)
            display_inventory(game->player->inventory, game);
        if (game->disp_dialog != 0)
            display_dialog(game->png[1], game);
    }
    next_what_disp(game);
}
