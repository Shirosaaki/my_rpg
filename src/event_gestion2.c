/*
** EPITECH PROJECT, 2024
** event2
** File description:
** oui
*/

#include "../include/my.h"

void handle_inventory_event(game_t *game)
{
    if (game->event.key.code == sfKeyI)
        game->disp_inventory = (game->disp_inventory == 0) ? 1 : 0;
}

void handle_xp_event(game_t *game)
{
    char xpStr[50];

    if (game->player->xp >= 10) {
        game->player->xp = 0;
        game->player->level += 1;
        printf("LEVEL UP = %d\n", game->player->level);
    }
    sprintf(xpStr, "XP: %d", game->player->xp);
    sfText_setString(game->player->xpText, xpStr);
}

void handle_life_event(game_t *game)
{
    char xpStr[50];

    if (game->event.key.code == sfKeyH) {
        game->player->life -= 10;
        if (game->player->life <= 0) {
            game->player->life = 0;
            printf("You are dead\n");
            game->player->rect.left = 0;
            game->player->count_death = 0;
            anim_death(game->player);
            game->can_move = 0;
        }
        sprintf(xpStr, "XP: %d", game->player->xp);
        sfText_setString(game->player->xpText, xpStr);
    }
}

void next_next_player_event_gestion(game_t *game)
{
    if (game->event.type != sfEvtKeyReleased)
        return;
    handle_inventory_event(game);
    handle_life_event(game);
}
