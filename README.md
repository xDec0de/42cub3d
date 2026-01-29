# 42cub3d ![Workflow status](https://github.com/xdec0de/42cub3d/actions/workflows/validate.yml/badge.svg)

A basic 3D raycasting engine in C inspired by Wolfenstein 3D.
Parses .cub map files and renders walls with textures using the MiniLibX graphics library.

Detailed code quality and coverage stats can be found
[here](https://app.codacy.com/gh/xDec0de/42cub3d). Keep in mind that as this is a project
made for the 42 cursus, it follows the [norminette](https://github.com/42School/norminette)
coding style. I mention this mainly to justify the bad practices we are *forced* to
use at `.h` files for colored messages (Not having macros for colors). If you are curious
about why, read [this issue](https://github.com/42school/norminette/issues/534).

## Dependencies

For this project, the use of the [MiniLibX library](https://github.com/42Paris/minilibx-linux)
is mandatory. Which means that you need to install it along with its dependencies. We've made
that process easier for you, so you only need to run two commands:

- `make submodules` - Clones all submodules and compiles the MiniLibX library for you.
- `make` - Compiles Cub3d itself.

You need at least GCC 11 to compile this project. The MiniLibX Library can't be
installed with GCC 15, which is why `make submodules` forces it to use GCC 11
so you don't have to figure that out.

Please refer to the MiniLibX library's [github page](https://github.com/42Paris/minilibx-linux)
to learn about its dependencies if you encounter errors with `make submodules`.

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
| mlx_init | Initializes the graphical context |
| mlx_new_window | Creates a new window |
| mlx_hook | Registers an event handler on a window |
| mlx_loop | Starts the event loop |
| mlx_new_image | Creates a new empty image buffer |
| mlx_get_data_addr | Returns a pointer to an image’s pixel buffer |
| mlx_put_image_to_window | Displays an image buffer in a window at the given position |
| mlx_loop_hook | Registers a function that is called repeatedly on each loop iteration |


And the whole math library. Once again, this table only contains those
functions we used from it

| Name | Basic description |
| :---: | :---: |
| cos | Returns the cosine of an angle (in radians) |
| sin | Returns the sine of an angle (in radians) |
| atan2 | Returns the angle (in radians) of the vector |

## Debug mode

You can toggle between the 2D debug view and the 3D raycasting view by changing the `DEBUG`
macro in `cb_render.h`:

- `#define DEBUG 1` → 2D debug mode (draws the map/player and the casted rays)
- `#define DEBUG 0` → 3D mode (renders the scene from the player point of view)

> Note: This is a development helper macro and may be removed/disabled in the final version.

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
| -3 | ERRC_MLX_INIT_FAIL | MLX initialization failure |
| -4 | ERRC_WINDOW_INIT_FAIL | Window intialization failure |
| -5 | ERRC_IMG_CREATION_FAIL | Image creation failure |
