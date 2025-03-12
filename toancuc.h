#ifndef TOANCUC_H_
#define TOANCUC_H_

// Khai báo thư viện
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>

using namespace std;

// Các thông số cua so
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
extern const char* WINDOW_TITLE;
// các thông số của cột
extern const int so_col;
// struct Column {
//     int Col_X;
//     int Col_gapY;
//     int Col_W;
//     int Col_gapHeight;
//     int Col_Speed;
// };
// extern Column col[so_col];
//cac thong so player
extern int playerX;
extern int playerY; 
extern const int playerW;
extern const int playerH;
extern float playerVelocity;
extern const float gravity;
extern const float jumpForce; 
extern bool running ;
extern const int startX;
extern const int startY;
extern const int startW;
extern const int startH;

extern const int Red;
extern const int Green;
extern const int Blue;

extern const int SCROLL_SPEED;
extern int backgroundX;
extern int backgroundWidth;
extern int backgroundHeight;
// Các biến toàn cục khác
extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern SDL_Texture* texture;
extern SDL_Texture* player1;
extern SDL_Texture* player2;
extern SDL_Texture* player;
extern SDL_Event e;
extern SDL_Texture* background;
extern SDL_Texture* menu;
extern SDL_Texture* start;
extern SDL_Texture* chuyen_canh;
#endif // TOANCUC_H_