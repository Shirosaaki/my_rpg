/*
** EPITECH PROJECT, 2024
** initialisation ennemy
** File description:
** initialisation ennemy
*/

#include "../include/my.h"

void player_fight(game_t *game)
{
    game->player->rect = (sfIntRect){0, 325, 65, 65};
    game->player->pos_fight = (sfVector2f){780, 700};
    game->ennemy[game->index_ennemy]->pos = (sfVector2f){300, 700};
    game->ennemy[game->index_ennemy]->rect = (sfIntRect){0, 100, 85, 95};
    sfSprite_setScale(game->player->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(game->player->sprite, game->player->pos_fight);
    sfSprite_setPosition(game->ennemy[game->index_ennemy]->sprite,
        game->ennemy[game->index_ennemy]->pos);
    game->ennemy[game->index_ennemy]->in_combat = false;
}

void anim_player(game_t *game)
{
    double seconds = sfClock_getElapsedTime(game->player\
        ->clock_attack).microseconds / 1000000.0;

    if (seconds > 0.1) {
        game->player->rect.left += 65;
        if (game->player->rect.left >= 385)
            game->player->rect.left = 0;
        sfClock_restart(game->player->clock_attack);
    }
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}

sfIntRect *init_rect_fight(void)
{
    sfIntRect *rect_fight = malloc(sizeof(sfIntRect) * 4);

    rect_fight[0] = (sfIntRect){675, 1515, 65, 65};
    rect_fight[1] = (sfIntRect){540, 1515, 65, 65};
    rect_fight[2] = (sfIntRect){150, 1515, 65, 65};
    rect_fight[3] = (sfIntRect){35, 1515, 65, 65};
    return rect_fight;
}

void attack_player(game_t *game)
{
    double seconds = sfClock_getElapsedTime(game->player->\
        clock_attack).microseconds / 1000000.0;

    game->player->rect.top = 584;
    if (seconds > 0.1 && game->player->pos_fight.x >= 360) {
        anim_player(game);
        game->player->pos_fight.x -= 10;
        sfClock_restart(game->player->clock_attack);
    }
    next_attack_player(seconds, game);
    if (game->player->pos_fight.x >= 360)
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfSprite_setPosition(game->player->sprite, game->player->pos_fight);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}

void next_attack_player(double seconds, game_t *game)
{
    if (seconds > 0.1 && game->player->pos_fight.x <= 360) {
        game->player->index_attack++;
        if (game->player->index_attack == 3) {
            game->ennemy[game->index_ennemy]->life -= game->player->attack;
            printf("life = %d\n", game->ennemy[game->index_ennemy]->life);
            game->player->in_combat = false;
            game->player->rect = (sfIntRect){0, 325, 65, 65};
            game->player->pos_fight = (sfVector2f){780, 700};
            game->player->index_attack = -1;
            game->ennemy[game->index_ennemy]->is_attacking = true;
            game->ennemy[game->index_ennemy]->in_combat = true;
        }
        sfSprite_setTextureRect(game->player->sprite,
            game->player->rect_fight[game->player->index_attack]);
        sfClock_restart(game->player->clock_attack);
    }
}
