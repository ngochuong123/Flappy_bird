#include "toancuc.h"
#include "cacham.h"
#include "code.h"

int main (int argc, char*argv[])
{
    nhap_du_lieu();
    srand(std::time(0));
    Col_H = Min + rand() % Max/2;
    Col_H1 = Min + rand() % Max/2;
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
            cot_troi( renderer, cotTop, cotBot, &Col_X, &Col_H, &Col_H1, &Col_X1, col_H_duoi, gap);
            SDL_RenderPresent(renderer);
            SDL_Delay(delay);
        }
    }
    void exit();
    return 0;
}