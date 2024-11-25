/*
** EPITECH PROJECT, 2024
** my_h
** File description:
** my_h
*/
#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>
    #include <sys/wait.h>
    #include <stdbool.h>

typedef struct weapon_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int defense;
    int attack;
    int weight;
} weapon_t;

typedef struct inventory_s {
    weapon_t *weapon;
    struct inventory_s *next;
} inventory_t;

typedef struct dialog {
    char *text;
    struct dialog *next;
} dialog_t;

typedef struct png_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    dialog_t *dialog;
} png_t;

typedef struct player_s {
    inventory_t *inventory;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_fight;
    sfIntRect rect;
    sfIntRect *rect_fight;
    sfClock *clock;
    sfClock *clock_anim;
    sfText* xpText;
    sfClock *clock_attack;
    sfVector2f hitbox_size;
    sfRectangleShape *rect_hitbox;
    bool in_combat;
    float speed;
    int defense;
    int attack;
    int level;
    int life;
    int xp;
    int count_death;
    int index_attack;
} player_t;

typedef struct ennemy_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfClock *clock_anim;
    sfVector2f hitbox_size;
    sfRectangleShape *rect_hitbox;
    bool in_combat;
    bool is_alive;
    bool is_attacking;
    float speed;
    int defense;
    int attack;
    int life;
} ennemy_t;

typedef struct fight_s {
    sfSprite *transition_sprite;
    sfTexture *texture;
    sfClock *clock_transition;
    sfTime time;
    sfIntRect rect;
    sfVector2f positon;
    bool reverse;
} fight_t;


typedef struct game_s {
    sfTexture *map_disp_texture;
    sfRenderWindow *window;
    int disp_inventory;
    sfSprite *map_disp;
    player_t *player;
    ennemy_t **ennemy;
    fight_t *transition;
    int disp_dialog;
    sfMusic *music;
    sfMusic *quete;
    sfClock *clock;
    int is_paused;
    int can_move;
    sfEvent event;
    sfView *view;
    png_t **png;
    char **map;
    int select;
    int init;
    int fd;
    int px;
    int py;
    int n;
    int display_quest;
    int previous_scene;
    int nb_piece_hammer;
    int nb_boss;
    int index_ennemy;
} game_t;

void anim_p(player_t *player, int top);
void what_disp(game_t *game);
weapon_t *create_weapon(char *path, int attack, int defense, int weight);
void display_inventory(inventory_t *inventory, game_t *game);
player_t *create_player(void);
fight_t *init_transition(void);
ennemy_t *init_ennemy(char *path_asset, sfVector2f pos_ennemy,
    sfIntRect rect_ennemy, sfVector2f scale);
sfIntRect *init_rect_fight(void);
void attack_ennemy(game_t *game);
void next_attack_ennemy(double seconds, game_t *game);
void NewFunction(double seconds, game_t *game);
void anim_ennemy(game_t *game);
void transition_anim(game_t *game, int n);
player_t *create_player(void);
sfRenderWindow *create_window(void);
void player_move(game_t *game);
char **my_str_to_word_array(char *str, char separator);
void next_player_move(game_t *game, char direction);
void next_event_gestion_menu(game_t *game);
void next_player_event_gestion(game_t *game);
void resize_event(game_t *game);
void load_map(game_t *game, char *path, sfVector2f pos, sfVector2f size);
void next_what_disp(game_t *game);
void scene_fight(game_t *game);
void player_fight(game_t *game);
void attack_player(game_t *game);
void next_attack_player(double seconds, game_t *game);
void anim_player(game_t *game);
void draw_map(sfRenderWindow *window, char *path);
png_t *create_png(char *path, sfVector2f pos, sfIntRect rect,
    sfVector2f scale);
int interact_with_png(game_t *game);
void display_dialog(png_t *png, game_t *game);
int can_tp(game_t *game);
void load_map_disp(game_t *game, char *path);
void tp_player(game_t *game, char direction);
void event_gestion(game_t *game);
void disp_pausemenu(game_t *game);
void handle_input(game_t *game, sfEvent event);
inventory_t *create_inventory(void);
void anim_death(player_t *player);
void display_xp_bar(game_t *game, sfVector2f pos);
void display_health_bar(game_t *game, sfVector2f pos);
void display_image1(game_t *game, sfVector2f player_position);
void display_image2(game_t *game, sfVector2f player_position);
int display_quest(game_t *game, sfVector2f player_position);
void next_next_player_event_gestion(game_t *game);
void create_dialogue(png_t *png, char *text);
void end_game(game_t *game);
void anim_end(player_t *player, game_t *game);
void handle_input(game_t *game, sfEvent event);
void dead(game_t *game);
void cursor(game_t *game);
sfTexture *create_texture(sfSprite **sprite, const char *file_path);
void set_sprite_properties(game_t *game, sfSprite *sprite);
void handle_input2(game_t *game, sfEvent event);
void handle_xp_event(game_t *game);

#endif /* !MY_H_ */
