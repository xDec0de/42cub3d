# 42cub3d ![Workflow status](https://github.com/xdec0de/42cub3d/actions/workflows/validate.yml/badge.svg)

A basic 3D raycasting engine in C inspired by Wolfenstein 3D.
Parses .cub map files and renders walls with textures using the MiniLibX graphics library.

Detailed code quality and coverage stats can be found
[here](https://app.codacy.com/gh/xDec0de/42cub3d). Keep in mind that as this is a project
made for the 42 cursus, it follows the [norminette](https://github.com/42School/norminette)
coding style. I mention this mainly to justify the bad practices we are *forced* to
use at `.h` files for colored messages (Not having macros for colors). If you are curious
about why, read [this issue](https://github.com/42school/norminette/issues/534).

## Allowed functions

As always, we are limited to a few functions to complete this task.
For this project, we are allowed to use some of the functions we already know.

| Name | Library | Basic description | Used |
| :---: | :---: | :---: | :---: |
| [open](https://linux.die.net/man/3/open) | fcntl.h | Open a file | ✅ |
| [close](https://linux.die.net/man/2/close) | unistd.h | Close a file descriptor | ✅ |
| [read](https://linux.die.net/man/3/read) | unistd.h | Read from a file | ✅ |
| [write](https://linux.die.net/man/3/write) | unistd.h | Write on a file | ❌ |
| [printf](https://linux.die.net/man/3/printf) | stdio.h | Formatted output conversion | ✅ |
| [malloc](https://linux.die.net/man/3/malloc) | stdlib.h | Allocate dynamic memory | ✅ |
| [free](https://linux.die.net/man/3/free) | stdlib.h | Free dynamic memory | ✅ |
| [perror](https://linux.die.net/man/3/perror) | errno.h | Print system error message | ❌ |
| [strerror](https://linux.die.net/man/3/strerror) | string.h | Return string describing error number | ✅ |
| [exit](https://linux.die.net/man/3/exit) | stdlib.h | Cause normal process termination | ✅ |
| [gettimeofday](https://linux.die.net/man/2/gettimeofday) | sys/time.h | Get current system time | ❌ |

The whole [MiniLibX library](https://github.com/42Paris/minilibx-linux). This
table only contains those functions we used from it.

| Name | Basic description |
| :---: | :---: |
| ... | ... |

And the whole math library. Once again, this table only contains those
functions we used from it

| Name | Basic description |
| :---: | :---: |
| ... | ... |

## Exit codes

Here is the exit code table of the program. This exists mainly to ensure consistency in
the exit codes of our program. Input / user errors are all positive integers, while
internal program errors are all negative integers.

| Exit code | Macro | Description |
| :---: | :---: | :---: |
| 0 | EXIT_SUCCESS | Program executed successfully |
| 1 | ERRC_ARGC | Invalid program argument count |
| 2 | ERRC_MAP_FILE_EXTENSION | Provided map file name doesn't end with '.cub' |
| 3 | ERRC_MAP_OPEN_MAP | Failed to open map file (Most likely it doesn't exist) |
| -1 | ERRC_MALLOC_FAIL | Malloc failed |
| -2 | ERRC_READ_FAIL | Read failed |
