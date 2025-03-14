#include "toancuc.h"

//cac thong so
const int SCREEN_WIDTH = 500 ;
const int SCREEN_HEIGHT = 700 ;
const char* WINDOW_TITLE = "Flappy_bird";
const int delay = 16;
const int Min = 80;
const int Max = 300;
//cột
    const int Col_W = 70;
    int Col_X = SCREEN_WIDTH - Col_W;
    const int kc_col = SCREEN_WIDTH/2 + Col_W; 
    int Col_X1 = Col_X + kc_col;
    int Col_Y = 0;
    int Col_H ;
    int Col_H1;
    const int gap = 200;
    int col_H_duoi = SCREEN_HEIGHT - 110 - gap;
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
const int SCROLL_SPEED = 4;
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
SDL_Texture* cotTop = NULL;
SDL_Texture* cotBot = NULL; 
SDL_Event e;

SDL_Rect startRect = {0, 0 ,0 ,0};