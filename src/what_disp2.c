/*
** EPITECH PROJECT, 2024
** chat
** File description:
** what
*/
#include "../include/my.h"

void print_eric(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->png[0]->sprite, NULL);
}

void next_what_disp(game_t *game)
{
    if (game->n >= 2 && game->n != 20 && game->n != 21 && game->n != 50) {
		sfSprite_setScale(game->player->sprite, (sfVector2f){1, 1});
        sfView_setCenter(game->view,
            (sfVector2f){sfSprite_getPosition(game->player->sprite).x + 27,
            sfSprite_getPosition(game->player->sprite).y + 27});
        sfRenderWindow_drawSprite(game->window, game->map_disp, NULL);
        sfRenderWindow_setView(game->window, game->view);
        sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
		// sfRenderWindow_drawRectangleShape(game->window, game->player->rect_hitbox, NULL);
        if (game->disp_inventory == 1)
            display_inventory(game->player->inventory, game);
    }
    if (game->n == 2) {
        print_eric(game);
        if (game->disp_dialog != 0)
            display_dialog(game->png[0], game);
    }
	if (game->n == 11 && game->ennemy[0]->is_alive == true) 
		sfRenderWindow_drawSprite(game->window, game->ennemy[0]->sprite, NULL);
	if (game->n == 8 && game->ennemy[1]->is_alive == true)
		sfRenderWindow_drawSprite(game->window, game->ennemy[1]->sprite, NULL);
	if (game->n == 5 && game->ennemy[2]->is_alive == true)
		sfRenderWindow_drawSprite(game->window, game->ennemy[2]->sprite, NULL);
    if (game->is_paused == 1)
        disp_pausemenu(game);
	if (game->n == 20){
        sfView_setCenter(game->view,
            (sfVector2f){sfSprite_getPosition(game->player->sprite).x -150,
            sfSprite_getPosition(game->player->sprite).y + 27});
        sfRenderWindow_setView(game->window, game->view);
		transition_anim(game, 21);
		game->previous_scene == 11 ? game->index_ennemy = 0 : 0;
		game->previous_scene == 8  ? game->index_ennemy = 1 : 0;
		game->previous_scene == 5  ? game->index_ennemy = 2 : 0;
		player_fight(game);
	}
	if (game->n == 50){
		if (game->transition->reverse == true){
			sfSprite_setPosition(game->player->sprite, game->player->pos);
			sfSprite_setScale(game->player->sprite, (sfVector2f){1, 1});
			sfView_setCenter(game->view,
				(sfVector2f){sfSprite_getPosition(game->player->sprite).x + 27,
				sfSprite_getPosition(game->player->sprite).y + 27});
			sfRenderWindow_drawSprite(game->window, game->map_disp, NULL);
			sfRenderWindow_setView(game->window, game->view);
			sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
			sfVector2f new_pos = {game->player->pos.x -450, game->player->pos.y -300};
			sfSprite_setPosition(game->transition->transition_sprite, new_pos);
		}
		transition_anim(game, 1);
	}
	if (game->n == 21){
        sfRenderWindow_setView(game->window, game->view);
		scene_fight(game);
	}
}
