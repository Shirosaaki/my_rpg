/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "../include/my.h"

static void next_next_init_game(game_t *game)
{
    game->ennemy[0] = init_ennemy("assets/Ennemy1/Ennemy1_iddle.png",
        (sfVector2f){400, 450}, (sfIntRect){0, 0, 85, 95},
        (sfVector2f){1.5, 1.5});
    game->ennemy[1] = init_ennemy("assets/Ennemy1/Ennemy1_iddle.png",
        (sfVector2f){400, 450}, (sfIntRect){0, 0, 85, 95},
        (sfVector2f){1.5, 1.5});
    game->ennemy[2] = init_ennemy("assets/Ennemy1/Ennemy1_iddle.png",
        (sfVector2f){400, 450}, (sfIntRect){0, 0, 85, 95},
        (sfVector2f){1.5, 1.5});
    game->index_ennemy = 0;
    game->previous_scene = game->n;
}

static game_t *next_init_game(game_t *game)
{
    game->view = sfView_createFromRect((sfFloatRect){0, 0, 1280, 720});
    game->png = malloc(sizeof(png_t) * 2);
    game->png[0] = create_png("assets/spritessheets/Eric.png", (sfVector2f)
        {1045, 10}, (sfIntRect){0, 0, 0, 0}, (sfVector2f){-0.35, 0.35});
    create_dialogue(game->png[0], "Eric:");
    game->png[1] = create_png("assets/spritessheets/old_dwarf.png",
        (sfVector2f){805, 650}, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){0.15, 0.15});
    create_dialogue(game->png[1], "Vieu:");
    create_dialogue(game->png[1], "Vieu2:");
    create_dialogue(game->png[1], "Vieu3:");
    create_dialogue(game->png[1], "Vieu4:");
    create_dialogue(game->png[1], "Vieu5:");
    game->disp_dialog = 0;
    game->can_move = 1;
    game->display_quest = 0;
    game->nb_piece_hammer = 0;
    return game;
}

static game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->ennemy = malloc(sizeof(ennemy_t) * 3);
    game->is_paused = 0;
    game->window = create_window();
    game->music = sfMusic_createFromFile("assets/musiques/menu.ogg");
    game->player = create_player();
    game->n = 0;
    game->select = 0;
    game->nb_boss = 2;
    game->disp_inventory = 0;
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    game = next_init_game(game);
    load_map_disp(game, "assets/maps/map.png");
    game->transition = init_transition();
    next_next_init_game(game);
    return game;
}

static void other_next_event_gestion(game_t *game)
{
    if (game->is_paused == 1)
        handle_input(game, game->event);
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyA)
        game->n = 20;
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyB && game->n == 21)
        game->n = 50;
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyEnter && game->n == 21) {
        game->ennemy[game->index_ennemy]->in_combat = true;
        game->ennemy[game->index_ennemy]->is_attacking = true;
    }
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyQ && game->n == 21)
        game->player->in_combat = true;
}

void destroy_all(game_t *game)
{
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->window);
    free(game->map);
    free(game->player);
    free(game->transition);
    free(game->png);
    free(game);
}

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Nainventure",
        sfClose | sfResize, NULL);

    return window;
}

void event_gestion(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtResized)
        resize_event(game);
    if (game->n < 42) {
        if (game->event.type == sfEvtKeyPressed
            && game->event.key.code == sfKeyEscape)
            game->is_paused = !game->is_paused;
        if (game->n != 0 && game->disp_inventory == 0 && game->is_paused == 0)
            player_move(game);
        if (game->n != 0 && game->is_paused == 0)
            next_player_event_gestion(game);
        if (game->n == 0)
            next_event_gestion_menu(game);
        other_next_event_gestion(game);
        interact_with_png(game);
    }
    if (game->n >= 999)
        handle_input2(game, game->event);
}

int main(void)
{
    game_t *game = init_game();

    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            event_gestion(game);
        if (game->n != 20)
            sfRenderWindow_clear(game->window, sfBlack);
        if (game->player->life <= 0 && game->n <= 999)
            game->n = 999;
        if (game->nb_piece_hammer == 3 && game->n < 84)
            game->n = 84;
        what_disp(game);
        sfRenderWindow_display(game->window);
    }
}
