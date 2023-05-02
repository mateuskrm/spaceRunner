#ifndef PLAYER_H
#define PLAYER_H
#include <game.h>
class Nave{
  public:
    Nave();
    bool movimento = false;
    int direcao = 0;
    int vida = 3;
    int score = 0;
    int velocidade = 10;
    SDL_Texture* jogador;
    SDL_Texture* threeLives;
    SDL_Texture* twoLives;
    SDL_Texture* oneLive;
    SDL_Rect origemVidaUI, destinoVidaUI,origemJogador,destinoJogador;

    void carregaTextura(SDL_Renderer* renderizador);
    void renderizaNave(SDL_Renderer* renderizador);
    void movimentacaoNave();
    void derrota(bool &condicao);



};
#endif // PLAYER_H
