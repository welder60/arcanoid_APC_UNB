#ifndef DESENHO_H_INCLUDED
#define DESENHO_H_INCLUDED

#include <windows.h>
#include <string.h>

#define TAMANHO_CABECALHO 6

#define LARGURA 74
#define ALTURA 40

#define COR_TEXTO 10
#define COR_BORDA 7
#define COR_FUNDO 0
#define COR_BARRA 13
#define COR_BOLA 10

int *idTerminal;
int pretoEBranco;

void pintarMoldura(){
    for (int y = -1; y <= ALTURA+1; y++) {
        for (int x = -1; x <= LARGURA+1; x++) {
            if(x==-1 || y==0-1 || x==LARGURA+1 || y==ALTURA+1){
                pixel(COR_BORDA,x,y);
            }
        }
    }
}

void pintarFundo(){
    for (int y = 0; y <= ALTURA+1; y++) {
        for (int x = 0; x <= LARGURA+1; x++) {
            pixel(COR_FUNDO,x,y);
        }
    }
}

void desenharBarra(int px,int py,int tamanho){
    for (int x = 0; x <= LARGURA; x++) {
            if(x>=px && x<=px+tamanho){
                pixel(COR_BARRA,x,py);
            } else {
                pixel(COR_FUNDO,x,py);
            }
    }
}

void desenhaGameOver(){
    int mensagem[19][35] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,7,7,7,7,7,0,0,0,0,0,7,0,0,0,0,7,0,0,0,0,0,7,0,7,7,7,7,7,7,7,0,0,
        0,0,7,0,0,0,0,0,7,0,0,0,7,0,7,0,0,0,7,7,0,0,0,7,7,0,7,0,0,0,0,0,0,0,0,
        0,0,7,0,0,0,0,0,0,0,0,7,0,0,0,7,0,0,7,0,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,
        0,0,7,0,0,7,7,7,7,0,7,0,0,0,0,0,7,0,7,0,0,7,0,0,7,0,7,7,7,7,7,0,0,0,0,
        0,0,7,0,0,0,0,0,7,0,7,7,7,7,7,7,7,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,0,0,0,
        0,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,0,0,0,
        0,0,0,7,7,7,7,7,0,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,7,0,7,7,7,7,7,7,7,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,7,7,7,7,7,7,7,0,7,0,0,0,0,0,7,0,7,7,7,7,7,7,7,0,7,7,7,7,7,7,0,0,0,
        0,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,0,0,7,0,0,0,0,0,7,0,0,
        0,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,0,0,7,0,0,0,0,0,7,0,0,
        0,0,7,0,0,0,0,0,7,0,7,0,0,0,0,0,7,0,7,7,7,7,7,0,0,0,7,7,7,7,7,7,0,0,0,
        0,0,7,0,0,0,0,0,7,0,0,7,0,0,0,7,0,0,7,0,0,0,0,0,0,0,7,0,0,0,7,0,0,0,0,
        0,0,7,0,0,0,0,0,7,0,0,0,7,0,7,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,0,7,0,0,0,
        0,0,7,7,7,7,7,7,7,0,0,0,0,7,0,0,0,0,7,7,7,7,7,7,7,0,7,0,0,0,0,0,7,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    int largura = 35;
    int altura = 19;

    for (int y = 0; y < altura; y++) {
        desenharVetor(mensagem[y],largura,LARGURA/2-largura/2,ALTURA/2-altura/2+y);
    }

}

void desenhaVitoria(){
    int mensagem[16][59] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,7,7,0,0,7,7,7,7,7,7,0,0,0,7,7,7,7,7,7,0,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,7,7,0,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,0,0,0,0,7,7,7,7,7,7,0,0,0,7,7,7,7,7,7,0,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,7,7,0,0,0,0,7,7,0,7,7,7,7,7,7,7,0,7,7,7,0,0,0,0,7,7,0,0,7,7,7,7,7,7,0,7,7,7,7,7,7,7,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,
        0,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,0,0,0,7,7,7,7,0,0,0,7,7,0,7,7,0,0,0,0,0,0,7,7,0,0,0,0,0,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,
        0,0,7,7,0,0,0,0,7,7,0,7,7,7,7,7,0,0,0,7,7,0,7,7,0,0,7,7,0,7,7,0,0,0,0,0,0,7,7,7,7,7,0,0,0,7,7,0,0,0,0,7,7,0,7,7,0,0,0,
        0,0,0,7,7,0,0,7,7,0,0,7,7,0,0,0,0,0,0,7,7,0,0,7,7,0,7,7,0,7,7,0,0,0,0,0,0,7,7,0,0,0,0,0,0,7,7,0,0,0,0,7,7,0,0,0,0,0,0,
        0,0,0,0,7,7,7,7,0,0,0,7,7,7,7,7,7,7,0,7,7,0,0,0,7,7,7,7,0,0,7,7,7,7,7,7,0,7,7,7,7,7,7,7,0,0,7,7,7,7,7,7,0,0,7,7,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    int largura = 59;
    int altura = 16;

    for (int y = 0; y < altura; y++) {
        desenharVetor(mensagem[y],largura,LARGURA/2-largura/2,ALTURA/2-altura/2+y);
    }

}

void desenharVetor(int vetor[],int largura,int px,int py){
    for (int x = 0; x < largura; x++) {
            pixel(vetor[x],px+x,py);
    }
}

void corEFundo(int corLetra,int corFundo){
    int wColor = ((corFundo & 0x0F) << 4) + (corLetra & 0x0F);
    SetConsoleTextAttribute(idTerminal, wColor);
}

void pixel(char cor, int x, int y) {
    if(pretoEBranco == 1){
        if(cor==0){
            caracterNaPosicao(' ',7,0,x,y);
        } else {
            caracterNaPosicao('X',7,0,x,y);
        }
    } else {
        caracterNaPosicao(' ',0,cor,x,y);
    }


}

void caracterNaPosicao(char caracter,int corLetra,int corFundo, int x, int y) {
    COORD coord;
    coord.X = x+1;
    coord.Y = y+TAMANHO_CABECALHO+1;

    unsigned long charsWritten;
    WriteConsoleOutputCharacter(idTerminal, &caracter, 1, coord, &charsWritten);

    unsigned long  attributes = ((corFundo%14 & 0x0F) << 4) + (corLetra%14 & 0x0F);
    WriteConsoleOutputAttribute(idTerminal, &attributes, 1, coord, &charsWritten);

}

void tamanhoJanela(int largura, int altura) {
   SMALL_RECT windowSize = {0, 0, 100, 200};
    SetConsoleWindowInfo(idTerminal, TRUE, &windowSize);

    // Definir o tamanho do buffer
    COORD bufferSize = {largura, altura};
    SetConsoleScreenBufferSize(idTerminal, bufferSize);

    // Definir o tamanho da janela para o tamanho desejado
    //windowSize = (SMALL_RECT){0, 0, largura - 1, altura - 1};
    //SetConsoleWindowInfo(idTerminal, TRUE, &windowSize);
}


#endif // DESENHO_H_INCLUDED
