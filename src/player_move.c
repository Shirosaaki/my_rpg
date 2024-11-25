/*
** EPITECH PROJECT, 2024
** move
** File description:
** move
*/
#include "../include/my.h"


int can_move(char direction, game_t *game)
{
    if (direction == 'u' && game->map[game->py - 1][game->px] != '#')
        return 1;
    if (direction == 'd' && game->map[game->py + 1][game->px] != '#')
        return 1;
    if (direction == 'l' && game->map[game->py][game->px - 1] != '#')
        return 1;
    if (direction == 'r' && game->map[game->py][game->px + 1] != '#')
        return 1;
    return 0;
}

char get_direction(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyRight)
        return 'r';
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyLeft)
        return 'l';
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyUp)
        return 'u';
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyDown)
        return 'd';
    return '0';
}

void other_next_player_move(game_t *game, char direction)
{
    if (direction == 'r') {
        game->px += 1;
        game->player->pos.x += game->player->speed;
        if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
            anim_p(game->player, 714);
            sfClock_restart(game->player->clock_anim);
        }
    }
    if (direction == 'l') {
        game->px -= 1;
        game->player->pos.x -= game->player->speed;
        if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
            anim_p(game->player, 584);
            sfClock_restart(game->player->clock_anim);
        }
    }
}

void next_player_move(game_t *game, char direction)
{
    if (direction == 'u') {
        game->py -= 1;
        game->player->pos.y -= game->player->speed;
        if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
            anim_p(game->player, 520);
            sfClock_restart(game->player->clock_anim);
        }
    }
    if (direction == 'd') {
        game->py += 1;
        game->player->pos.y += game->player->speed;
        if (sfClock_getElapsedTime(game->player->clock_anim).microseconds >
            70000) {
            anim_p(game->player, 650);
            sfClock_restart(game->player->clock_anim);
        }
    }
    other_next_player_move(game, direction);
}

void player_move(game_t *game)
{
    char direction = get_direction(game);

    if (game->can_move == 0)
        return;
    if (can_move(direction, game) == 1 &&
        sfClock_getElapsedTime(game->player->clock).microseconds > 10000) {
        next_player_move(game, direction);
        sfClock_restart(game->player->clock);
    }
	sfRectangleShape_setPosition(game->player->rect_hitbox, (sfVector2f){game->player->pos.x + 35, game->player->pos.y+32});
	if (game->ennemy[0]->is_alive == true && game->n == 11)
		if (sfRectangleShape_getPosition(game->player->rect_hitbox).x < sfRectangleShape_getPosition(game->ennemy[0]->rect_hitbox).x + sfRectangleShape_getSize(game->ennemy[0]->rect_hitbox).x &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).x + sfRectangleShape_getSize(game->player->rect_hitbox).x > sfRectangleShape_getPosition(game->ennemy[0]->rect_hitbox).x &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).y < sfRectangleShape_getPosition(game->ennemy[0]->rect_hitbox).y + sfRectangleShape_getSize(game->ennemy[0]->rect_hitbox).y &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).y + sfRectangleShape_getSize(game->player->rect_hitbox).y > sfRectangleShape_getPosition(game->ennemy[0]->rect_hitbox).y)
				game->n = 20;	
	if (game->ennemy[1]->is_alive == true && game->n == 8)
		if (sfRectangleShape_getPosition(game->player->rect_hitbox).x < sfRectangleShape_getPosition(game->ennemy[1]->rect_hitbox).x + sfRectangleShape_getSize(game->ennemy[1]->rect_hitbox).x &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).x + sfRectangleShape_getSize(game->player->rect_hitbox).x > sfRectangleShape_getPosition(game->ennemy[1]->rect_hitbox).x &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).y < sfRectangleShape_getPosition(game->ennemy[1]->rect_hitbox).y + sfRectangleShape_getSize(game->ennemy[1]->rect_hitbox).y &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).y + sfRectangleShape_getSize(game->player->rect_hitbox).y > sfRectangleShape_getPosition(game->ennemy[1]->rect_hitbox).y)
				game->n = 20;	
	if (game->ennemy[2]->is_alive == true && game->n == 5)
		if (sfRectangleShape_getPosition(game->player->rect_hitbox).x < sfRectangleShape_getPosition(game->ennemy[2]->rect_hitbox).x + sfRectangleShape_getSize(game->ennemy[2]->rect_hitbox).x &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).x + sfRectangleShape_getSize(game->player->rect_hitbox).x > sfRectangleShape_getPosition(game->ennemy[2]->rect_hitbox).x &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).y < sfRectangleShape_getPosition(game->ennemy[2]->rect_hitbox).y + sfRectangleShape_getSize(game->ennemy[2]->rect_hitbox).y &&
			sfRectangleShape_getPosition(game->player->rect_hitbox).y + sfRectangleShape_getSize(game->player->rect_hitbox).y > sfRectangleShape_getPosition(game->ennemy[2]->rect_hitbox).y)
				game->n = 20;
    tp_player(game, direction);
}
