/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Print display functions
*/

#include "../include/my.h"

static long get_divisor(int mem_unit)
{
    long divisor = 1;

    for (int i = 0; i < mem_unit; i++)
        divisor *= 1024;
    return divisor;
}

static void format_time_part(char *buf, int hours, int minutes)
{
    if (hours > 0)
        sprintf(buf, "%d:%02d", hours, minutes);
    else
        sprintf(buf, "%d min", minutes);
}

static void format_uptime(char *buf, int days, int hours, int minutes)
{
    char *day_str = (days == 1) ? "day" : "days";

    if (days > 0 && hours > 0)
        sprintf(buf, "%d %s,  %d:%02d", days, day_str, hours, minutes);
    else if (days > 0)
        sprintf(buf, "%d %s, %d min", days, day_str, minutes);
    else
        format_time_part(buf, hours, minutes);
}

static void print_header(display_data_t *data)
{
    char uptime_buf[64];

    format_uptime(uptime_buf, data->days, data->hours, data->minutes);
    mvprintw(0, 0,
        "my_top - %s up %s, %d user, "
        "load average: %.2f, %.2f, %.2f",
        data->time_str, uptime_buf, data->user,
        data->load1, data->load5, data->load15);
    mvprintw(1, 0,
        "Tasks: %d total, %d running, %d sleeping, %d stopped, %d zombie",
        data->tasks_total, data->tasks_running, data->tasks_sleeping,
        data->tasks_stopped, data->tasks_zombie);
}

static void print_mem(display_data_t *data, char **units, long divisor)
{
    mvprintw(2, 0, "%s Mem: %ld total, %ld free, %ld used, %ld buff/cache",
        units[data->mem_unit], data->mem_total / divisor,
        data->mem_free / divisor, data->mem_used / divisor,
        data->mem_buffers / divisor);
    mvprintw(4, 0, "%s Swap: %ld total, %ld free, %ld used, %ld avail Mem",
        units[data->mem_unit], data->swap_total / divisor,
        data->swap_free / divisor, data->swap_used / divisor,
        data->mem_available / divisor);
}

static void print_cpu(display_data_t *data)
{
    mvprintw(3, 0,
        "%%Cpu(s): %.1f us, %.1f sy, %.1f ni, %.1f id, %.1f wa, %.1f hi, "
        "%.1f si, %.1f st", data->cpu_us, data->cpu_sy, data->cpu_ni,
        data->cpu_id, data->cpu_wa, data->cpu_hi, data->cpu_si, data->cpu_st);
}

int print(display_data_t *data)
{
    char *units[] = {"KiB", "MiB", "GiB", "TiB", "PiB", "EiB"};
    long divisor;

    divisor = get_divisor(data->mem_unit);
    print_header(data);
    print_mem(data, units, divisor);
    print_cpu(data);
    return 0;
}
