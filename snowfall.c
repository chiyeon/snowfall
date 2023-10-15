#include <stdlib.h>				// srand, rand
#include <stdio.h>				// i/o
#include <time.h>					// time (seeding)
#include <string.h>				// strcmp

#ifdef _WIN32						// sleep
#include <windows.h>
#define CLEAR() printf("\033c")
#define SLEEP(time) Sleep(time)
#else
#include <unistd.h>
#define CLEAR() printf("\e[1;1H\e[2J")
#define SLEEP(time) usleep(time * 1000)
#endif

int is_arg(char *target, char *arg_short, char *arg_long) {
	return strcmp(target, arg_short) == 0 || strcmp(target, arg_long) == 0;
}

int main(int argc, char *argv[]) {
	int worldWidth = 80, worldHeight = 30, snowflakeSpawnChance = 3, sleepDuration = 300;  // initialize with default values
	if (argc > 1) {   // if arguments presented, filter & assign as needed
		for (int i = 0; i < argc - 1; ++i) {
			if (is_arg(argv[1], "-H", "--help") == 1) {
  				printf("USAGE: snowfall [-w/--width <width>] [-h/--height <height>] [-c/--chance <chance>] [-d/--duration <duration>]\n\nAll command line arguments are OPTIONAL.\n\n               -H/--help: Prints this help menu\n      -w/--width <width>: Sets the World Width (default: 80)\n    -h/--height <height>: Sets the World Height (default: 30)\n    -c/--chance <chance>: Sets the snowflake spawn chance (percent per tick) (default: 3)\n-d/--duration <duration>: Sets the duration (in ms) of each tick (default: 300)\n");
				return 0;
			}
			else if (is_arg(argv[i], "-w", "--width")) worldWidth = atoi(argv[i+1]);
			else if (is_arg(argv[i], "-H", "--height")) worldHeight = atoi(argv[i+1]);
			else if (is_arg(argv[i], "-c", "--chance")) snowflakeSpawnChance = atoi(argv[i+1]);
			else if (is_arg(argv[i], "-d", "--duration")) sleepDuration = atoi(argv[i+1]);
		}
	}
	
	srand(time(0));
	char world[worldHeight * worldWidth];  // create world & populate with emptiness
	for (int i = 0; i < worldHeight * worldWidth; ++i) world[i] = i % worldWidth ? ' ' : '\n';
	for (;;) {
		CLEAR();						// clear frame
		printf("%s", world);		// render world
		for (int i = worldHeight * worldWidth; i > 0; --i) {  // iterate (backwards to make snow fall properly)
			if (world[i] == '*' || world[i] == '+' || world[i] == '.') {   // make snowflakes fall & stack
				int dir = rand() % 3 - 1;
				if (world[i + worldWidth + dir] == ' ' && i + worldWidth * 2 < worldWidth * worldHeight) {
					world[i + worldWidth + dir] = world[i];
					world[i] = ' ';
				}
			}  // spawn snowflakes (focus *) under right conditions
			if (i < worldWidth && world[i + worldWidth] == ' ' && rand() % 100 <= snowflakeSpawnChance) 
				world[i] = rand()%2 == 0 ? '*' : rand()%2 == 0 ? '.' : '+';
		}
		SLEEP(sleepDuration);	// sleeeeep
	}
	return 0;
} // don't forget to make kanye with brandon in ds3 (we forgot :<)
