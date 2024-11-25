/*
** EPITECH PROJECT, 2024
** pause
** File description:
** oui
*/

#include "../include/my.h"

static void button_function(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
        if (game->select == 0) {
            game->is_paused = 0;
        }
        if (game->select == 1) {
            game->is_paused = 0;
            game->n = 0;
            game->previous_scene = game->n;
            sfMusic_stop(game->music);
            game->music = sfMusic_createFromFile("assets/musiques/menu.ogg");
            sfMusic_play(game->music);
            sfMusic_setLoop(game->music, sfTrue);
            resize_event(game);
            game->select = 0;
        }
        if (game->select == 2) {
            sfRenderWindow_close(game->window);
        }
    }
}

void handle_input(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        game->select++;
        if (game->select == 3)
            game->select = 0;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        game->select--;
        if (game->select == -1)
            game->select = 2;
    }
    button_function(game, event);
}

void move_sprite(game_t *game, sfSprite *sprite, int direction)
{
    sfVector2f player_position = sfSprite_getPosition(game->player->sprite);

    if (game->select == 0)
        sfSprite_setPosition(sprite, (sfVector2f){player_position.x - 320,
            player_position.y + -22.5});
    if (game->select == 1)
        sfSprite_setPosition(sprite, (sfVector2f){player_position.x - 72.5,
            player_position.y + -22.5});
    if (game->select == 2)
        sfSprite_setPosition(sprite, (sfVector2f){player_position.x + 175,
            player_position.y + -22.5});
}

sfTexture* create_texture(sfSprite
    **sprite, const char *file_path)
{
    sfTexture *texture = sfTexture_createFromFile(file_path, NULL);

    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    return texture;
}

void set_sprite_properties(game_t *game, sfSprite *sprite)
{
    sfVector2f player_position = sfSprite_getPosition(game->player->sprite);
    sfVector2f pause_position = (sfVector2f){player_position.x -
        425, player_position.y - 225};
    sfVector2f pause_size = (sfVector2f){7.5, 7.5};

    sfSprite_setPosition(sprite, pause_position);
    sfSprite_setScale(sprite, pause_size);
}

void disp_pausemenu(game_t *game)
{
    sfSprite *sprite1;
    sfSprite *sprite2;
    sfTexture *texture1;
    sfTexture *texture2;

    if (game->disp_inventory == 1)
        display_inventory(game->player->inventory, game);
    if (game->is_paused == 1) {
        texture1 = create_texture(&sprite1, "assets/withparchemin.png");
        texture2 = create_texture(&sprite2, "assets/selected.png");
        set_sprite_properties(game, sprite1);
        set_sprite_properties(game, sprite2);
        move_sprite(game, sprite2, 10);
        sfRenderWindow_drawSprite(game->window, sprite1, NULL);
        sfRenderWindow_drawSprite(game->window, sprite2, NULL);
        sfTexture_destroy(texture1);
        sfSprite_destroy(sprite1);
        sfTexture_destroy(texture2);
        sfSprite_destroy(sprite2);
    }
}
