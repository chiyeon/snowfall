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

Snowfall has support for most linux distros, macOS, and Windows. There are two versions, one in Javascript and one in C, but both function identically to one another.

# Installation
Note: This installs the Javascript version of snowfall.

### From npm
```console
npm -g i @chiyeon/snowfall
```

### From Source
Note: This installs the C version of snowfall.

```console
git clone https://github.com/chiyeon/snowfall
cd snowfall

# only on unix systems
./install.sh

# manually compile on windows
gcc -o snowfall snowfall.c
```
Running `install.sh` will install to `/usr/local/bin`. Requires sudo priviliges.

If installing locally without sudo, add the `-l` flag to the `install.sh` script to install it in `$HOME/.local/share` instead.

Note: Either of these directories should be in your `$PATH`! If all else fails, running the install script should leave an executable file simply named `snowfall` in the git directory. Run it with `./snowfall`!

If installing on Windows, it is recommended to simply use `npm`. If not, use gcc to compile.

# Configuration
Snowfall has a total of four optional arguments. Run with the help flag (`snowfall -H` or `snowfall --help`) to view the help menu. The flags are case-sensitive!

### arguments
 - `[-w/--width <width>]`: The width of the simulation in characters (Default: 80)
 - `[-h/--height <height>]`: The height of the simulation in characters (Default: 30)
 - `[-c/--chance <chance>]`: The spawn chance (in percent) of snowflakes per tick (Default: 3)
 - `[-d/--duration <duration>]`: The duration (in milliseconds) of each tick (Default: 300)
