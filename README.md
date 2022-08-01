```

                                                           +                  *
 .                    *       .       *                                        
   *                 *                                          *              
                                               __       _ _                    
            .         ___ _ __   _____      __/ _| __ _| | |                   
                     / __| '_ \ / _ \ \ /\ / / |_ / _' | | |                   
                     \__ \ | | | (_) \ V  V /|  _| (_| | | |.        *         
                     |___/_| |_|\___/ \_/\_/ |_|  \__,_|_|_|                  
                                                 *                           * 
*               .                                        .                     
                                                *        .    .                
             *      +      *                                                 + 
  .      ..**+*.            .+*              **              *  +**         *.+
 **. ****.+***+.** +* *   +...*+*+ ***+ . *.+. ****++++* *+...*+.+*.* *+ * +.**
.*++**.***+.**.+.**.****+****++.*.+*****.+.*++*...**+*+*+***+*******.+*+++.*..+
```

A simple snow-simulation in your terminal! Run and watch as the snow piles up, forming a comforting, even snowscape. Now customizable with optional arguments!

Snowfall has support for most linux distros, macOS, and Windows. `gcc` is required.

# Installation
### From npm
```console
npm -g i @chiyeon/snowfall
```

Note: Running `snowfall` for the first time on npm will compile the binary for your system. `gcc` is required to continue.

### From Source
```console
git clone https://github.com/chiyeon/snowfall
cd snowfall

# only on unix systems
./install.sh
```
Running `install.sh` will install to `/usr/local/bin`. Requires sudo priviliges.

If installing locally without sudo, add the `-l` flag to the `install.sh` script to install it in `$HOME/.local/share` instead.

Note: Either of these directories should be in your `$PATH`! If all else fails, running the install script should leave an executable file simply named `snowfall` in the git directory. Run it with `./snowfall`!

If installing on Windows, it is recommended to simply use `npm`. If not, use gcc to compile.

```console
gcc -o snowfall snowfall.c
```

# Configuration
Snowfall has a total of four optional arguments. Run with the help flag (`snowfall -h` or `snowfall --help`) to view the help menu. The flags are case-sensitive!

### arguments
 - `[-W/--width <width>]`: The width of the simulation in characters (Default: 80)
 - `[-H/--height <height>]`: The height of the simulation in characters (Default: 30)
 - `[-c/--chance <chance>]`: The spawn chance (in percent) of snowflakes per tick (Default: 3)
 - `[-d/--duration <duration>]`: The duration (in milliseconds) of each tick (Default: 300)
