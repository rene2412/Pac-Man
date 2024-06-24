#include <iostream>
#include "raylib.h"
#include "pacman.h"
#include "GhostAI.h"
#include "map.h"

static const int width = 500;
static const int height = 650;


int main() {
InitWindow(width, height, "Pac-Man");
SetTargetFPS(60);
float pwidth = 15;
float pheight = 15;
Map map;
PacMan pacman(map, pwidth, pheight);
Ghosts ghosts(map, pacman);
map.Draw();
//std::cout << map.GetPelletCount() << std::endl;
//exit(1);
while(!WindowShouldClose()) {
	pacman.Movement();
	pacman.EatPellets();
	ghosts.RedAI();
	BeginDrawing();
        ClearBackground(BLACK);
	pacman.Draw();
	ghosts.Draw();
	map.Draw();
	//std::cout << map.GetPelletCount() << std::endl;
	EndDrawing();
}
CloseWindow();

}
