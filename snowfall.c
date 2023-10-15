#include <stdlib.h>        // srand, rand
#include <stdio.h>         // i/o
#include <time.h>          // time (seeding)
#include <string.h>        // strcmp
#define is_arg(t, as, al) !strcmp(t, as) || !strcmp(t, al)
#ifdef _WIN32              // sleep
   #include <windows.h> 
   #define cls() printf("\033c")
   #define sleep(t) Sleep(t)
#else
   #include <unistd.h>
   #define cls() printf("\e[1;1H\e[2J")
   #define sleep(t) usleep(t * 1000)
#endif
int main(int argc, char *argv[]) {
   int ww = 80, wh = 30, ssc = 3, sd = 300;   // initialize with default values
   if (argc > 1) {   // if arguments presented, filter & assign as needed
      for (int i = 0; i < argc - 1; ++i) {
         if (is_arg(argv[1], "-H", "--help") == 1) {
            printf("USAGE: snowfall [-w/--width <width>] [-h/--height <height>] [-c/--chance <chance>] [-d/--duration <duration>]\n\nAll command line arguments are OPTIONAL.\n\n               -H/--help: Prints this help menu\n      -w/--width <width>: Sets the World Width (default: 80)\n    -h/--height <height>: Sets the World Height (default: 30)\n    -c/--chance <chance>: Sets the snowflake spawn chance (percent per tick) (default: 3)\n-d/--duration <duration>: Sets the duration (in ms) of each tick (default: 300)\n");
            return 0;
         }
         else if (is_arg(argv[i], "-w", "--width")) ww    = atoi(argv[i+1]);
         else if (is_arg(argv[i], "-H", "--height")) wh   = atoi(argv[i+1]);
         else if (is_arg(argv[i], "-c", "--chance")) ssc  = atoi(argv[i+1]);
         else if (is_arg(argv[i], "-d", "--duration")) sd = atoi(argv[i+1]);
      }
   }
   srand(time(0));
   char w[wh * ww];   // create world & populate with emptiness
   for (int i = 0; i < wh * ww; ++i) w[i] = i % ww ? ' ' : '\n';
   for (;;) {
      cls();               // clear frame
      printf("%s", w);   // render world
      for (int i = wh * ww; i > 0; --i) {   // iterate (backwards to make snow fall properly)
         if (w[i] == '*' || w[i] == '+' || w[i] == '.') {   // make snowflakes fall & stack
            int d = rand() % 3 - 1;
            if (w[i + ww + d] == ' ' && i + ww * 2 < ww * wh) {
               w[i + ww + d] = w[i];
               w[i] = ' ';
            }
         }   // spawn snowflakes (focus *) under right conditions
         if (i < ww && w[i + ww] == ' ' && rand() % 100 <= ssc) 
            w[i] = rand()%2 == 0 ? '*' : rand()%2 == 0 ? '.' : '+';
      }
      sleep(sd);   // sleeeeep
   }
   return 0;
}   // don't forget to make kanye with brandon in ds3 (we forgot :<)
