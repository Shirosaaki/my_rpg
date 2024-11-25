/*
** EPITECH PROJECT, 2024
** player
** File description:
** player
*/
#include "../include/my.h"

void next_init_player(player_t *player)
{
    player->count_death = -1;
    player->speed = 5;
    player->inventory = create_inventory();
    player->clock = sfClock_create();
    player->clock_anim = sfClock_create();
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->texture = sfTexture_createFromFile
        ("assets/spritessheets/player.png", NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->pos = (sfVector2f){780, 780};
    player->pos_fight = (sfVector2f){780, 700};
    player->rect = (sfIntRect){0, 650, 54, 54};
    player->rect_fight = init_rect_fight();
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->life = 100;
    player->attack = 10;
    player->defense = 5;
    player->xp = 0;
    player->life = 100;
    player->level = 1;
    next_init_player(player);
    return player;
}

sfText* create_xp_text(void)
{
    sfFont* font = sfFont_createFromFile("assets/font.ttf");
    sfText* xpText = sfText_create();
    sfSprite* sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile("assets/XP0.png", NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfText_setString(xpText, "XP: 0");
    sfText_setFont(xpText, font);
    sfText_setCharacterSize(xpText, 24);
    return xpText;
}

player_t *create_player(void)
{
    player_t *player = init_player();

    player->xpText = create_xp_text();
    player->index_attack = -1;
    player->inventory = create_inventory();
    player->clock = sfClock_create();
    player->clock_anim = sfClock_create();
    player->clock_attack = sfClock_create();
    player->rect_hitbox = sfRectangleShape_create();
    player->hitbox_size = (sfVector2f){54, 54};
    sfRectangleShape_setSize(player->rect_hitbox, player->hitbox_size);
    sfRectangleShape_setFillColor(player->rect_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(player->rect_hitbox, 1);
    sfRectangleShape_setOutlineColor(player->rect_hitbox, sfBlue);
    sfRectangleShape_setPosition(player->rect_hitbox,
        (sfVector2f){player->pos.x - 1000, player->pos.y - 1000});
    return player;
}
