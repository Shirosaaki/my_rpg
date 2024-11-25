/*
** EPITECH PROJECT, 2024
** anim
** File description:
** anim
*/
#include "../include/my.h"

void anim_p(player_t *player, int top)
{
    player->rect.top = top;
    player->rect.left += 64;
    if (player->rect.left >= 570)
        player->rect.left = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void anim_death(player_t *player)
{
    player->rect.top = 1226 + 64;
    player->rect.left += 64;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void anim_end(player_t *player, game_t *game)
{
    player->rect.top = 1640;
    player->rect.left += 128;
    if (player->rect.left >= 768)
        game->n = 90;
    sfSprite_setTextureRect(player->sprite, player->rect);
}
