#include "toancuc.h"
#include "cacham.h"

int main (int argc, char*argv[])
{
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = createRenderer(window);
    background = loadTexture("C:/Users/User/Desktop/game/src/image/backround1.png", renderer);
    SDL_QueryTexture(background, NULL, NULL, &backgroundWidth, &backgroundHeight);
    menu = loadTexture("C:/Users/User/Desktop/game/src/image/menu.png", renderer);
    start = loadTexture("C:/Users/User/Desktop/game/src/image/start.png", renderer);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/player1.png" , &player1);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/player2.png" , &player2);
    player = player1;
    SDL_Rect startRect = {startX , startY, startW, startH };
    chuyen_canh = menu;
    //Điều khiển
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }else if (e.type == SDL_MOUSEBUTTONDOWN){
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                if (chuot (mouseX, mouseY, startRect)){
                    if (chuyen_canh == menu) {
                        chuyen_canh = background;
                    }
                }if (chuyen_canh == background){
                    playerVelocity = jumpForce;
                }
            }
             else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE ) {
                playerVelocity = jumpForce; // Nhảy lên
            }
        }
        if(chuyen_canh == menu ){
            hien_menu (menu,  start, startRect);
        }
        if(chuyen_canh == background){
            hanh_dong(&playerVelocity, gravity, &playerY, playerH, SCREEN_HEIGHT);
            hoat_anh(playerVelocity, &player, player1, player2);
            SDL_RenderClear(renderer);
            renderScrollingBackground(renderer, background, backgroundWidth, &backgroundX);
            player_in(renderer, player, playerX, playerY, playerW, playerH);
            SDL_Delay(10);
        }
    }
    void exit();
    return 0;
}