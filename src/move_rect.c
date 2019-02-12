/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

void move_rect(window_t *window, player_t *player)
{
    if (window->rect_ground.left >= 3840)
        window->rect_ground.left = 0;
    else
        window->rect_ground.left += 18;
    if (window->rect_mount.left >= 3840)
        window->rect_mount.left = 0;
    else
        window->rect_mount.left += 2;
    if (window->rect_sky.left >= 3840)
        window->rect_sky.left = 0;
    else
        window->rect_sky.left += 1;
    if (player->rect_sans.left >= 240)
        player->rect_sans.left = 12;
    else
        player->rect_sans.left += 76;
}