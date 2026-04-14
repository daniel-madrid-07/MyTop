/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Main loop functions
*/

#include "../include/my.h"

static void update_time_data(display_data_t *data)
{
    time_t t = time(NULL);
    struct tm *tiempo = localtime(&t);

    strftime(data->time_str, 9, "%H:%M:%S", tiempo);
}

static void update_uptime_data(display_data_t *data, int uptime)
{
    data->days = uptime / 86400;
    data->hours = (uptime % 86400) / 3600;
    data->minutes = (uptime % 3600) / 60;
}

static void handle_input(int ch, display_data_t *data, int *running)
{
    if (ch == 'q')
        *running = 0;
    if (ch == 'E') {
        data->mem_unit++;
        if (data->mem_unit > 5)
            data->mem_unit = 0;
    }
}

static void update_display(display_data_t *data, cpu_stats_t *prev,
    cpu_stats_t *curr)
{
    int uptime;

    clear();
    update_time_data(data);
    get_loadavg(&data->load1, &data->load5, &data->load15);
    get_uptime(&uptime);
    update_uptime_data(data, uptime);
    get_mem_info(data);
    get_tasks(data);
    read_cpu_stats(curr);
    calc_cpu_percent(prev, curr, data);
    data->user = get_user_count();
    print(data);
    refresh();
}

void main_loop(flags_t *flags)
{
    int running = 1;
    int ch;
    display_data_t data;
    cpu_stats_t cpu_prev;
    cpu_stats_t cpu_curr;

    memset(&data, 0, sizeof(data));
    read_cpu_stats(&cpu_prev);
    while (running) {
        update_display(&data, &cpu_prev, &cpu_curr);
        napms(flags->seconds * 1000);
        ch = getch();
        handle_input(ch, &data, &running);
    }
}
