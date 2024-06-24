#pragma once 
#include "raylib.h"
#include <string>
#include <vector>

class Map {
private:
std::vector<std::string>  WorldMap = {
	"#####################",
        "#.........#.........#",
        "#.BB.BBBB.#.BBBB.BB.#",
        "#...................#",
        "#.BB.B.BBBBBBB.B.BB.#",
      	"#....B....B....B....#",
	"####.BBB  B  BBB.####",
	"   #.B         B.#   ",
	"   #.B  BPPPB  B.#   ",
	"####.   B   B   .####",
	"    .   B   B   .    ", 
	"    .   B   B   .    ",
	"####.B  BBBBB  B.####",
	"   #.B         B.#   ",
	"   #.B	        B.#   ",
	"####.B  BBBBB  B.####",
	"#.........B.........#",
	"#.BBB.BBB.B.BBB.BBB.#",
        "#...B....   ....B...#",
	"#BB.B.B.BBBBB.B.B.BB#",    
	"#.....B...B...B.....#",
	"#.BBBBBBB.B.BBBBBBB.#",
	"#...................#",
	"#####################"
};

Color DarkBlue; 
const int CellSize = 20;
float PelletRadius;
int Pellets;

public:
Map() {
	DarkBlue = {0, 0, 128, 255}; 
	PelletRadius = 2;
}

~Map() {}

std::vector<std::string> &GetWorldMap() { return WorldMap; } 
const int GetCellSize() const { return CellSize; }
float GetPelletRadius() const { return PelletRadius; } 
int GetPelletCount() { return Pellets; }


public:
void Draw() {
        for (int row = 0; row < WorldMap.size(); row++) {
            for (int col = 0; col < WorldMap[row].size(); col++) {
                char c = WorldMap[row][col];
                if (c == '#') {
                    // Draw Walls
                    DrawRectangle(col * CellSize, row * CellSize, CellSize, CellSize, DarkBlue);
                }
	         else if (c == 'B') {
                    DrawRectangle(col * CellSize, row * CellSize, CellSize, CellSize, DarkBlue);
		 }
	         else if (c == 'P') {
                    DrawRectangle(col * CellSize, row * CellSize, CellSize + 5, CellSize, PINK);
		 }
		
		else if (c == '.') {
		    float pelletX = col * CellSize + CellSize / 2;
		    float pelletY = row * CellSize + CellSize / 2;
		    DrawCircle(pelletX, pelletY, PelletRadius, YELLOW);
		    Pellets = Pellets + 1;
		}
            }
        }
    }
 
//will check of the 2D textures (pacman and the ghosts) are within bounds of the map and not going throughs walls
bool Collision(Rectangle rect) const {
        for (int row = 0; row < WorldMap.size(); row++) {
            for (int col = 0; col < WorldMap[row].size(); col++) {
                char c = WorldMap[row][col];
                //check for a wall and call the collision function between the wall and pacman
		   if (c == 'P') continue;
                   if (c == '#' or c == 'B') {
                    Rectangle wallRect = {float(col * CellSize), float(row * CellSize), float(CellSize), float(CellSize)};
                    if (CheckCollisionRecs(rect, wallRect)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

};
