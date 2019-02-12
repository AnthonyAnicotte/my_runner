/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/
#include <time.h>
#include "function.h"

void wait_few_seconds(int delay)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    double seconds = time.microseconds / 1000000.0;

    while (seconds != delay) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
    }
}

void set_positions_on_sprite(window_t *window, obstacle_t *obstacle, int i)
{
    if (obstacle->ennemy_flag == 1 || window->infinite == 1) {
        for (int i = 0; i < obstacle->ennemies; i++) {
            sfSprite_setPosition(obstacle->Sflowey,
                obstacle->pos_obstacle_tab[i]);
            sfRenderWindow_drawSprite(window->window, obstacle->Sflowey, NULL);
        }
        if (i != 1) {
            for (int i = 0; i < obstacle->ennemies; i++) {
                obstacle->pos_obstacle_tab[i].x -= 15;
            }
        }
    }
}

void randomize(window_t *window, obstacle_t *obstacle)
{
    int nb;
    static int randing = 2000;

    nb = rand() % randing;
    if (nb % 15 == 0) {
        obstacle->pos_obstacle_tab[obstacle->ennemies] = obstacle->ref_vector;
        obstacle->ennemies++;
        set_positions_on_sprite(window, obstacle, 0);
    }
    randing--;
}