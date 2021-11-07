#include <cstdlib>					// srand, rand, cls
#include <cstdio>					// I/O
#include <time.h>					// time
#include <chrono>					// sleeping
#include <thread>
//config
int sleepDuration = 100, snowflakeSpawnChance = 3, worldWidth = 80, worldHeight = 30;		// sleepDuration: ms between frames; spawn chance: % chance per tile to spawn *
int main() {
	srand (time(0));
	printf("enjoy the shnow :)\n\n");
	char world[worldHeight][worldWidth];
	for(int y = 0; y < worldHeight; y++) {
		for(int x = 0; x < worldWidth; x++) {
			world[y][x] = x == worldWidth - 1 ? '\n' : ' ';
		}
	}
	for(;;) {
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
		system("clear");
		for(int y = worldHeight; y > 0; y--) {										// iterate thru map
			for(int x = 0; x < worldWidth; x++) {								
				switch(world[y][x]) {
					case '.':
					case '*':
					case 'o':
						if(world[y+1][x] == ' ') {
							world[y+1][x] = world[y][x];
							world[y][x] = ' ';
						}
						break;
						/*
						world[y][x] = ' ';
						if(world[y+1][x] == ' ') world[y+1][x] = '*';		// move down when space
						if(world[y+1][x] == '#') world[y][x] = '.';			// particles when not
						if(world[y+1][x] == '.') world[y+1][x] = '#'; */
				}
				printf("%c", world[worldHeight - y][x]);								// print character
				// if top row && within x bounds && chance && no snowflake below...spawn a snowflake!
				//if(y == 1 && x > 3 && x < 40 && rand() % 100 < snowflakeSpawnChance && world[y+1][x] != '*') world[y][x] = '*';
				//if(y == 1 && x > 3 && x < 40 && world[y+1][x] == ' ' && rand() % 100 < snowflakeSpawnChance) world[y][x] = rand() % 2 == 0 ? '*' : 'o';
				if(y == 1 && x > 0 && x < worldWidth && world[y+1][x] == ' ' && rand() % 100 < snowflakeSpawnChance) {
					int c = rand() % 2;
					if(c == 0) {
						world[y][x] = '*';
					} else if(c == 1) {
						world[y][x] = '.';
					} else {
						world[y][x] = 'o';
					}
				}
			}
		}
	}
	return 0;
} // don't forget to make kanye with brandon in ds3
