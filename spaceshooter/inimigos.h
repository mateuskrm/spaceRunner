#ifndef INIMIGOS_H
#define INIMIGOS_H
#include <game.h>
#include <math.h>
#include <time.h>
#include <random>
class inimigos{
public:
  inimigos(int x, int h);
  ~inimigos() = default;
  SDL_Rect origemInimigo,destinoInimigo;
  SDL_Texture* texturaInimigo;
  int aceleracao;
  void atualiza(SDL_Rect &destino);

};
#endif // INIMIGOS_H
