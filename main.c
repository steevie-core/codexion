#include "codexion.h"

t_codex* codex_return() 
{
    static t_codex codex;
    return (&codex);
}

int dongles_init()
{
    t_dongle *dongle_arr;
    t_codex *codex;
    int i;

    codex = codex_return();
    i = 0;
    dongle_arr = malloc(codex->number_of_coders * sizeof(t_dongle));
    if (!(dongle_arr))
        return (-1);
    codex->dongles = dongle_arr;
    while (i < codex->number_of_coders)
    {
        pthread_mutex_init(&codex->dongles[i].mutex, NULL);
        codex->dongles[i].dongle_availability = available;
        codex->dongles[i].released_time = 0;
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_codex *codex;

    codex = codex_return();
    if (argc != 9)
        return (printf("wrong number of arguments\n"), 1);
    if (parser_validator(argv) == 1 || parser_last_validator(argv) == 1)
        return (1);
    free(codex->dongles);
    pthread_mutex_destroy;
    return (0);
}