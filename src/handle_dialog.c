/*
** EPITECH PROJECT, 2024
** dialog
** File description:
** dialog
*/
#include "../include/my.h"

void next_create_dialogue(char **tab, dialog_t *new, char *text, char *buff)
{
    int j = 0;
    int i = 0;

    for (i; tab[i] != NULL; i++) {
        if (strcmp(tab[i], text) == 0)
            j = i + 1;
        if (j != (i + 1) && j != 0 && strncmp(tab[i], "Vi", 2) == 0)
            break;
    }
    new->text = malloc(sizeof(char) * (strlen(buff) + 1));
    new->text[0] = '\0';
    for (j; j < i; j++) {
        new->text = strcat(new->text, tab[j]);
        new->text = strcat(new->text, "\n");
    }
    new->text[strlen(new->text) - 1] = '\0';
}

void create_dialogue(png_t *png, char *text)
{
    dialog_t *new = malloc(sizeof(dialog_t));
    dialog_t *tmp = png->dialog;
    int fd = open("dialogues", O_RDWR | O_CREAT | O_APPEND, 0666);
    char *buff = malloc(sizeof(char) * 1177);
    char **tab = NULL;

    read(fd, buff, 1177);
    buff[1176] = '\0';
    tab = my_str_to_word_array(buff, '\n');
    next_create_dialogue(tab, new, text, buff);
    new->next = NULL;
    if (png->dialog == NULL) {
        png->dialog = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

void display_dialog(png_t *png, game_t *game)
{
    sfSprite *dialog_box = sfSprite_create();
    sfTexture *dialog_box_texture = sfTexture_createFromFile(
        "assets/dialog.png", NULL);
    sfVector2f pos = {sfSprite_getPosition(png->sprite).x - 275,
        sfSprite_getPosition(png->sprite).y + 150};
    sfText *text = sfText_create();

    sfText_setString(text, png->dialog->text);
    sfText_setFont(text, sfFont_createFromFile("assets/font2.ttf"));
    sfText_setCharacterSize(text, 15);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){pos.x + 30, pos.y + 20});
    sfSprite_setTexture(dialog_box, dialog_box_texture, sfTrue);
    sfSprite_setScale(dialog_box, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(dialog_box, pos);
    sfRenderWindow_drawSprite(game->window, dialog_box, NULL);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfTexture_destroy(dialog_box_texture);
    sfSprite_destroy(dialog_box);
    sfText_destroy(text);
}
