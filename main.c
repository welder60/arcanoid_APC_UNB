#include <stdio.h>
#include <conio.h>
#include <locale.h>

#include "desenho.h"


#define TITULO "#Universidade de Brasília\n#Algoritmos e Programação de Computadores 1.2024\n#Prof. Clênio Emídio\n#Welder Rodrigues de Medeiros - 241012409\n"
#define INSTRUCOES "\n< > Move a barra / ESPAÇO - Modo Automático / F1 - Modo Preto e Branco"


#define Y_BLOCOS 5

#define VELOCIDADE_BARRA 2
#define ALTURA_BARRA 35
#define TAMANHO_BARRA 7
#define DIFICULDADE 1

typedef struct{
    int x,y;
}Barra;

typedef struct{
    int x,y;
    int xAnterior,yAnterior;
    int direcaoX,direcaoY;
}Bola;

int blocos[14][60]= {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
        2,7,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,7,2,
        2,2,2,2,7,7,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,7,7,2,2,2,2,
        2,2,2,2,2,2,2,2,7,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,7,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,7,7,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,7,7,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,7,7,7,1,1,1,1,1,1,1,1,1,7,7,1,1,1,1,1,1,1,1,1,7,7,7,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    };

int alturaBlocos = 14,larguraBlocos = 60;

Barra barra;
Bola bola;
int fim,estaMovendo,automatico,atualizar;
int margemHorizontal;

int main(){
    inicializar();

    while (fim == 0)
    {
        pintarTela();
        lerTeclas();
        fisica();
        Sleep(50/DIFICULDADE);
    }

    Sleep(5000);
    return 0;
}

void inicializar(){
    idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    //tamanhoJanela(80,800);
    setlocale(LC_ALL, "");
    margemHorizontal = LARGURA/2-larguraBlocos/2;
    barra.x = LARGURA/2-TAMANHO_BARRA/2;
    barra.y = ALTURA_BARRA;

    bola.x = barra.x+(TAMANHO_BARRA/2)+1;
    bola.y = ALTURA_BARRA-1;
    bola.direcaoY = 1;

    corEFundo(COR_TEXTO, COR_FUNDO);
    printf(TITULO);
    printf(INSTRUCOES);

    pintarFundo();
    pintarBlocos();
}

void pintarTela(){

    if(estaMovendo==0 || atualizar == 1){
        pintarMoldura();
        pintarBlocos();
        atualizar = 0;
    }

    desenharBarra(barra.x,ALTURA_BARRA,TAMANHO_BARRA);

    if(bola.xAnterior!=bola.x || bola.yAnterior!=bola.y){
        pixel(COR_FUNDO,bola.xAnterior,bola.yAnterior);
    }
    pixel(COR_BOLA,bola.x,bola.y);

    corEFundo(0, 0);
}

void pintarBlocos(){
    for (int y = 0; y < alturaBlocos; y++) {
        desenharVetor(blocos[y],larguraBlocos,margemHorizontal,Y_BLOCOS+y);
    }
}

void lerTeclas(){
    if (estaPressionado(VK_F1) == 1) {
        pretoEBranco = 1 - pretoEBranco;
        atualizar = 1;
    }

    if (estaPressionado(VK_LEFT) == 1) {
        barra.x-=VELOCIDADE_BARRA;
        if(estaMovendo == 0){
            bola.direcaoX = -1;
            estaMovendo = 1;
        }
    }

    if (estaPressionado(VK_RIGHT) == 1) {
        barra.x+=VELOCIDADE_BARRA;
        if(estaMovendo == 0){
            bola.direcaoX = 1;
            estaMovendo = 1;
        }
    }

    if (estaPressionado(VK_SPACE) == 1) {
        automatico = 1 - automatico;
    }

    if(automatico == 1){
        barra.x = bola.x-TAMANHO_BARRA/2;
    }

    limitesBarra();

}

int estaPressionado(int codigoTecla){
    if (GetAsyncKeyState(codigoTecla) & 0x8000){
        return 1;
    }
}

void fisica(){
    limitesBola();
    verificaColisaoBlocos();
    contaBlocos();

    if(estaMovendo==1){
        bola.xAnterior = bola.x;
        bola.yAnterior = bola.y;

        bola.x+=bola.direcaoX;
        bola.y+=bola.direcaoY;
    }

}

void limitesBarra(){
    if(barra.x<0){
        barra.x = 0;
    }

    if(barra.x+TAMANHO_BARRA>LARGURA){
        barra.x = LARGURA-TAMANHO_BARRA;
    }
}

void limitesBola(){
    if(bola.x>=LARGURA){
        bola.direcaoX=-1;
    }

    if(bola.x<=0){
        bola.direcaoX=1;
    }

    if(bola.y+1==ALTURA_BARRA && bola.x>=barra.x-1 && bola.x<=barra.x+TAMANHO_BARRA+1){
        bola.direcaoY=-1;
    }

    if(bola.y<=0){
        bola.direcaoY=1;
    }

    if(bola.y>=ALTURA){
        gameOver();
    }
}

void verificaColisaoBlocos(){
    int xRelativo = bola.x-margemHorizontal;
    int yRelativo = bola.y-Y_BLOCOS;

    if(quebrarBlocos(xRelativo,yRelativo+bola.direcaoY)>0){
        bola.direcaoY =-bola.direcaoY;
        pintarBlocos();
    }

    if(quebrarBlocos(xRelativo+bola.direcaoX,yRelativo)>0){
        bola.direcaoX =-bola.direcaoX;
        pintarBlocos();
    }

}

int quebrarBlocos(int x, int y){
    int largurabloco = 6;
    int alturabloco = 2;
    int quebrados = 0;
    if(x>=0 && y>=0 && x<larguraBlocos && y<alturaBlocos && blocos[y][x]!=0){
        for(int i =0;i<largurabloco && ((x/largurabloco)*largurabloco)+i<larguraBlocos;i++){
            for(int j =0;j<alturabloco && ((y/alturabloco)*alturabloco)+j<alturaBlocos;j++){
                int xAtual = ((x/largurabloco)*largurabloco)+i;
                int yAtual = ((y/alturabloco)*alturabloco)+j;
                if(blocos[yAtual][xAtual]!=0){
                    blocos[yAtual][xAtual]=0;
                    quebrados++;
                }
            }
        }

    }

    return quebrados;
}

void contaBlocos(){
    int nblocos = 0;

    for(int y = 0; y < alturaBlocos; y++){
        for(int x = 0; x < larguraBlocos ; x++){
            if(blocos[y][x]!=0){
                nblocos++;
            }
        }
    }

    if(nblocos == 0){
        vitoria();
    }
}

void vitoria(){
    fim = 1;
    estaMovendo=0;
    desenhaVitoria();
}

void gameOver(){
    fim = 1;
    estaMovendo=0;
    desenhaGameOver();
}

