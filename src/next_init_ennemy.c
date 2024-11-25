/*
** EPITECH PROJECT, 2024
** next
** File description:
** next
*/
#include "../include/my.h"

static void next_init_ennemy(ennemy_t *init_ennemy)
{
    init_ennemy->rect_hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(init_ennemy->rect_hitbox,
        init_ennemy->hitbox_size);
    sfRectangleShape_setFillColor(init_ennemy->rect_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(init_ennemy->rect_hitbox, 1);
    sfRectangleShape_setOutlineColor(init_ennemy->rect_hitbox, sfRed);
    sfRectangleShape_setPosition(init_ennemy->rect_hitbox, init_ennemy->pos);
}

ennemy_t *init_ennemy(char *path_asset, sfVector2f pos_ennemy,
    sfIntRect rect_ennemy, sfVector2f scale)
{
    ennemy_t *init_ennemy = malloc(sizeof(ennemy_t));

    init_ennemy->attack = 10;
    init_ennemy->pos = pos_ennemy;
    init_ennemy->rect = rect_ennemy;
    init_ennemy->in_combat = false;
    init_ennemy->life = 50;
    init_ennemy->sprite = sfSprite_create();
    init_ennemy->texture = sfTexture_createFromFile(path_asset, NULL);
    init_ennemy->clock_anim = sfClock_create();
    init_ennemy->hitbox_size = (sfVector2f){rect_ennemy.width * scale.x,
        rect_ennemy.height * scale.y};
    init_ennemy->is_alive = true;
    init_ennemy->is_attacking = false;
    sfSprite_setTexture(init_ennemy->sprite, init_ennemy->texture, sfTrue);
    sfSprite_setTextureRect(init_ennemy->sprite, init_ennemy->rect);
    sfSprite_setPosition(init_ennemy->sprite, init_ennemy->pos);
    sfSprite_setScale(init_ennemy->sprite, (sfVector2f){scale.x, scale.y});
    next_init_ennemy(init_ennemy);
    return init_ennemy;
}

void anim_ennemy(game_t *game)
{
    double seconds = sfClock_getElapsedTime(game->ennemy[game->index_ennemy]\
        ->clock_anim).microseconds / 1000000.0;

    if (seconds > 0.1) {
        game->ennemy[game->index_ennemy]->rect.left += 85;
        if (game->ennemy[game->index_ennemy]->rect.left >= 295)
            game->ennemy[game->index_ennemy]->rect.left = 0;
        sfClock_restart(game->ennemy[game->index_ennemy]->clock_anim);
    }
    sfSprite_setTextureRect(game->ennemy[game->index_ennemy]->sprite,
        game->ennemy[game->index_ennemy]->rect);
    sfRenderWindow_drawSprite(game->window,
        game->ennemy[game->index_ennemy]->sprite, NULL);
}

void attack_ennemy(game_t *game)
{
    double seconds = sfClock_getElapsedTime(game->ennemy[game->index_ennemy]\
        ->clock_anim).microseconds / 1000000.0;

    if (seconds > 0.1 && game->ennemy[game->index_ennemy]->pos.x <= 750) {
        anim_ennemy(game);
        game->ennemy[game->index_ennemy]->pos.x += 10;
        sfClock_restart(game->ennemy[game->index_ennemy]->clock_anim);
    }
    if (game->ennemy[game->index_ennemy]->pos.x == 750){
        game->ennemy[game->index_ennemy]->rect = (sfIntRect){0, 200, 85, 95};
        game->ennemy[game->index_ennemy]->pos.x = 751;
    }
    next_attack_ennemy(seconds, game);
    sfSprite_setPosition(game->ennemy[game->index_ennemy]->sprite,
        game->ennemy[game->index_ennemy]->pos);
    sfSprite_setTextureRect(game->ennemy[game->index_ennemy]->sprite,
        game->ennemy[game->index_ennemy]->rect);
    sfRenderWindow_drawSprite(game->window,
        game->ennemy[game->index_ennemy]->sprite, NULL);
}

void next_attack_ennemy(double seconds, game_t *game)
{
    if (seconds > 0.1 && game->ennemy[game->index_ennemy]->pos.x == 751) {
        game->ennemy[game->index_ennemy]->rect.left += 85;
        if (game->ennemy[game->index_ennemy]->rect.left >= 295) {
            game->player->life -= game->ennemy[game->index_ennemy]->attack;
            printf("life = %d\n", game->player->life);
            game->ennemy[game->index_ennemy]->in_combat = false;
            game->ennemy[game->index_ennemy]->is_attacking = false;
            game->ennemy[game->index_ennemy]->rect =
                (sfIntRect){0, 100, 85, 95};
            game->ennemy[game->index_ennemy]->pos = (sfVector2f){300, 700};
        }
        sfClock_restart(game->ennemy[game->index_ennemy]->clock_anim);
    }
}

void scene_fight(game_t *game)
{
    game->can_move = 0;
    sfRenderWindow_clear(game->window, sfWhite);
    if (game->ennemy[game->index_ennemy]->in_combat == false ||
        game->player->in_combat == true)
        anim_ennemy(game);
    else if (game->ennemy[game->index_ennemy]->is_attacking == true)
        attack_ennemy(game);
    if (game->player->in_combat == false)
        anim_player(game);
    else
        attack_player(game);
    if (game->ennemy[game->index_ennemy]->life <= 0){
        game->ennemy[game->index_ennemy]->is_alive = false;
        game->nb_piece_hammer++;
        game->player->xp += 4;
        game->player->attack += game->player->xp;
        handle_xp_event(game);
    }
    if (game->ennemy[game->index_ennemy]->is_alive == false)
        game->n = 50;
}
