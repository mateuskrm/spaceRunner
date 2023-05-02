#include <game.h>

Jogo::Jogo(){
    fundo = criaTextura("imagens/fundo.bmp", renderizador);
    destinoTexto.x = destinoTexto.y = 400;
    destinoTexto.h = destinoTexto.w = 100;
}

void Jogo::inicializacao(string titulo, int x, int y, int largura, int altura ){
    Uint32 flag = 0;
   if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
       janela = SDL_CreateWindow(titulo.c_str(), x, y, largura, altura, flag);
       renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
   }else{
       cout<<SDL_GetError();
   }
}

void renderiza(Jogo game,SDL_Texture* texturaJogador,SDL_Texture* texturaInimigo,int vida,SDL_Texture* uvida,
               SDL_Texture* dvida,SDL_Texture* tvida,SDL_Rect origemVida,SDL_Rect destinoVida,SDL_Rect origemJogador,
               SDL_Rect destinoJogador,SDL_Rect origemInimigo,SDL_Rect destinoInimigo){
    SDL_RenderClear(game.renderizador);
    SDL_RenderCopy(game.renderizador, game.fundo, NULL, NULL);
    if(vida == 3){
        SDL_RenderCopy(game.renderizador, tvida, &origemVida, &destinoVida);
    }else if(vida == 2){
        SDL_RenderCopy(game.renderizador, dvida, &origemVida, &destinoVida);
    }else{
        SDL_RenderCopy(game.renderizador, uvida, &origemVida, &destinoVida);
    }
    SDL_RenderCopy(game.renderizador, texturaInimigo, &origemInimigo, &destinoInimigo);
    SDL_RenderCopy(game.renderizador, texturaJogador, &origemJogador, &destinoJogador);

    SDL_RenderPresent(game.renderizador);
}

SDL_Texture* criaTextura(string caminho, SDL_Renderer* renderizador){
    SDL_Surface* temporario = SDL_LoadBMP(caminho.c_str());
    if(!temporario){
        cout<<"não foi possivel localizar a imagem";
    }else if(temporario){
        //cout<<"imagem carregada com sucesso";
    }
    return  SDL_CreateTextureFromSurface(renderizador, temporario);
    SDL_FreeSurface(temporario);
}

void evento(bool &movimento, int &direcao){
    SDL_Event eventos;
    while(SDL_PollEvent(&eventos)){
        switch (eventos.type) {
            case SDL_KEYDOWN:
                switch (eventos.key.keysym.sym) {
                    case SDLK_RIGHT:
                        movimento = true;
                        direcao = 1;
                    break;
                    case SDLK_LEFT:
                        movimento = true;
                        direcao = 2;
                    break;

                    case SDLK_ESCAPE:
                        SDL_Quit();
                    break;
            }

            break;
            case SDL_KEYUP:
                   movimento = false;
                    direcao = 0;
            break;

            case SDL_QUIT:
                SDL_Quit();
            break;

        }
    }

}


void Jogo::limpa(SDL_Texture* jogador){
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_DestroyTexture(jogador);
    SDL_DestroyTexture(fundo);
}



