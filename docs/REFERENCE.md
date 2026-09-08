# MyTop — technical reference

## Architecture

```
MyTop/
├── src/                          # Main implementation
│   ├── main.c                   # Entry point
│   ├── loop.c                   # Main event loop
│   ├── parse_args.c             # Command-line parsing
│   ├── parse.c                  # /proc file parsing
│   ├── print.c                  # ncurses rendering
│   ├── cpu_info.c               # CPU statistics gathering
│   ├── mem_info.c               # Memory information
│   ├── task_info.c              # Process/task counting
│   ├── data_getters.c           # System data collection
│   ├── ncurses_utils.c          # Terminal utilities
│   └── help.c                   # Help text
├── include/                      # Headers
│   ├── my.h                     # Main header file
│   ├── my_printf.h               # Printf header
│   └── other_functions.h         # String utilities header
├── my_printf/                    # Custom printf implementation
│   ├── include/
│   │   └── my_printf.h
│   └── src/                     # Printf source files (format handlers)
├── other_functions/              # String utility functions
└── Makefile
```

### Core data types

- **flags_t** — command-line flags and options (user filter, delay, frame count, password)
- **display_data_t** — all system statistics for display (CPU %, memory, tasks, uptime)
- **cpu_stats_t** — raw CPU statistics from `/proc/stat` (user, system, nice, idle, I/O wait, etc.)

## Display format

```
 top - <uptime> up <days d, hh:mm>, <users> users, load average: <1m> <5m> <15m>
 Tasks: <total> total, <running> running, <sleeping> sleeping, <stopped> stopped, <zombie> zombie
 %Cpu(s): <us>% us, <sy>% sy, <ni>% ni, <wa>% wa, <hi>% hi, <si>% si, <st>% st, <id>% id
 KiB Mem: <total> total, <free> free, <used> used, <available> available
 KiB Swap: <total> total, <free> free, <used> used
```

## How it works

1. Initialization — parse arguments, set up ncurses terminal
2. Data collection — read `/proc/uptime`, `/proc/loadavg`, `/proc/stat`, `/proc/meminfo`, `/proc/*/stat`
3. Calculation — compute CPU percentages, memory conversions, task statistics
4. Rendering — display formatted data using ncurses
5. Loop — sleep for configured interval, repeat until exit or frame limit reached
6. Cleanup — restore terminal state and free resources

## Linux /proc files used

- `/proc/uptime` — system uptime in seconds
- `/proc/loadavg` — load averages (1, 5, 15 minutes)
- `/proc/stat` — CPU statistics
- `/proc/meminfo` — memory and swap information
- `/proc/[PID]/stat` — individual process statistics
- `/etc/passwd` — user database (for `-U` option)

## System metrics explained

CPU usage:
- **us%** — user processes
- **sy%** — system kernel
- **ni%** — nice (lower priority processes)
- **wa%** — I/O wait
- **hi%** — hardware interrupts
- **si%** — software interrupts
- **st%** — steal time (VM overhead)
- **id%** — idle (unused)

Memory types:
- **Total** — all installed RAM
- **Free** — completely unused
- **Used** — currently allocated
- **Available** — can be allocated without swapping

Task states:
- **R** — running
- **S/D/I** — sleeping
- **T/t** — stopped
- **Z** — zombie

## Supported options

| Flag | Argument | Purpose |
|------|----------|---------|
| `-U` | username | Monitor processes of specific user only |
| `-d` | seconds | Refresh interval (can be fractional) |
| `-n` | frames | Exit after N updates |
| `-h` | - | Display help information |

## Notes

- Requires a Linux system (uses the `/proc` filesystem)
- Root privileges not required for basic functionality
- ncurses must be installed (`apt-get install libncurses-dev` on Debian/Ubuntu)
- CPU percentages are calculated between updates
- Memory display unit can be adjusted via code compilation
