# snowfall
a little program that simulates snowfall in about 30 lines, right in your terminal !

for gnu/linux

### configuration
snowfall can be configurated with 4 additional arguments when running
they do not all need to be present to run, but they must be in order

they are (in order):
 - world width (number of chars in x direction)
 - world height (number of chars in y direction)
 - snowflake spawn chance (chance per character in top row to spawn a snowflake per tick)
 - sleep duration (number of milliseconds in between ticks)

the defaults are
 - width: 80
 - height: 30
 - spawn chance: 3
 - sleep: 300

here are some examples:
**a small square**
```
./snowfall.o 30 15
```
![custom preview](./imgs/small_square.png)



**a tall rectangle**
```
./snowfall.o 25 25 10 100
```
![custom preview 2](./imgs/column.png)

### preview
![snowfall preview](./imgs/preview_main.png)
