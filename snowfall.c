#include <stdlib.h>				// srand, rand
#include <stdio.h>				// i/o
#include <time.h>				// time (seeding)
#include <unistd.h>				// sleep
int main(int argc, char *argv[]) {
	int worldWidth = argc > 1 ? atoi(argv[1]) : 80,
		worldHeight = argc > 2 ? atoi(argv[2]) : 30,
		snowflakeSpawnChance = argc > 3 ? atoi(argv[3]) : 3,
		sleepDuration = argc > 4 ? atoi(argv[4]) : 300;
	srand(time(0));																// seed rand
	char world[worldHeight * worldWidth];										// populate world w empty space & newlines
	for(int i = 0; i < worldHeight * worldWidth; i++) world[i] = i % worldWidth ? ' ' : '\n';
	for(;;) {
		printf("\e[1;1H\e[2J");													// clear frame
		for(int i = worldHeight * worldWidth; i > 0; i--) {						// iterate (backwards to make snow fall properly)
			printf("%c", world[worldHeight * worldWidth - i]);					// render map (backwards to reverse loop)
			switch(world[i]) {
				case '*': case '+': case '.':									// make snowflakes fall & stack
					int dir = rand() % 3 - 1;
					if(world[i + worldWidth + dir] == ' ' && i + worldWidth * 2 < worldWidth * worldHeight) {
						world[i + worldWidth + dir] = world[i];
						world[i] = ' ';
					}
					break;
			}																	// spawn snowflakes (focus *) under right conditions
			if(i < worldWidth && world[i + worldWidth] == ' ' && rand() % 100 < snowflakeSpawnChance) world[i] = rand()%2 == 0 ? '*' : rand()%2 == 0 ? '.' : '+';
		}
		usleep(sleepDuration * 1000);											//sleep
	}
	return 0;
} // don't forget to make kanye with brandon in ds3