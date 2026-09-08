<div align="center">

# MyTop

**A terminal-based system monitoring utility built with ncurses.**

</div>

---

## What it does

MyTop is a C implementation of the Unix `top` command, providing real-time system monitoring
through a terminal user interface. It reads Linux `/proc` filesystem data to display CPU usage,
memory consumption, task counts, system load averages, and uptime, with support for user
filtering, custom refresh intervals, and adjustable output formatting.

## Features

- **CPU statistics** — real-time user, system, I/O wait, and idle CPU percentages
- **Memory monitoring** — total, used, free, and available memory (KB/MB/GB)
- **Task status** — running, sleeping, stopped, and zombie process counts
- **Load averages & uptime** — 1/5/15-minute load, formatted system uptime
- **Command-line options** — filter by user (`-U`), custom refresh interval (`-d`), frame limit (`-n`)

## Installation / Usage

```bash
make                             # Build
./my_top                         # Run with default settings (1-second refresh)
./my_top -U username -d 0.5 -n 10   # Filter by user, 0.5s refresh, exit after 10 frames
```

Requires a Linux system (uses `/proc`), a C99 compiler, and ncurses (`apt-get install
libncurses-dev` on Debian/Ubuntu). Full architecture, `/proc` file breakdown, and metrics glossary:
**[docs/REFERENCE.md](docs/REFERENCE.md)**.

## Tech stack

C (C99), ncurses, Make, Linux `/proc` filesystem

## License

School project — see [LICENSE](LICENSE)
