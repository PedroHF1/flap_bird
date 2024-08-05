/*Versão beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: não permitido o uso de funções e variáveis compostas como structs, vetores e matrizes
    - Corrigir os rastros (pássaro e obstáculos)
    - Implementar colisão
    - Implementar pontuação (mais um ponto para cada obstáculo superado)
    - Fazer 2 obstáculos simultâneos (obstaculo1 e obstaculo2)
    - Deixar a pontuação visível durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

    srand(time(NULL));
    int bird_x=10, bird_y=10;
    int obstaculo1_x=50, obstaculo1_y;
    int obstaculo2_x=75, obstaculo2_y;
    int obstaculo3_x=100, obstaculo3_y;
    int obstaculo4_x=125, obstaculo4_y;
    char tecla;
    int score;
    int gapY = rand()% 12 + 5;
    int gapY2 = rand()% 12 + 5;
    int gapY3 = rand()% 12 + 5;
    int gapY4 = rand()% 12 + 5;
    bool gameover=false;

        cout << "-----------------------" << endl;
        cout << "-        Menu!        -" << endl;
        cout << "-                     -" << endl;
        cout << "-    Press W to fly   -" << endl;
        cout << "-                     -" << endl;
        cout << "-----------------------" << endl << endl;


        system("pause");

    while (!gameover) { //esse laço faz o jogo rodar para sempre

        if(obstaculo1_x==1) {
            obstaculo1_x=100;
            gapY = rand()% 12 + 5;
        }
        if(obstaculo2_x==1) {
            obstaculo2_x=100;
            gapY2 = rand()% 12 + 5;
        }
        if(obstaculo3_x==1) {
            obstaculo3_x=100;
            gapY3 = rand()% 12 + 5;
        }
        if(obstaculo4_x==1) {
            obstaculo4_x=100;
            gapY3 = rand()% 12 + 5;
        }

        system ("cls");

        ///DESENHO DO CENÁRIO
        cout<<"----------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl << "---------------";
        cout << endl << "-    Score    - ";
        cout << endl << "-      " << score << "      -";
        cout << endl << "---------------";
        ///POSICIONA O PÁSSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);


        ///POSICIONA O OBSTÁCULO

        obstaculo1_y=1;
        while(obstaculo1_y<21){
            coord.X = obstaculo1_x;    coord.Y = obstaculo1_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo1_y < gapY || obstaculo1_y > gapY + 4) {
            cout << char(219);
            } else {
                cout << " ";
            }
            obstaculo1_y++;
        }

          obstaculo2_y=1;
        while(obstaculo2_y<21){
            coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

           if(obstaculo2_y < gapY2 || obstaculo2_y > gapY2 + 4) {
            cout << char(219);
            } else {
                cout << " ";
            }
            obstaculo2_y++;
        }

        obstaculo3_y=1;
        while(obstaculo3_y<21){
            coord.X = obstaculo3_x;    coord.Y = obstaculo3_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

           if(obstaculo3_y < gapY3 || obstaculo3_y > gapY3 + 4) {
            cout << char(219);
            } else {
                cout << " ";
            }
            obstaculo3_y++;
        }

        obstaculo4_y=1;
        while(obstaculo4_y<21){
            coord.X = obstaculo4_x;    coord.Y = obstaculo4_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

           if(obstaculo4_y < gapY4 || obstaculo4_y > gapY4 + 4) {
            cout << char(219);
            } else {
                cout << " ";
            }
            obstaculo4_y++;
        }

        ///VERIFICA COLISÃO
        if (bird_x==obstaculo1_x || bird_x==obstaculo2_x || bird_x==obstaculo3_x || bird_x==obstaculo4_x) {
            score++;
        }

        if (bird_y>=21 || bird_y<=1 || (bird_x >= obstaculo1_x && bird_x <= obstaculo1_x + 1 && (bird_y < gapY || bird_y > gapY+4))) {
            gameover = true;
        }
        if (bird_x >= obstaculo2_x && bird_x <= obstaculo2_x + 1 && (bird_y < gapY2 || bird_y > gapY2+4)) {
            gameover = true;
        }
        if (bird_x >= obstaculo3_x && bird_x <= obstaculo3_x + 1 && (bird_y < gapY3 || bird_y > gapY3+4)) {
            gameover = true;
        }
        if (bird_x >= obstaculo4_x && bird_x <= obstaculo4_x + 1 && (bird_y < gapY4 || bird_y > gapY4+4)) {
            gameover = true;
        }

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador

        }

        if ( tecla=='w' ){
            bird_y--;
            tecla='0';

        } else  {
            bird_y++;

        }

        ///PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR

        ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA
        obstaculo1_x--;
        obstaculo2_x--;
        obstaculo3_x--;
        obstaculo4_x--;

        ///TEMPO DE ESPERA
        if(score<=4){
            Sleep(250);
        }
        else if (score>4 && score<10){
            Sleep(150);
        }
        else if (score>9 && score<15){
            Sleep(100);
        }
        else if (score>14 && score<20){
            Sleep(50);
        }
        else if (score>19 && score<25){
            Sleep(25);
        }

    }

    system ("cls");
    cout << "---------------------" << endl;
    cout << "-    Game Over!     -" << endl;
    cout << "-                   -" << endl;
    cout << "-    Score: " << score << "       -" << endl;
    cout << "---------------------" << endl;


    return 0;
}
