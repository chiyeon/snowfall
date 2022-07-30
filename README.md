# snowfall
snowfall in your terminal!

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

# Installation
Simply run the `install.sh` script to install snowfall to `/usr/local/bin`. 

If installing locally without sudo, add the `-l` flag to the `install.sh` script to install it in `$HOME/.local/share` instead.

Note: Either of these directories should be in your `$PATH`! If all else fails, running the install script should leave an executable file simply named `snowfall` in the git directory. Run it with `./snowfall`!

# configuration
Snowfall has a total of four optional arguments. Run with the help flag (`snowfall -h` or `snowfall --help`) to view the help menu. The flags are case-sensitive!

### arguments
 - `[-W/--width <width>]`: The width of the simulation in characters (Default: 80)
 - `[-H/--height <height>]`: The height of the simulation in characters (Default: 30)
 - `[-c/--chance <chance>]`: The spawn chance (in percent) of snowflakes per tick (Default: 3)
 - `[-d/--duration <duration>]`: The duration (in milliseconds) of each tick (Default: 300)
