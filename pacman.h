#pragma once
#include "raylib.h"
#include "map.h"

class PacMan {
private:
	Vector2 WorldLocation;
	Texture2D texture;
    	float width;
	float height;
	float speed;
	static const int window_width = 750;
	static const int window_height = 1000;
	Map &map;
        Rectangle pacman;
        int pellets;
public:
	PacMan(Map& m, float w, float h) : map(m), width(w), height(h) {
		texture = LoadTexture("images/pacman.png");
		WorldLocation = {203.0f, 363.0f};
		speed = 1.5;
	        pellets = 169;
	}
	~PacMan() {
		UnloadTexture(texture);
	}
		
	Vector2 GetWorldLocation() const { return WorldLocation; } 
	
	void Draw() const {
		Vector2 position = {WorldLocation.x, WorldLocation.y};
		Vector2 size = {width / texture.width, height / texture.height};
		DrawTextureEx(texture, position, 0.0f, size.x, YELLOW);
	}

	void Movement() {
   	     Rectangle nextRect = {WorldLocation.x, WorldLocation.y, width, height};
//	std::cout << "(" << WorldLocation.x << ", " << WorldLocation.y << ")" << std::endl;
        if (IsKeyDown(KEY_LEFT)) {
                nextRect.x -= speed;
            //if (!map.Collision(nextRect)) {
                WorldLocation.x -= speed;
            //}
        } else if (IsKeyDown(KEY_RIGHT)) {
            nextRect.x += speed;
            //if (!map.Collision(nextRect)) {
                WorldLocation.x += speed;
           // }
        } else if (IsKeyDown(KEY_DOWN)) {
            nextRect.y += speed;
            //if (!map.Collision(nextRect)) {
                WorldLocation.y += speed;
           //}
        } else if (IsKeyDown(KEY_UP)) {
            nextRect.y -= speed;
            //if (!map.Collision(nextRect)) {
                WorldLocation.y -= speed;
            //}
        }
	     //Create a copy of pacman and its live location into a rectangle for easier collison checking with the pellets
	     pacman = {WorldLocation.x, WorldLocation.y, width, height};
    	}     

void EatPellets() {
                         //std::cout << "Pellets: " << pellets << std::endl;
	for (int row = 0; row < map.GetWorldMap().size(); row++) {
		for (int col = 0; col < map.GetWorldMap()[0].size(); col++) {
			//if a collision occurs between pacman and the pellet then clear that space
			if (map.GetWorldMap()[row][col] == '.') {
                        float pelletX = col * map.GetCellSize() + map.GetCellSize() / 2;
                        float pelletY = row * map.GetCellSize() + map.GetCellSize() / 2;
                    	Rectangle pelletRect = {pelletX - map.GetPelletRadius(), pelletY - map.GetPelletRadius(), map.GetPelletRadius() * 2, map.GetPelletRadius() * 2};
                        if (CheckCollisionRecs(pacman, pelletRect)) {
				map.GetWorldMap()[row][col] = ' ';
				std::cout << "Pellets: " << pellets << std::endl;
				pellets --;
				}
                	}
		}		 
	 }
   }    

};	
