#ifndef CACHAM_H_
#define CACHAM_H_

#include"toancuc.h"

void logErrorAndExit(const char* msg, const char* error);
SDL_Window* initSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const char* WINDOW_TITLE);
//hinh anh + backround
SDL_Texture *loadTexture(const char *filename,SDL_Renderer* renderer);
void renderTexture(SDL_Texture *texture, int x, int y, int w, int h, SDL_Renderer* renderer);

SDL_Renderer* createRenderer(SDL_Window* window);

void hinh_anh_player(const char* filename , SDL_Texture**player1);
void player_in(SDL_Renderer* renderer, SDL_Texture* player, int playerX, int playerY, const int playerW, const int playerH); 
void renderScrollingBackground(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int backgroundWidth, int* backgroundX);
bool chuot (int mouseX, int mouseY, SDL_Rect Start);

void hoat_anh(int vantoc, SDL_Texture**p, SDL_Texture*p1, SDL_Texture*p2);
void hanh_dong(float* playerVelocity, float gravity, int* playerY, const int playerH, const int SCREEN_HEIGHT);
void hien_menu (SDL_Texture* menu, SDL_Texture* start,SDL_Rect startRect);

void exit();
#endif
