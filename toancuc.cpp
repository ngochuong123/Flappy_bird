#include "toancuc.h"

//cac thong so
const int SCREEN_WIDTH = 500 ;
const int SCREEN_HEIGHT = 700 ;
const char* WINDOW_TITLE = "Flappy_bird";
//cột
const int so_col = 5;
struct Column {
    int Col_X;
    int Col_gapY;
    int Col_W;
    int Col_gapHeight;
    int Col_Speed;
};
Column col[so_col] ;
//player
int playerX = 70;
int playerY = 250;
const int playerW = 50;
const int playerH = 50;
float playerVelocity = 0;
const float gravity = 0.3f;
const float jumpForce = -8.0f;
bool running = true;
const int startX = 150;
const int startY = 500;
const int startW = 200;
const int startH = 100;

const int Red = 230;
const int Green = 230;
const int Blue = 230;
const int SCROLL_SPEED = 2;
int backgroundX = 0;
int backgroundWidth = 0;
int backgroundHeight = 0;
// Định nghĩa các biến toàn cục
SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
SDL_Texture* texture = NULL;
SDL_Texture* player1 = NULL;
SDL_Texture* player2 = NULL;
SDL_Texture* player = NULL ;
SDL_Texture* background = NULL;
SDL_Texture* menu = NULL;
SDL_Texture* start = NULL;
SDL_Texture* chuyen_canh = NULL;
SDL_Event e;