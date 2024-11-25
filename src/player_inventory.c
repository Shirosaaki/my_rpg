/*
** EPITECH PROJECT, 2024
** player_inventory
** File description:
** oui
*/
#include "../include/my.h"

inventory_t *create_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    inventory_t *tmp = NULL;

    inventory->weapon = create_weapon("./assets/sprites_inven/marteau1.png",
        10, 0, 0);
    sfSprite_setScale(inventory->weapon->sprite, (sfVector2f){0.1, 0.1});
    inventory->next = NULL;
    return inventory;
}

void next_disp_inventory(inventory_t *inventory, game_t *game,
    sfVector2f pos, inventory_t *tmp)
{
    while (tmp != NULL) {
        sfSprite_setPosition(tmp->weapon->sprite, (sfVector2f)
            {pos.x + 520, pos.y - 75});
        pos = (sfVector2f){pos.x + 85, pos.y};
        sfRenderWindow_drawSprite(game->window, tmp->weapon->sprite, NULL);
        tmp = tmp->next;
    }
}

void display_inventory(inventory_t *inventory, game_t *game)
{
    inventory_t *tmp = inventory;
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f player_position = sfSprite_getPosition(game->player->sprite);
    sfVector2f pos = {player_position.x - 250, player_position.y - 75};
    sfVector2f xp_bar_pos = {pos.x, pos.y + 0};

    display_xp_bar(game, xp_bar_pos);
    display_health_bar(game, xp_bar_pos);
    display_image1(game, player_position);
    display_image2(game, player_position);
    display_quest(game, player_position);
    next_disp_inventory(inventory, game, pos, tmp);
}
