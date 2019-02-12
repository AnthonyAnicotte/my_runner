/*
** EPITECH PROJECT, 2023
** MUL_my_runner_2018
** File description:
** Created by anthonyanicotte,
*/

#include <time.h>
#include "function.h"

void h_display(void)
{
    write(1, "Finite runner created with CSFML.\n\n", 35);
    write(1, "USAGE\n ./my_runner map.txt\n\n\n", 29);
    write(1, "OPTIONS\n -i       launch the game in infinity mode.", 51);
    write(1, "\n -h       print the usage and quit.\n\n", 39);
    write(1, "USER INTERACTIONS\n SPACE KEY/UP ARROW to jump.\n", 53);
    write(1, " P KEY to pause the game\n", 25);
}

int open_read_arg(char **av, window_t *window)
{
    int fd = open(av[1], O_RDONLY);
    ssize_t nb;
    window->nb_char = 0;
    window->buffer = malloc(sizeof(char) * 15001);
    if (fd == -1)
        return (1);
    nb = read(fd, window->buffer, 15000);
    window->buffer[nb] = '\0';
    if (nb == 0)
        return (1);
    for (int i = 0; window->buffer[i] != '\0'; i++) {
        if (window->buffer[i] != '_' && window->buffer[i] != '-')
            return (1);
        window->nb_char++;
    }
    close(fd);
    return (0);
}

int argument_management(int ac, char **av, window_t *window)
{
    if (ac != 2)
        return (1);
    if (av[1][0] == '-' && (av[1][1] != 'i' && av[1][1] != 'h') &&
        av[1][2] == '\0')
        return (1);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        h_display();
        return (2);
    }
    if (av[1][0] == '-' && av[1][1] == 'i' && av[1][2] == '\0') {
        window->infinite = 1;
        return (0);
    }
    if (open_read_arg(av, window) == 1)
        return (1);
    return (0);
}

int dispatch_windows(window_t *window, menu_t *menu, player_t *player,
    obstacle_t *obstacle)
{
    sfMusic_setLoop(window->dofus, sfTrue);
    sfMusic_play(window->dofus);
    if (start_menu(window, menu, player, obstacle) == 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int nb;
    srand(time(NULL));
    window_t *window = malloc(sizeof(window_t));
    window->infinite = 0;
    nb = argument_management(ac, av, window);
    if (nb == 1)
        return (84);
    if (nb == 2)
        return (0);
    obstacle_t *obstacle = malloc(sizeof(obstacle_t));
    menu_t *menu = malloc(sizeof(menu_t));
    player_t *player = malloc(sizeof(player_t));
    create_menu(window, menu);
    dispatch_windows(window, menu, player, obstacle);
    free_and_destroy(window, menu, player, obstacle);
    return (0);
}