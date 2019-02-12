/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

void destroy_function_menu(window_t *window, menu_t *menu)
{
    sfSprite_destroy(menu->Splay);
    sfSprite_destroy(menu->Smenu);
    sfMusic_destroy(window->dofus);
    sfRenderWindow_close(window->window);
}

void destroy_function_game(window_t *window, obstacle_t *obstacle)
{
    sfClock_destroy(window->clock);
    sfSprite_destroy(window->Sgrnd);
    sfSprite_destroy(window->Sball);
    sfSprite_destroy(window->Smount);
    sfSprite_destroy(window->Ssky);
    sfSprite_destroy(obstacle->Sflowey);
    sfSprite_destroy(window->Spause);
    sfSprite_destroy(window->Stransp);
    sfMusic_destroy(window->dofus);
    sfRenderWindow_close(window->window);
}

void free_and_destroy(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle)
{
    sfRenderWindow_destroy(window->window);
    free(window);
    free(menu);
    free(player);
    free(obstacle);
}