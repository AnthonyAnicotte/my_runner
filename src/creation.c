/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include "function.h"

void create_from_file_game(window_t *window, player_t *player,
    obstacle_t *obstacle)
{
    window->score_font = sfFont_createFromFile("assets/font.ttf");
    window->Tball = sfTexture_createFromFile("assets/images/boule.png", NULL);
    player->Tsans = sfTexture_createFromFile("assets/images/sans.png", NULL);
    window->Tpause = sfTexture_createFromFile("assets/images/pause.png", NULL);
    window->Ttransp = sfTexture_createFromFile("assets/images/grey.png", NULL);
    window->Tgrnd = sfTexture_createFromFile("assets/images/ground.png", NULL);
    window->Tmount = sfTexture_createFromFile("assets/images/mounts.png", NULL);
    window->Tsky = sfTexture_createFromFile("assets/images/sky.png", NULL);
    obstacle->Tflowey = sfTexture_createFromFile("assets/images/flowey.png",
        NULL);
}

void creations_game(window_t *window, player_t *player, obstacle_t *obstacle)
{
    window->clock = sfClock_create();
    window->Sball = sfSprite_create();
    player->Ssans = sfSprite_create();
    window->Spause = sfSprite_create();
    window->Stransp = sfSprite_create();
    window->Ssky = sfSprite_create();
    window->Sgrnd = sfSprite_create();
    window->Smount = sfSprite_create();
    obstacle->Sflowey = sfSprite_create();
}

void set_sprites_game(window_t *window, player_t *player, obstacle_t *obstacle)
{
    sfSprite_setTexture(window->Sball, window->Tball, sfTrue);
    sfSprite_setTexture(player->Ssans, player->Tsans, sfTrue);
    sfSprite_setTexture(window->Spause, window->Tpause, sfTrue);
    sfSprite_setTexture(window->Stransp, window->Ttransp, sfTrue);
    sfSprite_setTexture(window->Ssky, window->Tsky, sfTrue);
    sfSprite_setTexture(window->Smount, window->Tmount, sfTrue);
    sfSprite_setTexture(window->Sgrnd, window->Tgrnd, sfTrue);
    sfSprite_setTexture(obstacle->Sflowey, obstacle->Tflowey, sfTrue);
}

void create_rect(window_t *window, player_t *player)
{
    player->rect_sans.top = 135;
    player->rect_sans.left = 12;
    player->rect_sans.width = 72;
    player->rect_sans.height = 129;

    window->rect_ground.top = 0;
    window->rect_ground.left = 0;
    window->rect_ground.width = 1920;
    window->rect_ground.height = 1080;

    window->rect_mount.width = 1920;
    window->rect_mount.height = 1080;
    window->rect_mount.top = 0;
    window->rect_mount.left = 0;

    window->rect_sky.top = 0;
    window->rect_sky.left = 0;
    window->rect_sky.width = 1920;
    window->rect_sky.height = 1080;
}

void create_vectors(window_t *window, player_t *player, obstacle_t *obstacle)
{
    player->sans_origin.x = 36;
    player->sans_origin.y = 65;
    sfSprite_setOrigin(player->Ssans, player->sans_origin);
    obstacle->flowey_origin.x = 35;
    obstacle->flowey_origin.y = 41;
    sfSprite_setOrigin(obstacle->Sflowey, obstacle->flowey_origin);
    window->score_pos.x = 25;
    window->score_pos.y = 70;
    player->jump_status = 0;
    player->sans_pos.x = 800;
    player->sans_pos.y = 860;
    sfSprite_setPosition(player->Ssans, player->sans_pos);
    window->pause_pos.x = 810;
    window->pause_pos.y = 250;
    sfSprite_setPosition(window->Spause, window->pause_pos);
}