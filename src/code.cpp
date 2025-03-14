#include "toancuc.h"
#include "cacham.h"
#include "code.h"

void nhap_du_lieu(){
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = createRenderer(window);
    background = loadTexture("C:/Users/User/Desktop/game/src/image/backround1.png", renderer);
    SDL_QueryTexture(background, NULL, NULL, &backgroundWidth, &backgroundHeight);
    menu = loadTexture("C:/Users/User/Desktop/game/src/image/menu.png", renderer);
    start = loadTexture("C:/Users/User/Desktop/game/src/image/start.png", renderer);
    cotTop = loadTexture("C:/Users/User/Desktop/game/src/image/cot.png", renderer);
    cotBot = loadTexture("C:/Users/User/Desktop/game/src/image/cot.png", renderer);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/player1.png" , &player1);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/player2.png" , &player2);
    player = player1;
    startRect = {startX , startY, startW, startH };
    chuyen_canh = menu;
    return;
}