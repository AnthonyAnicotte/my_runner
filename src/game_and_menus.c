/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

int dead_function(window_t *window)
{
    static int death_flag = 0;
    dead_t *dead = malloc(sizeof(dead_t));
    if (death_flag == 0) {
        dead->Tdeath = sfTexture_createFromFile("assets/images/died.png", NULL);
        dead->Sdeath = sfSprite_create();
        sfSprite_setTexture(dead->Sdeath, dead->Tdeath, sfTrue);
        sfRenderWindow_drawSprite(window->window, dead->Sdeath, NULL);
        sfRenderWindow_display(window->window);
        dead->death_song = sfMusic_createFromFile("assets/musics/died.ogg");
        sfMusic_stop(window->dofus);
        sfMusic_destroy(window->dofus);
        sfMusic_play(dead->death_song);
        death_flag = 1;
    }
    wait_few_seconds(7);
    sfMusic_destroy(dead->death_song);
    return (1);
}

int menu_to_game(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle)
{
    sfTexture_destroy(menu->Tmenu);
    sfTexture_destroy(menu->Tplay);
    sfSprite_destroy(menu->Smenu);
    sfSprite_destroy(menu->Splay);
    create_game(window, player, obstacle);
    if (game_test(window, player, obstacle) == 1)
        return (1);
    return (0);
}

int start_menu(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle)
{
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_isOpen(window->window) &&
            sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (event_function_menu(window, menu, player, obstacle) == 1)
                return (1);
        }
        draw_sprite_menu(window, menu);
    }
    return (0);
}

int game_test(window_t *window, player_t *player, obstacle_t *obstacle)
{
    sfRenderWindow_setFramerateLimit(window->window, 60);
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_isOpen(window->window) &&
            sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (event_function_game(window, player, obstacle) == 1)
                return (1);
        }
        if (display_window(window, player, obstacle) == 1)
            return (1);
    }
    return (0);
}

int pause_function(window_t *window, player_t *player, obstacle_t *obstacle)
{
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (window->event.type == sfEvtKeyPressed &&
                window->event.key.code == sfKeyP)
                return (1);
            if (window->event.type == sfEvtClosed)
                return (84);
        }
        draw_sprite(window, 1, player, obstacle);
    }
    return (0);
}