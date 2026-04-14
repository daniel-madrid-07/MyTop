/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** CPU info functions
*/

#include "../include/my.h"

int read_cpu_stats(cpu_stats_t *stats)
{
    FILE *file;

    file = fopen("/proc/stat", "r");
    if (file == NULL)
        return 0;
    fscanf(file, "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
        &stats->user, &stats->nice, &stats->system, &stats->idle,
        &stats->iowait, &stats->irq, &stats->softirq, &stats->steal);
    fclose(file);
    return 0;
}

static long calc_total_diff(cpu_stats_t *prev, cpu_stats_t *curr)
{
    long total = 0;

    total += curr->user - prev->user;
    total += curr->nice - prev->nice;
    total += curr->system - prev->system;
    total += curr->idle - prev->idle;
    total += curr->iowait - prev->iowait;
    total += curr->irq - prev->irq;
    total += curr->softirq - prev->softirq;
    total += curr->steal - prev->steal;
    return total;
}

static void set_cpu_percents(cpu_stats_t *prev, cpu_stats_t *curr,
    display_data_t *data, long total)
{
    data->cpu_us = ((curr->user - prev->user) * 100.0) / total;
    data->cpu_sy = ((curr->system - prev->system) * 100.0) / total;
    data->cpu_ni = ((curr->nice - prev->nice) * 100.0) / total;
    data->cpu_id = ((curr->idle - prev->idle) * 100.0) / total;
    data->cpu_wa = ((curr->iowait - prev->iowait) * 100.0) / total;
    data->cpu_hi = ((curr->irq - prev->irq) * 100.0) / total;
    data->cpu_si = ((curr->softirq - prev->softirq) * 100.0) / total;
    data->cpu_st = ((curr->steal - prev->steal) * 100.0) / total;
}

int calc_cpu_percent(cpu_stats_t *prev, cpu_stats_t *curr,
    display_data_t *data)
{
    long total;

    total = calc_total_diff(prev, curr);
    if (total > 0) {
        set_cpu_percents(prev, curr, data, total);
        *prev = *curr;
    }
    return 0;
}
