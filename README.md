# My Top 2 📊

**A terminal-based system monitoring utility built with ncurses** — Real-time display of CPU, memory, task statistics, and system uptime in an interactive console interface.

## Overview

My Top 2 is a C implementation of the Unix `top` command, providing real-time system monitoring through a terminal user interface. It reads Linux `/proc` filesystem data to display CPU usage, memory consumption, task counts, system load averages, and uptime. The application uses ncurses for interactive terminal rendering with support for user filtering, custom refresh intervals, and adjustable output formatting.

## Features

🖥️ **System Information:**
- 📈 **CPU Statistics** - Real-time user, system, I/O wait, and idle CPU percentages
- 💾 **Memory Monitoring** - Total, used, free, and available memory with configurable units (KB/MB/GB)
- ⚡ **Task Status** - Running, sleeping, stopped, and zombie process counts
- 📊 **Load Averages** - 1, 5, and 15-minute system load metrics
- ⏱️ **System Uptime** - Days, hours, minutes display format

## Command-Line Options:
- `-U <username>` - Filter processes for specific user
- `-d <seconds>` - Set custom refresh interval (delay between updates)
- `-n <frames>` - Display only N frames then exit
- `-h` - Show help information

## Architecture

```
MyTop2/
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
│   ├── my_printf.h              # Printf header
│   └── other_functions.h        # String utilities header
├── my_printf/                    # Custom printf implementation
│   ├── include/
│   │   └── my_printf.h
│   └── src/                     # Printf source files (format handlers)
├── other_functions/             # String utility functions
└── Makefile
```

## Data Structures

### Core Types
- **flags_t** - Command-line flags and options (user filter, delay, frame count, password)
- **display_data_t** - All system statistics for display (CPU %, memory, tasks, uptime)
- **cpu_stats_t** - Raw CPU statistics from `/proc/stat` (user, system, nice, idle, I/O wait, etc.)

## Building

```bash
# Build the application
make

# Clean object files
make clean

# Remove all build artifacts
make fclean

# Rebuild from scratch
make re

# Build with debug symbols
make debug
```

### Requirements
- **Compiler**: Clang/GCC with C99 support
- **Dependencies**:
  - ncurses library (for terminal UI)
  - Standard C libraries
  - Linux `/proc` filesystem access

## Usage

```bash
# Run with default settings (1-second refresh)
./my_top

# Filter processes for specific user
./my_top -U username

# Custom refresh interval (0.5 seconds)
./my_top -d 0.5

# Display only 10 frames then exit
./my_top -n 10

# Combine options
./my_top -U root -d 2.0 -n 5

# Show help
./my_top -h
```

### Display Format

The console displays:
```
 top - <uptime> up <days d, hh:mm>, <users> users, load average: <1m> <5m> <15m>
 Tasks: <total> total, <running> running, <sleeping> sleeping, <stopped> stopped, <zombie> zombie
 %Cpu(s): <us>% us, <sy>% sy, <ni>% ni, <wa>% wa, <hi>% hi, <si>% si, <st>% st, <id>% id
 KiB Mem: <total> total, <free> free, <used> used, <available> available
 KiB Swap: <total> total, <free> free, <used> used
```

## How It Works

1. **Initialization** - Parse arguments, setup ncurses terminal
2. **Data Collection** - Read `/proc/uptime`, `/proc/loadavg`, `/proc/stat`, `/proc/meminfo`, `/proc/*/stat`
3. **Calculation** - Compute CPU percentages, memory conversions, task statistics
4. **Rendering** - Display formatted data using ncurses
5. **Loop** - Sleep for configured interval, repeat until exit or frame limit reached
6. **Cleanup** - Restore terminal state and free resources

## Linux /proc Files Used

- `/proc/uptime` - System uptime in seconds
- `/proc/loadavg` - Load averages (1, 5, 15 minutes)
- `/proc/stat` - CPU statistics
- `/proc/meminfo` - Memory and swap information
- `/proc/[PID]/stat` - Individual process statistics
- `/etc/passwd` - User database (for -U option)

## Project Stats

- **Lines of Code**: ~551 (core implementation)
- **Project Size**: ~660KB
- **Language**: C (C99 standard)
- **UI Framework**: ncurses
- **Build System**: Make
- **Target**: Linux systems

## Technical Highlights

✨ **Key Features:**
- **Real-Time Updates** - Configurable refresh intervals
- **/proc Parsing** - Direct Linux kernel interface for accurate data
- **User Filtering** - getpwnam() for username validation
- **Memory Unit Conversion** - Flexible KB/MB/GB display
- **ncurses Terminal UI** - Interactive console rendering
- **CPU Percentage Calculation** - Delta-based CPU metrics
- **Custom printf** - Lightweight formatted output

## System Metrics Explained

### CPU Usage
- **us%** - User processes
- **sy%** - System kernel
- **ni%** - Nice (lower priority processes)
- **wa%** - I/O Wait
- **hi%** - Hardware interrupts
- **si%** - Software interrupts
- **st%** - Steal time (VM overhead)
- **id%** - Idle (unused)

### Memory Types
- **Total** - All installed RAM
- **Free** - Completely unused
- **Used** - Currently allocated
- **Available** - Can be allocated without swapping

### Task States
- **R** - Running
- **S/D/I** - Sleeping
- **T/t** - Stopped
- **Z** - Zombie

## Supported Options

| Flag | Argument | Purpose |
|------|----------|---------|
| `-U` | username | Monitor processes of specific user only |
| `-d` | seconds | Refresh interval (can be fractional) |
| `-n` | frames | Exit after N updates |
| `-h` | - | Display help information |

## Notes

- Requires Linux system (uses `/proc` filesystem)
- Root privileges not required for basic functionality
- ncurses must be installed (`apt-get install libncurses-dev` on Debian/Ubuntu)
- CPU percentages are calculated between updates
- Memory display unit can be adjusted via code compilation

## Credits

Epitech Unix System Programming Project (2022)

---

**Project Type**: System Administration / Terminal UI  
**Difficulty**: Intermediate  
**Key Concepts**: Process Management, System Calls, File Parsing, Terminal UI (ncurses), Linux /proc interface
