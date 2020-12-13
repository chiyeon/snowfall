#include <stdlib.h>		// srand n rand
#include <cstdio>		// I/O
#include <time.h>		// time()
//#include <cstdlib>		// clear the screen

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif					// for clearing the screen

using namespace std;

char world[14][40] = {
	"_______________________________________",
	"|                                     |",
	"|                                     |",
	"|                                     |",
	"|                                     |",
	"|                                     |",
	"|                                     |",
	"|                            __       |",
	"|                           /  \\      |",
	"|                          /    \\     |",
	"|                         /      \\    |",
	"|       ______           /        \\___|",
	"|______/      \\_________/             |",
	"|_____________________________________|"
};

int main() {
	
	printf("enjoy the shnow :)\n\n");
	
	srand (time(0));
	
	for(;;) {
		system(CLEAR);
		printf("             > snowfall <\n");
		
		// iterate through each character in the map
		for(int y = 14; y > 0; y--) {
			for(int x = 39; x > 0; x--) {
				// render each character
				int printX = 39 - x;
				int printY = 14 - y;
				printf("%c", world[printY][printX]);
				
				// new line when necessary
				if(printX == 38)
					printf("\n");
				
				// randomly spawn snowflakes on the top row
				if(y == 1) {
					if(world[y][x] != '|') {
						if(rand() % 35 == 0) {
							world[y][x] = '*';
							continue;
						}
					}
				}
				
				// character logic
				switch(world[y][x]) {
					case 'v': world[y][x] = '_'; break;		// _ hit particle. reverts back to original state
					case '>': world[y][x] = '/'; break;		// / hit particle. reverts back to original state
					case '<': world[y][x] = '\\'; break;	// \ hit particle. reverts back to original state
					case '*':		// snowflake. Falls down gradually, causes impact particles.
						world[y][x] = ' ';
						if(world[y+1][x] == ' ') {
							world[y+1][x] = '*';
						} else {
							world[y][x] = ' ';
							if(world[y+1][x] == '_') {
								world[y+1][x] = 'v';
							} else if(world[y+1][x] == '/') {
								world[y+1][x] = '>';
							} else if(world[y+1][x] == '\\') {
								world[y+1][x] = '<';
							}
						}
						break;
				}
			}
		}
	}
	return 0;
}
// don't forget to make kanye with brandon in ds3
