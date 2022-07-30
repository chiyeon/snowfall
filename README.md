# snowfall
a little program that simulates snowfall in about 50 lines, right in your gnu/linux terminal !

![snowfall preview](./imgs/preview.png)

# Installation
Simply run the `install.sh` script to install snowfall to `$HOME/.local/share`. If installing system-wide as superuser, add the `-g` flag to the `install.sh` script to install it in `/usr/local/bin` instead.

Note: Either of these directories should be in your $PATH! If all else fails, running the install script should leave an executable file simply named `snowfall` in the git directory. Run it with `./snowfall`!

# configuration
Snowfall has a total of four optional arguments. Run with the help flag (`snowfall -h` or `snowfall --help`) to view the help menu. The flags are case-sensitive!

### arguments
 - `[-W/--width <width>]`: The width of the simulation in characters (Default: 80)
 - `[-H/--height <height>]`: The height of the simulation in characters (Default: 30)
 - `[-c/--chance <chance>]`: The spawn chance (in percent) of snowflakes per tick (Default: 3)
 - `[-d/--duration <duration>]`: The duration (in milliseconds) of each tick (Default: 300)
 
### examples
| **small square** | **tall rectangle** |
| ---------------- | ------------------- |
| `./snowfall.o -W 30 -H 15` | `./snowfall.o -W 25 -H 25 -c 10 -d 100` |
| ![custom preview](./imgs/small_square.png) | ![custom preview 2](./imgs/column.png) |
