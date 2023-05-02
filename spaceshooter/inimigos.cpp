#include <inimigos.h>


inimigos::inimigos(int x, int h){
    origemInimigo.x = origemInimigo.y = 0;
    origemInimigo.h = origemInimigo.w = 300;
    destinoInimigo.x = x;
    destinoInimigo.y = 0;
    destinoInimigo.h = destinoInimigo.w = 300 / h;
    if(destinoInimigo.h <= 300 && destinoInimigo.h >= 150){
        aceleracao = 5;
    }else if (destinoInimigo.h <= 149 && destinoInimigo.h >= 100){
        aceleracao = 10;
    }else if (destinoInimigo.h <= 99 && destinoInimigo.h >= 75){
        aceleracao = 15;
    }else{
        aceleracao = 20;
    }
}

void inimigos::atualiza(SDL_Rect &destino){
    destino.y += aceleracao;
}

