#include <nave.h>

Nave::Nave(){
    origemJogador.x = origemJogador.y = 0;
    origemJogador.h = origemJogador.w = 500;
    destinoJogador.x = 400;
    destinoJogador.y = 400;
    destinoJogador.h = 100;
    destinoJogador.w = 100;

    origemVidaUI.x = origemVidaUI.y = 0;
    origemVidaUI.w = 256;
    origemVidaUI.h = 128;
    destinoVidaUI.x = destinoVidaUI.y = 0;
    destinoVidaUI.h = origemVidaUI.h / 2;
    destinoVidaUI.w = origemVidaUI.w / 2;
}
void Nave::carregaTextura(SDL_Renderer* renderizador){
    jogador = criaTextura("imagens/jogador.bmp", renderizador);
    oneLive = criaTextura("imagens/one.bmp", renderizador);
    twoLives = criaTextura("imagens/two.bmp", renderizador);
    threeLives = criaTextura("imagens/three.bmp", renderizador);
}

void Nave::movimentacaoNave(){
    if(movimento){
        switch (direcao) {
            case 1:
                if(destinoJogador.x <= 700){
                    destinoJogador.x += velocidade;
                }
            break;
            case 2:
                if(destinoJogador.x >= 0){
                    destinoJogador.x -= velocidade;
                }
            break;
        }

    }
}

void Nave::derrota(bool &condicao){
    if(vida == 0){
      condicao = true;
      SDL_Delay(1000);
      cout << "\n\n\n Game over!\n Score: " << score <<"\n";
    }

}
