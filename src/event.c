/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

int event_function_menu(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle
)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (check_mouse_on_play(window, menu, player, obstacle) == 1)
            return (1);
    }
    if (window->event.type == sfEvtClosed) {
        destroy_function_menu(window, menu);
        return (1);
    }
    return (0);
}

int event_function_game(window_t *window, player_t *player,
    obstacle_t *obstacle
)
{
    if (window->event.type == sfEvtClosed) {
        destroy_function_game(window, obstacle);
        return (1);
    }
    if (window->event.type == sfEvtKeyPressed &&
        window->event.key.code == sfKeyP) {
        if (pause_function(window, player, obstacle) == 84) {
            destroy_function_game(window, obstacle);
            return (1);
        }
    }
    if (window->event.key.code == sfKeySpace ||
        window->event.key.code == sfKeyUp) {
        if (player->jump_status == 0) {
            player->jump_status = 1;
        }
    }
    return (0);
}