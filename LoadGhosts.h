#include <iostream>
#include <cmath>
#include "map.h"
#include <vector>
#include <raylib.h>

class Ghosts {
private:
    Texture2D RedGhost, BlueGhost, PinkGhost, YellowGhost;
    Vector2 RedPosition, BluePosition, PinkPosition, YellowPosition;
    float width;
    float height;
    float speed;
    Map &map;
    PacMan &pacman;
    bool inGhostHouse;
    Vector2 ghostHouseExit;

public:
    Ghosts(Map &m, PacMan &p) : map(m), pacman(p), inGhostHouse(true) {
        RedGhost = LoadTexture("images/RedGhost.png");
        BlueGhost = LoadTexture("images/BlueGhost.png");
        PinkGhost = LoadTexture("images/PinkGhost.png");
        YellowGhost = LoadTexture("images/YellowGhost.png");

        RedPosition = {185, 219};
        BluePosition = {185, 183};
        PinkPosition = {221, 183};
        YellowPosition = {221, 219};

        width = 20;
        height = 20;
        speed = 0.2;

        //Ghost House exit point
        ghostHouseExit = {205, 143};
    }

    ~Ghosts() {
        UnloadTexture(RedGhost);
        UnloadTexture(BlueGhost);
        UnloadTexture(PinkGhost);
        UnloadTexture(YellowGhost);
    }

    void Draw() {
        float redScale = width / RedGhost.width;
        float blueScale = width / BlueGhost.width;
        float pinkScale = width / PinkGhost.width;
        float yellowScale = width / YellowGhost.width;

        DrawTextureEx(RedGhost, RedPosition, 0.0f, redScale, WHITE);
        DrawTextureEx(BlueGhost, BluePosition, 0.0f, blueScale, WHITE);
        DrawTextureEx(PinkGhost, PinkPosition, 0.0f, pinkScale, WHITE);
        DrawTextureEx(YellowGhost, YellowPosition, 0.0f, yellowScale, WHITE);
    }
  //AI, Movement, and collisions from ghosts to pacman will be in "GhostAI.h"
   void RedAI();
   
};
