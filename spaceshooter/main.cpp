#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <game.h>
#include <iostream>
#include <nave.h>
#include <inimigos.h>
#include <SDL_thread.h>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;

Jogo game;
Nave nave;
inimigos* i;

int criaInimigos(void *ptr){
    srand(time(NULL));
    int cnt;
    int contNaves = 0;
    while(nave.vida >= 0){
        int x = rand()%800 + 1;
        int h = rand()%5 + 1;
        i = new inimigos(x, h);

        while (i->destinoInimigo.y < 600){
            i->atualiza(i->destinoInimigo);
            if(SDL_HasIntersection(&i->destinoInimigo, &nave.destinoJogador)){
                nave.vida --;
                contNaves = 0;
                break;
            }
            SDL_Delay(1000/60);
        };
        contNaves ++;
        nave.score += contNaves * i->aceleracao + i->destinoInimigo.h;
        delete[]  i;
    }
    return cnt;
}



void gameloop(){
    game.inicializacao("spaceshooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
    nave.carregaTextura(game.renderizador);
    game.fundo = criaTextura("imagens/fundo.bmp", game.renderizador);

    while(!game.jogoFinalizado){
        i->texturaInimigo = criaTextura("imagens/inimigo.bmp", game.renderizador);
        renderiza(game,nave.jogador,i->texturaInimigo,nave.vida,nave.oneLive,nave.twoLives,nave.threeLives,
                    nave.origemVidaUI,nave.destinoVidaUI,nave.origemJogador,nave.destinoJogador,i->origemInimigo,
                        i->destinoInimigo);
        evento(nave.movimento, nave.direcao);
        nave.movimentacaoNave();
        nave.derrota(game.jogoFinalizado);
        SDL_Delay(1000/60);
    }
    game.limpa(nave.jogador);
}

int main()
{
    cout << "\nBem Vindo ao Space Runner!\n Aperte qualquer tecla para continuar\n lembre-se de clicar na janela";
    getchar();
    SDL_Delay(1000);

    SDL_Thread* inimigo;
    inimigo = SDL_CreateThread(criaInimigos, "criaInimigos", (void *)NULL);
    int retornaThread;
    gameloop();
    SDL_WaitThread(inimigo, &retornaThread);


}
