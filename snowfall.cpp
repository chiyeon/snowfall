#include <cstdlib>					// srand, rand, cls
#include <cstdio>					// I/O
#include <time.h>					// time
#ifdef _WIN32			
#include <windows.h>
#define CLS "cls"
#else
#include <unistd.h>
#define CLS "clear"
#endif								// for clearing the screen
#include <chrono>					// sleeping
#include <thread>
// config
int sleepDuration = 750, snowflakeSpawnChance = 3;			// sleepDuration: ms between frames; spawn chance: % chance per tile to spawn *
char world[14][122] = {										// is actually 10 x 40, muiltiply each by 3
	"╔══════════════════════════════════════╗\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║                                      ║\n",
	"║          ████████                    ║\n",
	"║      ██████████████████        ███   ║\n",
	"║ ████████████████████████████████████ ║\n",
	"║ ████████████████████████████████████ ║\n",
	"╚══════════════════════════════════════╝\n"
};
bool test = true;
int i, j;
char tGetch();

int main() {
	srand (time(0));
	printf("enjoy the shnow :)\n\n");
	for(;;) {
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
		system(CLS);
		if(test) {
			unsigned char ahf;
			ahf = 129;
			printf("ahf:%c", ahf);
			printf("thing: |%c%c%c|", world[0][0], world[0][1], world[0][2]);			//test = false;
			printf("thing2: %d", int(world[0][0]));
			printf("br%cuh", char(219));
		}
		printf("              » snowfall «\n");
		for(int y = 14; y > 0; y--) {										// iterate thru map
			for(int x = 0; x < 122; x++) {									
				switch(world[y][x]) {
					case 'v': world[y][x] = ' '; break;						// dissolve hit particle
					case '*':
						world[y][x] = ' ';
						if(world[y+1][x] == ' ') world[y+1][x] = '*';		// move down when space
						//if(&world[y+1][x] == '█') world[y][x] = '▄';								// particles when not
						break;
					case '█':
						world[y][x] = ' ';
						break;
				}

				//if((int)world[y][x] == -30)
				//	world[y][x] = ' ';

				printf("%c", world[14 - y][x]);								// print character
				// if top row && within x bounds && chance && no snowflake below...spawn a snowflake!
				if(y == 1 && x > 3 && x < 40 && rand() % 100 < snowflakeSpawnChance && world[y+1][x] != '*') world[y][x] = '*';
			}
		}
	}
	return 0;
} // don't forget to make kanye with brandon in ds3
