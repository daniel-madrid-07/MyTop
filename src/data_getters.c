/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Data gathering functions
*/

#include "../include/my.h"

int get_loadavg(float *load1, float *load5, float *load15)
{
    FILE *file;

    file = fopen("/proc/loadavg", "r");
    if (file == NULL) {
        *load1 = 0;
        *load5 = 0;
        *load15 = 0;
        return 0;
    }
    fscanf(file, "%f %f %f", load1, load5, load15);
    fclose(file);
    return 0;
}

int get_uptime(int *uptime)
{
    FILE *file;

    file = fopen("/proc/uptime", "r");
    if (file == NULL) {
        *uptime = 0;
        return 0;
    }
    fscanf(file, "%i", uptime);
    fclose(file);
    return 0;
}

int get_user_count(void)
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir("/run/user");
    if (dir == NULL)
        return 0;
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] != '.')
            count++;
        entry = readdir(dir);
    }
    closedir(dir);
    return count;
}
