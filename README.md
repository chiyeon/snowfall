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

Snowfall has support for most linux distros, macOS, and Windows.

# Installation
Note: This installs the Javascript version of snowfall.

### From npm
```console
npm -g i @chiyeon/snowfall
```

# Configuration
Snowfall has a total of four optional arguments. Run with the help flag (`snowfall -h` or `snowfall --help`) to view the help menu. The flags are case-sensitive!

### arguments
 - `[-W/--width <width>]`: The width of the simulation in characters (Default: 80)
 - `[-H/--height <height>]`: The height of the simulation in characters (Default: 30)
 - `[-c/--chance <chance>]`: The spawn chance (in percent) of snowflakes per tick (Default: 3)
 - `[-d/--duration <duration>]`: The duration (in milliseconds) of each tick (Default: 300)
