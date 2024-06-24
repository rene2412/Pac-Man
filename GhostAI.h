#include "LoadGhosts.h"
#include <iostream>
#include "raylib.h"
#include <cmath>



void Ghosts::RedAI() {
// how can we implement blinky (red ghost) on this game??
 // If Blinky is in the ghost house, move towards the exit
    if (inGhostHouse) {
        std::cout << "leaving house\n";
	Vector2 direction = {ghostHouseExit.x - RedPosition.x, ghostHouseExit.y - RedPosition.y};
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) {
            direction.x /= length;
            direction.y /= length;
        }

        RedPosition.x += direction.x * speed;
        RedPosition.y += direction.y * speed;

        // Check if Blinky has reached the ghost house exit
        if (fabs(RedPosition.x - ghostHouseExit.x) < speed && fabs(RedPosition.y - ghostHouseExit.y) < speed) {
           std::cout << "entering world\n";
		 inGhostHouse = false; // Blinky has exited the ghost house
        }
    }
}

