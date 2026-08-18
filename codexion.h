#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef enum e_scheduler
{
    fifo_sched, 
    edf_sched

} t_scheduler;

typedef struct s_dongle
{
    pthread_mutex_t mutex;
    long            released_time;
    enum            {available, taken} dongle_availability;

} t_dongle;

typedef struct s_coder
{
    pthread_mutex_t mutex;
    long            coder_id;
    long            coder_compiles_num;
    long            last_compile;
    int             left_dongle;
    int             right_dongle;

} t_coder;

typedef struct s_codex
{
    long           number_of_coders;
    long           time_to_burnout;
    long           time_to_compile;
    long           time_to_debug;
    long           time_to_refactor;
    long           number_of_compiles_required;
    long           dongle_cooldown;
    t_scheduler    scheduler;
    t_dongle       *dongles;
    t_coder        *coders;

} t_codex;

t_codex *codex_return(void);
int overflow_checker(long value);
int validator_numeric_donglecd(const char *str);
int validator_numeric(const char *str);
int validator_scheduler(const char *str);
int parser_validator(char **argv);
int parser_last_validator(char **argv);