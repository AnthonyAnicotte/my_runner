/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

void create_game(window_t *window, player_t *player, obstacle_t *obstacle)
{
    obstacle->pos_obstacle_tab = malloc(sizeof(sfVector2f) * 1000);
    window->i = 0;
    obstacle->ennemies = 0;
    obstacle->ennemy_flag = 0;
    obstacle->ref_vector.x = 1920;
    obstacle->ref_vector.y = 894;
    create_from_file_game(window, player, obstacle);
    creations_game(window, player, obstacle);
    set_sprites_game(window, player, obstacle);
    create_rect(window, player);
    create_vectors(window, player, obstacle);
    set_strings(window);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
}

void create_menu(window_t *window, menu_t *menu)
{
    window->dofus = sfMusic_createFromFile("assets/musics/dofus.ogg");
    menu->Tplay = sfTexture_createFromFile("assets/images/play.png", NULL);
    menu->Tmenu = sfTexture_createFromFile("assets/images/menu.png", NULL);
    window->video_mode.bitsPerPixel = 128;
    window->video_mode.width = 1980;
    window->video_mode.height = 1080;
    window->window = sfRenderWindow_create(window->video_mode, "My Runner",
        sfDefaultStyle, NULL);
    menu->Smenu = sfSprite_create();
    menu->Splay = sfSprite_create();
    sfSprite_setTexture(menu->Splay, menu->Tplay, sfTrue);
    sfSprite_setTexture(menu->Smenu, menu->Tmenu, sfTrue);
}