/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MUL_MY_RUNNER_2018_STRUCT_H
#define MUL_MY_RUNNER_2018_STRUCT_H

typedef struct window_s
{
    sfTexture *Tball;
    sfSprite *Sball;
    sfVector2f pause_pos;

    sfTexture *Ttransp;
    sfSprite *Stransp;

    sfTexture *Tpause;
    sfSprite *Spause;

    sfTexture *Tsky;
    sfSprite *Ssky;

    sfIntRect rect_sky;
    sfTexture *Tmount;
    sfSprite *Smount;

    sfIntRect rect_mount;
    sfTexture *Tgrnd;
    sfSprite *Sgrnd;

    int i;
    char *buffer;
    int infinite;
    int nb_char;
    sfIntRect rect_ground;
    sfVector2f score_pos;
    sfFont *score_font;
    sfText *score_text;
    char *score_char;
    int score_int;
    double seconds;
    sfClock *clock;
    sfTime time;
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *dofus;

} window_t;

typedef struct menu_s
{
    sfTexture *Tmenu;
    sfSprite *Smenu;
    sfVector2i mouse_pos;
    sfTexture *Tplay;
    sfSprite *Splay;
} menu_t;

typedef struct player_s
{
    sfVector2f sans_origin;
    sfVector2f sans_pos;
    sfIntRect rect_sans;
    sfTexture *Tsans;
    sfSprite *Ssans;
    int jump_status;
    sfVector2f check_sans_pos;
} player_t;

typedef struct obstacle_s
{
    sfVector2f ref_vector;
    int ennemy_flag;
    int ennemies;
    sfVector2f *pos_obstacle_tab;
    sfVector2f flowey_origin;
    sfTexture *Tflowey;
    sfVector2f check_flowey_pos;
    sfSprite *Sflowey;
} obstacle_t;

typedef struct dead_s
{
    sfTexture *Tdeath;
    sfSprite *Sdeath;
    sfMusic *death_song;
} dead_t;
#endif
