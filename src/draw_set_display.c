/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

void draw_sprite(window_t *window, int i, player_t *player,
    obstacle_t *obstacle
)
{
    sfSprite_setTextureRect(player->Ssans, player->rect_sans);
    sfSprite_setTextureRect(window->Ssky, window->rect_sky);
    sfSprite_setTextureRect(window->Smount, window->rect_mount);
    sfSprite_setTextureRect(window->Sgrnd, window->rect_ground);
    sfRenderWindow_drawSprite(window->window, window->Ssky, NULL);
    sfRenderWindow_drawSprite(window->window, window->Smount, NULL);
    sfRenderWindow_drawSprite(window->window, window->Sgrnd, NULL);
    if (i == 1) {
        sfRenderWindow_drawSprite(window->window, window->Stransp, NULL);
        sfRenderWindow_drawSprite(window->window, window->Spause, NULL);
    }
    sfRenderWindow_drawSprite(window->window, window->Sball, NULL);
    sfRenderWindow_drawSprite(window->window, player->Ssans, NULL);
    sfRenderWindow_drawText(window->window, window->score_text, NULL);
    set_positions_on_sprite(window, obstacle, i);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
}

void update_score(window_t *window)
{
    window->score_char = int_to_char(window->score_int);
    window->score_int++;
    sfText_setString(window->score_text, window->score_char);
}

int display_window(window_t *window, player_t *player, obstacle_t *obstacle)
{
    window->time = sfClock_getElapsedTime(window->clock);
    window->seconds = window->time.microseconds / 1000000.0;
    if (window->seconds > 0.05) {
        if (window->infinite != 1) {
            if (check_obstacles(window, obstacle) == 1)
            return (1);
        } else
            randomize(window, obstacle);
        check_jump(player);
        update_score(window);
        if (check_collision(window, player, obstacle) == 1)
            return (1);
        move_rect(window, player);
        sfClock_restart(window->clock);
    }
    draw_sprite(window, 0, player, obstacle);
    return (0);
}

void draw_sprite_menu(window_t *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window->window, menu->Smenu, NULL);
    sfRenderWindow_drawSprite(window->window, menu->Splay, NULL);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
}

void set_strings(window_t *window)
{
    window->score_char = "0";
    window->score_text = sfText_create();
    sfText_setFont(window->score_text, window->score_font);
    sfText_setString(window->score_text, window->score_char);
    sfText_setPosition(window->score_text, window->score_pos);
    sfText_setCharacterSize(window->score_text, 14);
}