/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Memory info functions
*/

#include "../include/my.h"

static void parse_mem_line(char *line, display_data_t *data)
{
    if (strncmp(line, "MemTotal:", 9) == 0)
        sscanf(line, "MemTotal: %ld", &data->mem_total);
    if (strncmp(line, "MemFree:", 8) == 0)
        sscanf(line, "MemFree: %ld", &data->mem_free);
    if (strncmp(line, "Buffers:", 8) == 0)
        sscanf(line, "Buffers: %ld", &data->mem_buffers);
    if (strncmp(line, "MemAvailable:", 13) == 0)
        sscanf(line, "MemAvailable: %ld", &data->mem_available);
    if (strncmp(line, "Cached:", 7) == 0)
        sscanf(line, "Cached: %ld", &data->mem_cached);
}

static void parse_swap_line(char *line, display_data_t *data)
{
    if (strncmp(line, "SwapTotal:", 10) == 0)
        sscanf(line, "SwapTotal: %ld", &data->swap_total);
    if (strncmp(line, "SwapFree:", 9) == 0)
        sscanf(line, "SwapFree: %ld", &data->swap_free);
}

int get_mem_info(display_data_t *data)
{
    FILE *file;
    char line[256];

    file = fopen("/proc/meminfo", "r");
    if (file == NULL)
        return 0;
    while (fgets(line, 256, file) != NULL) {
        parse_mem_line(line, data);
        parse_swap_line(line, data);
    }
    data->mem_used = data->mem_total - data->mem_free
        - data->mem_buffers - data->mem_cached;
    data->swap_used = data->swap_total - data->swap_free;
    fclose(file);
    return 0;
}
