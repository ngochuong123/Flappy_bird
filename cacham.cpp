#include"toancuc.h"
#include"cacham.h"

void logErrorAndExit(const char* msg, const char* error) {
    printf("%s %s\n", msg, error);
    exit(1);
}

SDL_Window* initSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const char* WINDOW_TITLE) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        logErrorAndExit("SDL could not initialize! SDL_Error:", SDL_GetError());
    }
    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow(
        WINDOW_TITLE,                      
        SDL_WINDOWPOS_UNDEFINED,    
        SDL_WINDOWPOS_UNDEFINED,    
        SCREEN_WIDTH,                     
        SCREEN_HEIGHT,                     
        SDL_WINDOW_SHOWN            
    );
    if (window == NULL) {
        logErrorAndExit("Window could not be created! SDL_Error:", SDL_GetError());
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        logErrorAndExit("SDL_image could not initialize! SDL_image Error:", IMG_GetError());
    }
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    return renderer;
}
//xu ly hinh anh
SDL_Texture *loadTexture(const char *filename,SDL_Renderer*renderer)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    SDL_Texture*texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
    }
    return texture;    
}
// backround trôi
void renderScrollingBackground(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int backgroundWidth, int* backgroundX) {
    *backgroundX -= SCROLL_SPEED;
    if (*backgroundX < -backgroundWidth) {
        *backgroundX = 0; 
    }
    SDL_Rect destRect1 = {*backgroundX, 0, backgroundWidth, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &destRect1);
    SDL_Rect destRect2 = {*backgroundX + backgroundWidth, 0, backgroundWidth, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &destRect2);
}

void hinh_anh_player(const char* filename , SDL_Texture**player1){
    SDL_Surface* surface = IMG_Load(filename);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, Red, Green, Blue)); 
    *player1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}
void player_in(SDL_Renderer* renderer, SDL_Texture* player, int playerX, int playerY, const int playerW, const int playerH){
    SDL_Rect playerRect = {playerX, playerY, playerW, playerH};
        SDL_RenderCopy(renderer, player, NULL, &playerRect);
}
bool chuot (int mouseX, int mouseY, SDL_Rect Start){
    return (mouseX >= Start.x && mouseX <= Start.x + Start.w &&
            mouseY >= Start.y && mouseY <= Start.y + Start.h);
}

void cot_troi(SDL_Renderer* renderer, SDL_Texture* cotTop, SDL_Texture* cotBot, int* Col_X, int* Col_H, int* Col_H1, int* Col_X1, int col_H_duoi, int gap) {
    *Col_X -= SCROLL_SPEED;
    *Col_X1 -= SCROLL_SPEED;
    if (*Col_X <= -Col_W && *Col_X1 <= SCREEN_WIDTH - kc_col - Col_W ) {
        *Col_X = SCREEN_WIDTH - Col_W; 
        *Col_H = Min + rand() % Max;    
        while (col_H_duoi - *Col_H <= 0) {
            *Col_H = Min + rand() % Max;
        }
    }
    if (*Col_X1 <= -Col_W && *Col_X <= SCREEN_WIDTH - kc_col - Col_W) {
        *Col_X1 = SCREEN_WIDTH - Col_W;
        *Col_H1 = Min + rand() % Max;
        while (col_H_duoi - *Col_H1 <= 0) {
            *Col_H1 = Min + rand() % Max;
        }
    }
    SDL_Rect cotRectTop = { *Col_X, 0, Col_W, *Col_H };
    SDL_RenderCopy(renderer, cotTop, NULL, &cotRectTop);
    SDL_Rect cotRectBot = { *Col_X, gap + *Col_H, Col_W, col_H_duoi - *Col_H };
    SDL_RenderCopy(renderer, cotBot, NULL, &cotRectBot);

    SDL_Rect cotRectTop1 = { *Col_X1, 0, Col_W, *Col_H1 };
    SDL_RenderCopy(renderer, cotTop, NULL, &cotRectTop1);
    SDL_Rect cotRectBot1 = { *Col_X1, gap + *Col_H1, Col_W, col_H_duoi - *Col_H1 };
    SDL_RenderCopy(renderer, cotBot, NULL, &cotRectBot1);
}


void hoat_anh(int vantoc, SDL_Texture**p, SDL_Texture*p1, SDL_Texture*p2){
    if (vantoc < 0) {
        *p = p2; 
    } else if (vantoc > 0) {
        *p = p1; 
    }
}
void hanh_dong(float* playerVelocity, float gravity, int* playerY, const int playerH, const int SCREEN_HEIGHT){
    *playerVelocity += gravity; 
    *playerY += *playerVelocity; 
    if (*playerY < 0) {
        *playerY = 0;
    }
    if (*playerY + playerH > SCREEN_HEIGHT) {
        *playerY = SCREEN_HEIGHT - playerH;
    }
}
void hien_menu (SDL_Texture* menu, SDL_Texture* start, SDL_Rect startRect){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer ,menu ,NULL ,NULL);
    SDL_RenderCopy(renderer ,start ,NULL ,&startRect);
    SDL_RenderPresent(renderer);
}

void exit(){
    SDL_DestroyTexture(menu);
    SDL_DestroyTexture(start);
    SDL_DestroyTexture(player1);
    SDL_DestroyTexture(player2);
    SDL_DestroyTexture(player);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(cotTop);
    SDL_DestroyTexture(cotBot);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


    