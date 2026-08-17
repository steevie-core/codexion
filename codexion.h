typedef enum e_scheduler
{
    fifo_sched, 
    edf_sched

} t_scheduler;

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

} t_codex;

t_codex *codex_return(void);