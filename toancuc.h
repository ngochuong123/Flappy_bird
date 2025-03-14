#ifndef TOANCUC_H_
#define TOANCUC_H_
// Khai báo thư viện
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;
// Các thông số cửa sổổ
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
extern const char* WINDOW_TITLE;
extern const int delay;
extern const int Min;
extern const int Max;
// các thông số của cột
extern const int Col_W;
extern int Col_X;
extern const int kc_col;
extern int Col_X1;
extern int Col_Y;
extern int Col_H;
extern int Col_H1;
extern const int gap;
extern int col_H_duoi;
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
//xóa nền = RGB
extern const int Red;
extern const int Green;
extern const int Blue;
//các thông số backgroundbackground
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
extern SDL_Texture* cotTop;
extern SDL_Texture* cotBot;
// Các biến hình chữ nhật 
extern SDL_Rect startRect;
#endif // TOANCUC_H_