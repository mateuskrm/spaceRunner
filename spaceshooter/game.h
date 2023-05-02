#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <iostream>
#include <nave.h>
#include <inimigos.h>



using namespace std;

class Jogo{
public:
    Jogo();
    bool jogoFinalizado = false;
    SDL_Window *janela;
    SDL_Renderer *renderizador;
    SDL_Texture* fundo;
    void inicializacao(string titulo, int x, int y, int largura, int altura );
    void limpa(SDL_Texture* jogador);
    SDL_Rect destinoTexto;

};

void evento(bool &movimento, int &direcao);
void renderiza(Jogo game,SDL_Texture* texturaJogador,SDL_Texture* texturaInimigo,int vida,SDL_Texture* uvida,
               SDL_Texture* dvida,SDL_Texture* tvida,SDL_Rect origemVida,SDL_Rect destinoVida,SDL_Rect origemJogador,
               SDL_Rect destinoJogador,SDL_Rect origemInimigo,SDL_Rect destinoInimigo);
SDL_Texture* criaTextura(string caminho, SDL_Renderer* renderizador);
//void evento(Nave &navePrincipal);



#endif // GAME_H
