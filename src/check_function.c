/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/
#include "function.h"

void win_function(window_t *window)
{
    sfMusic *win = sfMusic_createFromFile("assets/musics/win.ogg");
    sfTexture *texture = sfTexture_createFromFile("assets/images/win.png",
        NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfMusic_destroy(window->dofus);
    sfMusic_play(win);
    sfRenderWindow_drawSprite(window->window, sprite, NULL);
    sfRenderWindow_display(window->window);
    wait_few_seconds(7);
    sfMusic_destroy(win);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int check_obstacles(window_t *window, obstacle_t *obstacle)
{
    static int end_game = 0;
    if (window->buffer[window->i] != '\0') {
        if (window->buffer[window->i] == '-') {
            obstacle->ennemies++;
            obstacle->ennemy_flag = 1;
            obstacle->pos_obstacle_tab[obstacle->ennemies -
                1] = obstacle->ref_vector;
        }
        window->i++;
    } else {
        end_game++;
        if (end_game == 50) {
            win_function(window);
            return (1);
        }
    }
    return (0);
}

int check_collision(window_t *window, player_t *player, obstacle_t *obstacle)
{
    for (int i = 0; i < obstacle->ennemies; i++) {
        player->check_sans_pos = sfSprite_getPosition(player->Ssans);
        obstacle->check_flowey_pos = obstacle->pos_obstacle_tab[i];
        if (obstacle->check_flowey_pos.y - player->check_sans_pos.y < 80) {
            if (player->check_sans_pos.x < obstacle->check_flowey_pos.x) {
                if (obstacle->check_flowey_pos.x - player->check_sans_pos.x <
                    60 &&
                    obstacle->check_flowey_pos.x - player->check_sans_pos.x >
                        0) {
                    if (dead_function(window) == 1)
                        return (1);
                }
            } else {
                if (player->check_sans_pos.x - obstacle->check_flowey_pos.x <
                    60 &&
                    player->check_sans_pos.x - obstacle->check_flowey_pos.x >
                        0) {
                    if (dead_function(window) == 1)
                        return (1);
                }
            }
        }
    }
    return (0);
}

void check_jump(player_t *player)
{
    static int test = 5;
    if (player->jump_status == 1) {
        if (player->sans_pos.y > 700) {
            player->sans_pos.y -= 30;
            test += 5;
        }
        if (player->sans_pos.y <= 700)
            player->jump_status = 2;
    }
    test = 5;
    if (player->jump_status == 2) {
        if (player->sans_pos.y <= 850) {
            player->sans_pos.y += 30;
            test += 5;
        }
        if (player->sans_pos.y >= 850)
            player->jump_status = 0;
    }
    sfSprite_setPosition(player->Ssans, player->sans_pos);
}

int check_mouse_on_play(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle)
{
    menu->mouse_pos = sfMouse_getPosition(window->window);
    if (menu->mouse_pos.x > 94 && menu->mouse_pos.x < 364 &&
        menu->mouse_pos.y > 118 && menu->mouse_pos.y < 212) {
        if (menu_to_game(window, menu, player, obstacle) == 1)
            return (1);
    }
    return (0);
}