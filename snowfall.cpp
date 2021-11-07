#include <cstdlib>					// srand, rand, clear
#include <cstdio>					// i/o
#include <time.h>					// time (seeding)
#include <chrono>					// millisecond conversion
#include <thread>					// sleeping thread
//config : length of each 'frame'; chance for each top tile to spawn a snowflake; world dimensions
int sleepDuration = 300, snowflakeSpawnChance = 3, worldWidth = 80, worldHeight = 30;
int main() {
	srand(time(0));
	char world[worldHeight * worldWidth];
	for(int i = 0; i < worldHeight * worldWidth; i++)										// populate world w empty space & newlines
		world[i] = i % worldWidth ? ' ' : '\n';
	for(;;) {
		system("clear");																	// clear new frame
		for(int i = worldHeight * worldWidth; i > 0; i--) {									// iterate (backwards to make snow fall evenly)
			printf("%c", world[worldHeight * worldWidth - i]);								// render map (backwards to reverse loop)
			switch(world[i]) {
				case '*':
				case '.':																	// make snowflakes fall
					if(world[i + worldWidth] == ' ') {
						world[i + worldWidth] = world[i];
						world[i] = ' ';
					}
					break;
			}																				// spawn new snowflakes under right conditions
			if(i < worldWidth * 2 && world[i - worldWidth] == ' ' && rand() % 100 < snowflakeSpawnChance) world[i] = rand() % 2 == 0 ? '*' : '.';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));				// sleep
	}
	return 0;
} // don't forget to make kanye with brandon in ds3