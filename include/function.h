/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/
#ifndef MUL_MY_RUNNER_2018_FUNCTION_H
#define MUL_MY_RUNNER_2018_FUNCTION_H

#include "struct.h"

int main(int ac, char **av);
int pause_function(window_t *window, player_t *player, obstacle_t *obstacle);
void create_vectors(window_t *window, player_t *player, obstacle_t *obstacle);
int check_mouse_on_play(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle);
char *my_revstr_no_display(char *str);
int dispatch_windows(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle);
void create_menu(window_t *window, menu_t *menu);
void create_game(window_t *window, player_t *player, obstacle_t *obstacle);
char *int_to_char(int nb);
void set_sprites_game(window_t *window, player_t *player, obstacle_t *obstacle);
void create_rect(window_t *window, player_t *player);
void creations_game(window_t *window, player_t *player, obstacle_t *obstacle);
void create_from_file_game(window_t *window, player_t *player,
    obstacle_t *obstacle);
int start_menu(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle);
int game_test(window_t *window, player_t *player, obstacle_t *obstacle);
void check_jump(player_t *player);
void set_strings(window_t *window);
int display_window(window_t *window, player_t *player, obstacle_t *obstacle);
void draw_sprite(window_t *window, int i, player_t *player,
    obstacle_t *obstacle);
void h_display(void);
void move_rect(window_t *window, player_t *player);
void draw_sprite_menu(window_t *window, menu_t *menu);
int event_function_game(window_t *window, player_t *player,
    obstacle_t *obstacle);
int event_function_menu(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle);
void destroy_function_game(window_t *window, obstacle_t *obstacle);
void destroy_function_menu(window_t *window, menu_t *menu);
int check_collision(window_t *window, player_t *player, obstacle_t *obstacle);
int menu_to_game(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle);
void wait_few_seconds(int delay);
void free_and_destroy(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle);
int argument_management(int ac, char **av, window_t *window);
int dead_function(window_t *window);
int check_obstacles(window_t *window, obstacle_t *obstacle);
void set_positions_on_sprite(window_t *window, obstacle_t *obstacle, int i);
void randomize(window_t *window, obstacle_t *obstacle);
void win_function(window_t *window);

#endif