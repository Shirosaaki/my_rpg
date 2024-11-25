/*
** EPITECH PROJECT, 2024
** inventaire2
** File description:
** oui
*/

#include "../include/my.h"

void display_xp_bar(game_t *game, sfVector2f pos)
{
    sfRectangleShape *xp_bar = sfRectangleShape_create();
    float scale_factor = 18.5;
    sfVector2f size = {game->player->xp * scale_factor, 10};

    pos.x += 520;
    pos.y -= 125;
    sfRectangleShape_setSize(xp_bar, size);
    sfRectangleShape_setFillColor(xp_bar, sfBlue);
    sfRectangleShape_setPosition(xp_bar, pos);
    sfRenderWindow_drawRectangleShape(game->window, xp_bar, NULL);
    sfRectangleShape_destroy(xp_bar);
}

void display_health_bar(game_t *game, sfVector2f pos)
{
    sfRectangleShape *health_bar = sfRectangleShape_create();
    float scale_factor = 1.7;
    sfVector2f size = {game->player->life * scale_factor, 10};

    pos.x += 520;
    pos.y -= 110;
    sfRectangleShape_setSize(health_bar, size);
    sfRectangleShape_setFillColor(health_bar, sfRed);
    sfRectangleShape_setPosition(health_bar, pos);
    sfRenderWindow_drawRectangleShape(game->window, health_bar, NULL);
    sfRectangleShape_destroy(health_bar);
}

void display_image1(game_t *game, sfVector2f player_position)
{
    sfSprite* image = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile
        ("assets/InventoryMasterclass.png", NULL);
    sfVector2f new_position = {player_position.x -
        -250, player_position.y - 200};
    sfVector2f scale = {2.5, 2.5};

    sfSprite_setTexture(image, texture, sfTrue);
    sfSprite_setPosition(image, new_position);
    sfSprite_setScale(image, scale);
    sfRenderWindow_drawSprite(game->window, image, NULL);
    sfSprite_destroy(image);
    sfTexture_destroy(texture);
}

void display_image2(game_t *game, sfVector2f player_position)
{
    sfSprite* image = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile
    ("assets/BetterMission.png", NULL);
    sfVector2f new_position = {player_position.x -
    150, player_position.y - 200};
    sfVector2f scale = {2.2, 2.2};

    sfSprite_setTexture(image, texture, sfTrue);
    sfSprite_setPosition(image, new_position);
    sfSprite_setScale(image, scale);
    sfRenderWindow_drawSprite(game->window, image, NULL);
    sfSprite_destroy(image);
    sfTexture_destroy(texture);
}

int display_quest(game_t *game, sfVector2f player_position)
{
    sfSprite* image = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile
        ("assets/MissionPrincipale.png", NULL);
    sfVector2f new_position = {player_position.x -
        90, player_position.y - 50};
    sfVector2f scale = {1.5, 1.5};

    if (game->display_quest == 0)
        return 0;
    sfSprite_setTexture(image, texture, sfTrue);
    sfSprite_setPosition(image, new_position);
    sfSprite_setScale(image, scale);
    sfRenderWindow_drawSprite(game->window, image, NULL);
    sfSprite_destroy(image);
    sfTexture_destroy(texture);
    return 0;
}
