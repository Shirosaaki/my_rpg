/*
** EPITECH PROJECT, 2024
** transition fight
** File description:
** transition fight
*/

#include "../include/my.h"

fight_t *init_transition()
{
	fight_t *init_transition = malloc(sizeof(fight_t));
	init_transition->reverse = false;
	init_transition->positon = (sfVector2f){80, 450};
	init_transition->rect = (sfIntRect){0, 0, 500, 275};	

	init_transition->transition_sprite = sfSprite_create();
	init_transition->texture = sfTexture_createFromFile("assets/transition_combat.png", NULL);
	sfSprite_setTexture(init_transition->transition_sprite, init_transition->texture, sfTrue);
	sfSprite_setTextureRect(init_transition->transition_sprite, init_transition->rect);
	sfSprite_setPosition(init_transition->transition_sprite, init_transition->positon);
	sfSprite_setScale(init_transition->transition_sprite, (sfVector2f){2, 2.2});
	init_transition->clock_transition = sfClock_create();


	return init_transition;
}


void transition_anim(game_t *game, int n)
{
	double seconds = game->transition->time.microseconds / 1000000.0;
	game->transition->time = sfClock_getElapsedTime(game->transition->clock_transition);
	if (game->n != 50)
		sfSprite_setPosition(game->transition->transition_sprite, game->transition->positon);

	//animation fermeture de la transition
	if (game->transition->reverse == false && seconds > 0.08 && game->transition->rect.left != 5000) {
		game->transition->rect.left += 500;
		sfClock_restart(game->transition->clock_transition);
	}
	//si la transition est ouverte, on attend 0.4 secondes avant de la fermer
	if (game->transition->rect.left == 5000) {
		if (seconds > 0.4){
			game->transition->reverse = true;
			sfClock_restart(game->transition->clock_transition);
		}
	}
	//animation de d'ouverture de la transition
	if (game->transition->reverse == true && seconds > 0.08 && game->transition->rect.left != -500) {
		if (game->n != 50)
			sfRenderWindow_clear(game->window, sfWhite);
		game->transition->rect.left -= 500;
		sfClock_restart(game->transition->clock_transition);
	}
	//si la transition est fermée, on la remet à 0
	if (game->transition->rect.left == -500) {
		if (game->n == 50){
			load_map(game, "map.txt", (sfVector2f){160, 160}, (sfVector2f){320, 320});
			load_map_disp(game, "assets/maps/map.png");
			sfSprite_setPosition(game->player->sprite, game->player->pos);
			game->player->in_combat = false;
			game->n = n;
			game->can_move = 1;
		}
		else
			game->n = n;
		game->transition->rect.left = 0;
		game->transition->reverse = false;
	}
	sfSprite_setTextureRect(game->transition->transition_sprite, game->transition->rect);
	sfRenderWindow_drawSprite(game->window, game->transition->transition_sprite, NULL);
}