/*
** EPITECH PROJECT, 2024
** inventaire
** File description:
** inventaire
*/
#include "../include/my.h"

void add_weapon(inventory_t **inventory, weapon_t *weapon)
{
    inventory_t *new = malloc(sizeof(inventory_t));
    inventory_t *tmp = *inventory;

    new->weapon = weapon;
    new->next = NULL;
    if (*inventory == NULL) {
        *inventory = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

void remove_weapon(inventory_t **inventory, weapon_t *weapon)
{
    inventory_t *tmp = *inventory;
    inventory_t *prev = NULL;

    if (tmp != NULL && tmp->weapon == weapon) {
        *inventory = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->weapon != weapon) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}

void destroy_inventory(inventory_t **inventory)
{
    inventory_t *tmp = *inventory;
    inventory_t *next;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    *inventory = NULL;
}

weapon_t *create_weapon(char *path, int attack, int defense, int weight)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->texture = sfTexture_createFromFile(path, NULL);
    weapon->sprite = sfSprite_create();
    sfSprite_setTexture(weapon->sprite, weapon->texture, sfTrue);
    weapon->attack = attack;
    weapon->defense = defense;
    weapon->weight = weight;
    return weapon;
}
