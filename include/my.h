/*
** EPITECH PROJECT, 2022
** Unix System Programming, my_top
** File description:
** my.h
*/

#ifndef MY_H_
    # define MY_H_

    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <dirent.h>
    #include <time.h>
    #include <utmp.h>
    #include <pwd.h>
    #include <signal.h>
    #include "my_printf.h"
    #include "other_functions.h"

typedef struct flags_s {
    int U;
    int d;
    int n;
    int frames;
    float seconds;
    struct passwd *pw;
} flags_t;

typedef struct display_data_s {
    char time_str[9];
    int days;
    int hours;
    int minutes;
    int user;
    int mem_unit;
    float load1;
    float load5;
    float load15;
    long mem_total;
    long mem_free;
    long mem_buffers;
    long mem_cached;
    long mem_used;
    long mem_available;
    long swap_total;
    long swap_free;
    long swap_used;
    int tasks_total;
    int tasks_running;
    int tasks_sleeping;
    int tasks_stopped;
    int tasks_zombie;
    float cpu_us;
    float cpu_sy;
    float cpu_ni;
    float cpu_wa;
    float cpu_hi;
    float cpu_si;
    float cpu_st;
    float cpu_id;
} display_data_t;

typedef struct cpu_stats_s {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
} cpu_stats_t;

int parse_options(int argc, char **argv, flags_t *flags);
int parse_chooser(char **argv, flags_t *flags, int i);
int parse_u(char **argv, flags_t *flags, int i);
int parse_d(char **argv, flags_t *flags, int i);
int parse_n(char **argv, flags_t *flags, int i);
void init_flags(flags_t *flags);
void help(void);
int print(display_data_t *data);
void init_ncurses(void);
void cleanup_ncurses(void);
void main_loop(flags_t *flags);
int get_loadavg(float *load1, float *load5, float *load15);
int get_uptime(int *uptime);
int get_user_count(void);
int get_mem_info(display_data_t *data);
int get_tasks(display_data_t *data);
int read_cpu_stats(cpu_stats_t *stats);
int calc_cpu_percent(cpu_stats_t *prev, cpu_stats_t *curr,
    display_data_t *data);

#endif
