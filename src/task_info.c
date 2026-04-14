/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Task info functions
*/

#include "../include/my.h"

static void init_task_counts(display_data_t *data)
{
    data->tasks_total = 0;
    data->tasks_running = 0;
    data->tasks_sleeping = 0;
    data->tasks_stopped = 0;
    data->tasks_zombie = 0;
}

static void count_task_state(char state, display_data_t *data)
{
    if (state == 'R')
        data->tasks_running++;
    if (state == 'S' || state == 'D' || state == 'I')
        data->tasks_sleeping++;
    if (state == 'T' || state == 't')
        data->tasks_stopped++;
    if (state == 'Z')
        data->tasks_zombie++;
    data->tasks_total++;
}

static void process_entry(struct dirent *entry, display_data_t *data)
{
    FILE *file;
    char path[267];
    char state;

    if (!my_isdigit(entry->d_name[0]))
        return;
    sprintf(path, "/proc/%s/stat", entry->d_name);
    file = fopen(path, "r");
    if (file == NULL)
        return;
    fscanf(file, "%*d %*s %c", &state);
    fclose(file);
    count_task_state(state, data);
}

int get_tasks(display_data_t *data)
{
    DIR *dir;
    struct dirent *entry;

    init_task_counts(data);
    dir = opendir("/proc/");
    if (dir == NULL)
        return 0;
    entry = readdir(dir);
    while (entry != NULL) {
        process_entry(entry, data);
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}
